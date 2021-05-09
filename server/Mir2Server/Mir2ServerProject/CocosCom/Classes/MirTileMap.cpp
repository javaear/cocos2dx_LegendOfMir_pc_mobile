#include "MirTileMap.h"

MirTileMap::MirTileMap(void)
{
	m_pMapTiles = 0;
	m_initComplete = false;
	m_curShowTileCount = 0;
	m_showTileCountPerTime = 1000;
}


MirTileMap::~MirTileMap(void)
{
}

bool MirTileMap::init()
{
	m_pMapTiles = 0;
	return true;
}

bool MirTileMap::is1AtTopDigit(unsigned char target) 
{
	//return (target & 0x1000_0000) == 0x1000_0000;
	return (target & 0x80) == 0x80;
}

bool MirTileMap::is1AtTopDigitForShort(short target) 
{
	//return (target & 0x1000_0000) == 0x1000_0000;
	return (target & 0x8000) == 0x8000;
}

bool MirTileMap::initWithMapFile(char* filename, const char* loadingFinished)
{
	m_filename = filename;
	m_loadingFinished = loadingFinished;
	/*
	if (!readMapData())
		return false;
	*/
	//重新初始化
	if (m_pMapTiles != 0)
		release();

	thread t(&MirTileMap::readMapData, this);
	t.detach();

	return true;
}

bool MirTileMap::readMapData()
{
	ssize_t len;

	unsigned char* data = CCFileUtils::getInstance()->getFileData(m_filename, "rb", &len);

	//地图大小
	setWidth(readShort(data, 0, true));
	setHeight(readShort(data, 2, true));
	
	//初始化地图tile
	m_pMapTiles = new MapTileInfo[m_width*m_height];

	int resIdx = 52;
	int resOffset = 12;
	for (int w=0; w < m_width; ++w)
	{
		for(int h=0; h < m_height; ++h)
		{
			int tileIdx = w + m_width * (m_height - h - 1);
			MapTileInfo* tile = &m_pMapTiles[tileIdx]; 

			readMapTileData(tile, data, resIdx);
			tile->setRow(w);
			tile->setCol(m_height - h - 1);

			resIdx = resIdx + resOffset;
		}
	}

	//schedule(schedule_selector(MirTileMap::updateTile), 0.2f);

	//发送加载完成事件
	m_initComplete = true;

	return true;
}

int MirTileMap::getInitComplete()
{
	if (m_initComplete)
		return 1;
	else
		return 0;
}

void MirTileMap::updateTile(float delta)
{
	int begin = m_curShowTileCount;
	for (int i=begin; i < m_showTilePointVec.size() && i <= begin+m_showTileCountPerTime; ++i)
	{
		int tileIndex = m_showTilePointVec[i];
		MapTileInfo* tile = &m_pMapTiles[tileIndex];

		if (tile->getIsInit() == false)
		{
			initMapTileSprite(tile);
			tile->setVisible(true);
		}

		m_curShowTileCount++;
	}
}

MapTileInfo* MirTileMap::readMapTileData(MapTileInfo* res, unsigned char* data, int resOffset)
{
	short bng = readShort(data, resOffset, true);
	short mid = readShort(data, resOffset+2, true);
	short obj = readShort(data, resOffset+4, true);

	if ((bng & 0x7fff) > 0)
	{
		res->setBngIndex((short)(bng & 0x7fff) - 1);
		res->setHasBng(true);
	}

	if ((mid & 0x7fff) > 0)
	{
		res->setMidIndex((short)(mid & 0x7fff) - 1);
		res->setHasMid(true);
	}

	if ((obj & 0x7fff) > 0)
	{
		res->setObjIndex((short)(obj & 0x7fff) - 1);
		res->setHasObj(true);
	}

	res->setCanWalk(!is1AtTopDigitForShort(bng) && !is1AtTopDigitForShort(obj));
	res->setCanFly(!is1AtTopDigitForShort(obj));

	unsigned char doorIdx     = data[resOffset+6];
	unsigned char doorOffset  = data[resOffset+7];
	if (is1AtTopDigit(doorIdx))
	{
		res->setDoorIndex((char)(doorIdx & 0x7F));
		res->setHasDoor(true);
	}
	res->setDoorOffset(doorOffset);
	if(is1AtTopDigit(doorOffset)) res->setDoorOpen(true);
	
	unsigned char aniFrame    = data[resOffset+8];
	if(is1AtTopDigit(aniFrame)) 
	{
		res->setAniFrame((char) (aniFrame & 0x7F));
		res->setHasAni(true);
	}

	res->setAniTick(data[resOffset+9]);
	res->setObjFileIndex(data[resOffset+10]);
	res->setLight(data[resOffset+11]);

	return res;
}

