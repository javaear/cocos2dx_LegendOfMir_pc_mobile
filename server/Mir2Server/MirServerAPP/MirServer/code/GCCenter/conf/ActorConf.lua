--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/9
--此文件由[BabeLua]插件自动生成

--[[
--血量
    self.maxHp       = value.maxHp
    self.maxMp       = value.maxMp

    --游戏当前血量和魔法量
    self.hp          = self.maxHp
    self.mp          = self.maxMp

    --攻防属性
    self.attack      = stringToTable(value.sz_attack)     --1：物理攻击 2：魔法攻击3：道术攻击
    self.defense     = stringToTable(value.sz_defense)    --1：物理防御 2：魔法防御 3：道术防御

    --角色基本面板属性
    self.strength    = value.strength      --力量
    self.magic       = value.magic         --魔法
    self.aligity     = value.aligity       --敏捷
    self.taoistMagic = value.taoistMagic   --道术

    --这两个影响是否暴击,先计算暴击,计算失败在计算击中和躲避
    self.critRate    = value.critRate    --暴击力
    self.defenCrit   = value.defenCrit   --抗暴击力

    --这三个相互影响是否击中和躲避
    self.lucky       = value.lucky   --幸运
    self.precise     = value.precise --精准
    self.dodge       = value.dodge   --躲避力

    self.slashSpeed  = value.slashSpeed;
    self.speed       = value.speed;
    ]]

--endregion
local conf = {}
conf[1] = {}
conf[1].type = "Actor"
conf[1].conf = {name="Actor",camp=1,moveDelta=0,allowRun=true,slashDelta=2,
        slashSpeed=0.6, speed={0.8,0.4}, castSpeed=0.4, castDelta=2}
conf[1].levelAttribute =
{
    --     hp   mp          attack                 defense
    [1] = {maxHp=100000,maxMp=100,atk={{3,4},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [2] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [3] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [4] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
}

conf[2] = {}
conf[2].type = "Monster"
conf[2].conf = {name="monster1",camp=2,moveDelta=2,allowRun=false,slashDelta=2,
        path="mon3", offset=720,slashSpeed=0.6, speed={0.6,0.4}}
conf[2].levelAttribute =
{
    --     hp   mp          attack                 defense
    [1] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [2] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [3] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
    [4] = {maxHp=100,maxMp=100,atk={{10,100},{10,100},{10,100}},
        dfs={10,10,10},strength=10, magic=10, aligity=10, taoistMagic=10, critRate=10,
        defenCrit=10, lucky=10, precise=10, dodge=10, },
}

return conf;
