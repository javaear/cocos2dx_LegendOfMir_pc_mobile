--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/17
--此文件由[BabeLua]插件自动生成



--endregion
Player = {}
local gold = 0
local money = 0
local actors = {}
local currActorIndex = 0

function Player:setGold(_gold)
    gold = _gold;
end

function Player:setGold(_money)
    money = _money;
end

function Player:addActor(actor)
    table.insert(actors, #actors+1, actor);
end

function Player:changeActor(index)
    currActorIndex = index;
end

function Player:getCurrActor()
    return actors[currActorIndex];
end

function Player:getActor(id)
    return actors[id];
end