void MirTileMap::showPart(int x, int y, int width, int height)
{
	if (m_initComplete == false)
		return;

	int startRow = x/m_tileWidth - 1;
	int startCol = y/m_tileHeight - 1;
	int endRow   = (width+x)/m_tileWidth + 1;
	int endCol   = (height+y)/m_tileHeight + 1;

	if (endRow > m_width)
		endRow = m_width-1;

	if (endCol > m_height)
		endCol = m_height-1;

	if (startRow < 0 )
		startRow = 0;

	if (startCol < 0)
		startCol = 0;

	if (startRow > endRow || startCol > endCol)
		return;

	showPartEx(startRow, startCol, endRow, endCol);
}

void MirTileMap::showPartEx(int row, int col, int endRow, int endCol)
{
	int index = 0;

	for (int w=row; w <= endRow; ++w)
	{
		for(int h=col; h <= endCol; ++h)
		{
			int tileIdx = w + m_width * h;

			MapTileInfo* tile = &m_pMapTiles[tileIdx];

			if (tile->getIsInit() == false)
			{
				initMapTileSprite(tile);
				tile->setVisible(true);
			}
		}
	}

	Rect size(row,col, endRow, endCol);
}

void MirTileMap::hindPart(int row, int col, int rowCount, int colCount)
{

}

bool MirTileMap::initMapTileSprite(MapTileInfo* mapTile)
{
	if (mapTile == 0)
		return false;

	mapTile->initSprite();
	mapTile->setAnchorPoint(0, 0);
	mapTile->setPosition(mapTile->getRow()*m_tileWidth, mapTile->getCol()*m_tileHeight);
	mapTile->addTileSpriteTo(this, m_bngOrder, m_midOrder, m_objOrder);


	return true;
}

short MirTileMap::getImgIdx(short param)
{
	if ((param & 0x7fff) > 0)
		return (short)(param & 0x7fff) - 1;
	else
		return -1;
}

short MirTileMap::readShort(unsigned char* chars, int index, bool reverse) 
{
	if(reverse)
		return (short) ((chars[index + 1] << 8) | (chars[index] & 0xff));
	else
		return (short) ((chars[index] << 8) | (chars[index + 1] & 0xff));
}

void MirTileMap::setWidth(short _width)
{
	this->m_width = _width;
}

void MirTileMap::setHeight(short _height)
{
	this->m_height = _height;
}

void MirTileMap::setTileSize(short width, short height)
{
	m_tileWidth = width;
	m_tileHeight = height;
}

void MirTileMap::setTileOrder(short bngOrder, short midOrder, short objOrder)
{
	m_bngOrder = bngOrder;
	m_midOrder = midOrder;
	m_objOrder = objOrder;
}

short MirTileMap::getWidth()
{
	return m_width;
}

short MirTileMap::getHeight()
{
	return m_height;
}

MapTileInfo* MirTileMap::getMapTiles()
{
	return m_pMapTiles;
}

MapTileInfo* MirTileMap::getMapTile(int row, int col)
{
	int index = row + m_width*col;

	return &m_pMapTiles[index];
}

void MirTileMap::release()
{
	if (m_pMapTiles != 0)
		delete[] m_pMapTiles;

	m_pMapTiles = 0;
	m_width = 0;
	m_height = 0;

	Layer::release();
}