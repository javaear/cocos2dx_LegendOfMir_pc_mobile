
#include "cocos2d.h"
#include <string>

using namespace std;
USING_NS_CC;

class MapTileInfo
{
public:
	MapTileInfo(void);
	~MapTileInfo(void);

public:
	bool			addTileSpriteTo(Node* parent, int bngOrder, int midOrder, int objOrder);
	bool			initSprite();
	bool            initTestLabel();
	string			getFilename(int index);
	Point			getOffsetOfObject(int FileIndex, int index);
	void			getImgPath(char* buff, int index, char* path);

	Sprite*         getSpriteFromType(int type, int index);
	void			setAnchorPoint(int x, int y);
	void			setPosition(int x, int y);
	void			removeTileSprite();
	void			setVisible(bool visible);

	CC_SYNTHESIZE(Sprite*, m_bngImg, BngImg);
	CC_SYNTHESIZE(Sprite*, m_midImg, MidImg);
	CC_SYNTHESIZE(Sprite*, m_objImg, ObjImg);

	CC_SYNTHESIZE(short, m_row, Row);
	CC_SYNTHESIZE(short, m_col, Col);
	CC_SYNTHESIZE(short, m_bngIndex, BngIndex);
	CC_SYNTHESIZE(short, m_midIndex, MidIndex);
	CC_SYNTHESIZE(short, m_objIndex, ObjIndex);

	CC_SYNTHESIZE(char, m_doorIndex, DoorIndex);
	CC_SYNTHESIZE(char, m_doorOffset, DoorOffset);
	CC_SYNTHESIZE(char, m_aniFrame, AniFrame);
	CC_SYNTHESIZE(char, m_aniTick, AniTick);
	CC_SYNTHESIZE(char, m_objFileIndex, ObjFileIndex);
	CC_SYNTHESIZE(char, m_light, Light);

	CC_SYNTHESIZE(bool, m_canWalk, CanWalk);
	CC_SYNTHESIZE(bool, m_canFly, CanFly);
	CC_SYNTHESIZE(bool, m_hasBng, HasBng);
	CC_SYNTHESIZE(bool, m_hasMid, HasMid);
	CC_SYNTHESIZE(bool, m_hasObj, HasObj);
	CC_SYNTHESIZE(bool, m_hasDoor, HasDoor);
	CC_SYNTHESIZE(bool, m_doorOpen, DoorOpen);
	CC_SYNTHESIZE(bool, m_hasAni, HasAni);
	CC_SYNTHESIZE(bool, m_isInit, IsInit);
	CC_SYNTHESIZE(Point, m_objOffset, ObjOffset);

private:
	Sprite*    getSpriteFronPath(const char* path);

	Label*	   m_testLabel;
};

