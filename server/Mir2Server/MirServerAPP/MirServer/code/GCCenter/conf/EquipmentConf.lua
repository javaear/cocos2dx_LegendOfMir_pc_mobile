--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/9
--此文件由[BabeLua]插件自动生成



--endregion
local attribute = {}

--衣服
local equipConf = {};
equipConf.conf = 
{   name="新手衣服", type=1, mapSpritePath="human1", 
    mapSpriteOffset=1200, sz_mapIconSprite="mapIcon/000060.png",
    sz_bagIconSprite = "mapIcon/000060.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000597.png"
}
equipConf.attribute = 
{
    maxHp=100,maxMp=100,atk={},
    dfs={100,100,100},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

--武器
equipConf = {};
equipConf.conf = 
{   name="裁决之杖", type=2, mapSpritePath="weapon1", 
    mapSpriteOffset=28800, sz_mapIconSprite="mapIcon/000055.png",
    sz_bagIconSprite = "mapIcon/000055.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000055.png"
}
equipConf.attribute = 
{
    maxHp=100,maxMp=100,atk={{0,40}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);


--头盔
equipConf = {};
equipConf.conf = 
{   name="新手头盔", type=3, mapSpritePath="wu", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000100.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "001369.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

--项链
equipConf = {};
equipConf.conf = 
{   name="新手棍", type=4, mapSpritePath="weapon1", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000030.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000192.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

--手镯
equipConf = {};
equipConf.conf = 
{   name="新手棍", type=5, mapSpritePath="weapon1", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000030.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000192.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
    sz_bagIconSprite = "bagItemIcon/000100.png",
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

equipConf = {};
equipConf.conf = 
{   name="新手棍", type=6, mapSpritePath="weapon1", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000030.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000192.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    sz_bagIconSprite = "bagItemIcon/000100.png",
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

--戒指
equipConf = {};
equipConf.conf = 
{   name="新手棍", type=7, mapSpritePath="weapon1", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000030.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000165.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

equipConf = {};
equipConf.conf = 
{   name="新手棍", type=8, mapSpritePath="weapon1", 
    mapSpriteOffset=30000, sz_mapIconSprite="mapIcon/000030.png",
    sz_bagIconSprite = "bagItemIcon/000100.png",
    sz_bigIconDir = "stateItemIcon", sz_bigIconFile = "000172.png"
}
equipConf.attribute = 
{
    maxHp=0,maxMp=0,atk={{0,3}},
    dfs={},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10, 
    defenCrit=10, lucky=10, precise=10, dodge=10
}
table.insert(attribute, #attribute+1, equipConf);

--头发

return attribute;