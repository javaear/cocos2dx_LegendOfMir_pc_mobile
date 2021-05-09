
#include "MapTileInfo.h"

MapTileInfo::MapTileInfo(void)
{
	m_bngIndex = -1;
	m_midIndex = -1;
	m_objIndex = -1;
	m_bngImg = 0;
	m_midImg = 0;
	m_objImg = 0;
	m_hasObj = false;
	m_hasBng = false;
	m_hasMid = false;
	m_isInit = false;
	m_canWalk = false;
	m_canFly = false;

	m_testLabel = 0;
}


MapTileInfo::~MapTileInfo(void)
{
	removeTileSprite();
}

/*
void MapTileInfo::setBngImgIdx(short index)
{
	bngIndex = index;
}

void MapTileInfo::setHasBng(bool has)
{
	m
}

void MapTileInfo::setMidImgIdx(short index)
{
	midIndex = index;
}

void MapTileInfo::setHasMid(bool has)
{

}


void MapTileInfo::setObjImgIdx(short index)
{
	objIndex = index;
}

void MapTileInfo::setHasObj(bool has)
{

}

short MapTileInfo::getBngImgIdx()
{
	return bngIndex;
}

short MapTileInfo::getMidImgIdx()
{
	return midIndex;
}

short MapTileInfo::getObjImgIdx()
{
	return objIndex;
}

void MapTileInfo::setCanWalk(bool has)
{

}

void MapTileInfo::setCanFly(bool has)
{

}

void MapTileInfo::setDoorIdx(char index)
{

}

void MapTileInfo::setHasDoor(bool has)
{

}

void MapTileInfo::setDoorOffset(char index)
{

}

void MapTileInfo::setDoorOpen(bool has)
{

}

void MapTileInfo::setAniFrame(char index)
{

}

void MapTileInfo::setHasAni(bool has)
{

}

void MapTileInfo::setAniTick(char index)
{

}

void MapTileInfo::setObjFileIdx(char index)
{

}

void MapTileInfo::setLight(char index)
{

}*/

void MapTileInfo::setVisible(bool visible)
{
	if (m_bngImg)
		m_bngImg->setVisible(visible);

	if (m_midImg)
		m_midImg->setVisible(visible);

	if (m_objImg)
		m_objImg->setVisible(visible);

	if (m_testLabel)
		m_testLabel->setVisible(visible);
}

void MapTileInfo::setPosition(int x, int y)
{
	MapTileInfo* self = this;

	if (m_bngImg)
		m_bngImg->setPosition(x, y - 32);

	if (m_midImg)
		m_midImg->setPosition(x, y - 32);

	if (m_objImg)
		m_objImg->setPosition(x, y);

	if (m_testLabel)
		m_testLabel->setPosition(x+24,y+16);
}

void MapTileInfo::setAnchorPoint(int x, int y)
{
	Point point = Point(x, y);

	if (m_bngImg)
		m_bngImg->setAnchorPoint(point);

	if (m_midImg)
		m_midImg->setAnchorPoint(point);

	if (m_objImg)
		m_objImg->setAnchorPoint(point);
}

bool MapTileInfo::addTileSpriteTo(Node* parent, int bngOrder, int midOrder, int objOrder)
{
	if (m_bngImg)
		parent->addChild(m_bngImg, bngOrder);

	if (m_midImg)
		parent->addChild(m_midImg, midOrder);

	if (m_objImg)
		parent->addChild(m_objImg, objOrder);

	if (m_testLabel)
		parent->addChild(m_testLabel, 1000);

	return true;
}

bool MapTileInfo::initSprite()
{
	bool isDrawBng = (m_col+1)%2 == 0 && (m_row)%2 == 0;

	if (getHasBng() && isDrawBng)
		m_bngImg = getSpriteFromType(1, m_bngIndex);

	if (getHasMid())
		m_midImg = getSpriteFromType(2, m_midIndex);

	if (getHasObj())
		m_objImg = getSpriteFromType(3, m_objIndex);

	setIsInit(true);

	return true;
}

bool MapTileInfo::initTestLabel()
{
	m_testLabel = Label::create();
	char buff[50];
	sprintf(buff, "%d\n%d", getRow(), getCol());
	m_testLabel->setString(buff);

	return true;
}

Sprite* MapTileInfo::getSpriteFromType(int type, int index)
{
	Sprite *pSprite = 0;
	char filename[30];

	switch(type)
	{
	case 1:
		getImgPath(filename, index, "Tiles");
		pSprite = getSpriteFronPath(filename);
		break;
	case 2:
		getImgPath(filename, index, "SmTiles");
		pSprite = getSpriteFronPath(filename);
		break;
	case 3:
		char path[20];
		int objFileIdx = (int)m_objFileIndex;
		sprintf(path, "objects%d", objFileIdx+1);
		getImgPath(filename, index, path);

		pSprite = getSpriteFronPath(filename);
		//Æ«ÒÆ
		if (pSprite)
		{
			Point offset = getOffsetOfObject(m_objFileIndex+1, m_objIndex);
			Size size = pSprite->getContentSize();
			Point objOffset(offset.x, offset.y+size.height);
			m_objOffset = objOffset;
		}
		break;
	}

	return pSprite;
}

Sprite* MapTileInfo::getSpriteFronPath(const char* path)
{
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(path);

	if (frame == 0)
		return Sprite::create(path);

	auto sprite = Sprite::createWithSpriteFrame(frame);

	return sprite;
}

Point MapTileInfo::getOffsetOfObject(int FileIndex, int index)
{
	char path[40];
	string filename = getFilename(index);
	sprintf(path, "objects%d/Placements/%s.txt", FileIndex, filename.c_str());
	string fullPath = CCFileUtils::getInstance()->fullPathForFilename(path);
	String coordinate = CCFileUtils::getInstance()->getStringFromFile(fullPath);
	Array *pArray = coordinate.componentsSeparatedByString("\n");

	String* xstr = (String*)pArray->getObjectAtIndex(0);
	String* ystr = (String*)pArray->getObjectAtIndex(1);
	int x = (int)xstr->intValue();
	int y = (int)ystr->intValue();

	return Point(x, y);
}

string MapTileInfo::getFilename(int i)
{
	char buff[7];

	if (i < 10)
		sprintf(buff, "0000%d", i);
	else if(i < 100)
		sprintf(buff, "0000%d", i);
	else if(i < 1000)
		sprintf(buff, "000%d", i);
	else if(i < 10000)
		sprintf(buff, "00%d", i);
	else if (i < 100000)
		sprintf(buff, "0%d", i);

	string filename = buff;

	return filename;
}

void MapTileInfo::getImgPath(char* buff, int i, char* path)
{
	if (i < 10)
		sprintf(buff, "%s_00000%d.png", path, i);
	else if(i < 100)
		sprintf(buff, "%s_0000%d.png", path, i);
	else if(i < 1000)
		sprintf(buff, "%s_000%d.png", path, i);
	else if(i < 10000)
		sprintf(buff, "%s_00%d.png", path, i);
	else if (i < 100000)
		sprintf(buff, "%s_0%d.png", path, i);
}

void MapTileInfo::removeTileSprite()
{
	Node* parent = 0;

	if (m_bngImg)
	{
		parent = m_bngImg->getParent();

		if (parent == 0)
			return;

		parent->removeChild(m_bngImg);
	}

	if (m_midImg)
		parent->removeChild(m_midImg);

	if (m_objImg)
		parent->removeChild(m_objImg);

	if (m_testLabel)
		parent->removeChild(m_testLabel);
}

