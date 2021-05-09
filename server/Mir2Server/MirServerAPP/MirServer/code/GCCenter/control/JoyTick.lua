--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/19
--此文件由[BabeLua]插件自动生成



--endregion
JoyTick = class("JoyTick", function()
    return cc.Node:create();
end)

function JoyTick:ctor()
    self:initUI();

    engine.addEventListenerWithScene(self, "removeItem", function(event)
        local itemIndex = event.info;--self.player:getItem(itemIndex);
        --移除道具
        self.player:removeItem(itemIndex);
    end);

    engine.addEventListenerWithScene(self, "useItem", function(event)
        --使用物品
        local data = event.info;--self.player:getItem(itemIndex);

        if data.type <= 10 then
            self:useEquip(data);
        end
    end);

	engine.addEventListenerWithScene(self, "addItem", function(event)
		local item = event.info;

		self.player:addItem(item);
		self:updateBag();
	end);

	engine.addEventListenerWithScene(self, "removeEquip", function(event)
		local equip = event.info;

		if equip.type <= 10 then
            self.player:unLoadPart(equip);

			self.statueWindow:removeEquip(equip:getType());
			self.statueWindow:updateAttribute(self.player:getAttribute());
        end
	end);

    engine.addEventListenerWithScene(self, "changeItem", function(event)
        local data = event.info;
        local item1 = self.player:getItem(data.index1);
        local item2 = self.player:getItem(data.index2);
        self.player:removeItem(data.index2)
        self.player:removeItem(data.index1)

        if item1 then
            self.player:addItem(item1, data.index2);
        end

        if item2 then
            self.player:addItem(item2, data.index1);
        end
    end);
end

function JoyTick:useEquip(data)
    --装备
    local oldPart = self.player:loadPart(data);

    if oldPart then
        self.player:addItem(oldPart, itemIndex);
        --状态面板删除ui
        local etype = data:getType();

        if self.statueWindow then
            self.statueWindow:removeEquip(etype);
        end
    end

    TraceError("update bag");
    --更新背包状态
    self:updateBag();

    --更新状态栏面板
    if self.statueWindow then
        self.statueWindow:addEquip(data);
        self.statueWindow:updateAttribute(self.player:getAttribute());
    end
end

function JoyTick:reloadStateWindow(actor)
    for k,v in pairs(self.statueWindow.equipGroup) do
        local etype = k;
        self.statueWindow:removeEquip(etype);
    end

    --更新状态栏面板
    for k,v in pairs(actor.parts) do
        self.statueWindow:addEquip(v);
    end

    self.statueWindow:updateAttribute(actor:getAttribute());
end

function JoyTick:initUI()
    if not self.bag then
		self.bag = Bag:new();
		self.bag:setPosition(200, 200);
		self.bag:hide();
        self.bag:registListener();
		self:addChild(self.bag);
	end

    if not self.statueWindow then
        self.statueWindow = StatueWindow:new();
        self.statueWindow:setPosition(400, 200);
        self.statueWindow:setVisible(false);
        self.statueWindow:setSex(1);
        self.statueWindow:showPanel(1)
        self.statueWindow:showAttributePanel(1);
        self:addChild(self.statueWindow)
    end

    local function putItemInGround()
        --切换场景
        local item1 = ItemManager:addEquip({typeid=4, itemid=1});
        local item2 = ItemManager:addEquip({typeid=3, itemid=2});
		local item3 = ItemManager:addEquip({typeid=1, itemid=3});
        local pos = self.player:getMap():getFreePlaceAroundPosition(self.player:getPositionOfMap(), 3);
        self.player.map:addItem(item1, pos[1]);
        self.player.map:addItem(item2, pos[2]);
		self.player.map:addItem(item3, pos[3]);
    end

    local function item2_callback()
        --切换场景
		self.player:cast("fireball", self.enemy);
    end

    local function item3_callback()
        --self.player:changeStatus("7");
        self.statueWindow:setVisible(true);
    end

    local function open_bag()
        self.bag:show();
    end

    local function changeMap()
        --self.player:remove();
        --engine.dispachEvent("changeMap", "");
    end

    local item1 = cc.MenuItemLabel:create(cc.Label:createWithTTF("putItemInGround","fonts/Marker Felt.ttf",20))
    item1:registerScriptTapHandler(putItemInGround)
    local item2 = cc.MenuItemLabel:create(cc.Label:createWithTTF("cast","fonts/Marker Felt.ttf",20))
    item2:registerScriptTapHandler(item2_callback)

    local item3 = cc.MenuItemLabel:create(cc.Label:createWithTTF("openStatueWindow","fonts/Marker Felt.ttf",20))
    item3:registerScriptTapHandler(item3_callback)

    local item4 = cc.MenuItemLabel:create(cc.Label:createWithTTF("revive","fonts/Marker Felt.ttf",20))
    item4:registerScriptTapHandler(function()
        --self.player:unLoadPartForType(1);
        self.player:revive();
    end)

    local bag = cc.MenuItemLabel:create(cc.Label:createWithTTF("openBag","fonts/Marker Felt.ttf",40))
    bag:registerScriptTapHandler(open_bag)

    local map = cc.MenuItemLabel:create(cc.Label:createWithTTF("changeMap","fonts/Marker Felt.ttf",20))
    map:registerScriptTapHandler(changeMap)

    local menu = cc.Menu:create(item1, item2,item3, bag, item4, map);

    item1:setPosition(200,300);
    item2:setPosition(250,300);
    item3:setPosition(300,300);
    item4:setPosition(100,300);
    map:setPosition(-200, 300);
    bag:setPosition(50, 200);
    self:addChild(menu);
end

function JoyTick:updateBag()
    self.bag:clearItem();
    self.bag:setItemData(self.player.items);
end

function JoyTick:setPlayer(player)
    self.player = player;
    self.enemy = nil;
end

function JoyTick:getPlayer()
    return self.player;
end

function JoyTick:updateStatueWindowSex(actor)
    local sex = actor:getSex();
    self.statueWindow:setSex(sex);

    self:updateStateWindow(actor);
end

function JoyTick:update(dt)
    if self.player then
        self:updatePlayerMove();
    end

	if self.player and self.player:checkMove()==false then
        local pos = self.player:getPositionOfMap();
        local item = self.player:getMap():getItemFromMap(pos);

        if item then
			local map = self.player:getMap();
			map:removeItem(pos);
            self.player:addItem(item);
            self:updateBag();
        end
    end
end

function JoyTick:onTouchBegan(touches, events)
    if self.player then
        local point = touches[1]:getLocation();
        self:touchMap(point);
    end
end

function JoyTick:onTouchMoved(touches, events)
    if self.player then
        local point = touches[1]:getLocation();

        self:playerMoving(point);
    end
end

function JoyTick:onTouchEnded(touches, events)
    if self.player then
        self:endPlayerMove();
    end
end

function JoyTick:touchMap(touchPoint)
    local currMap = self.player:getMap();
    local enemy  = self:getTouchActor(touchPoint, currMap);

    if enemy and enemy ~= self.player then
        self.player:executeScript("autofight", enemy:getID())
        self:chooseEnemy(enemy);
    else
        self:beginPlayerMove(touchPoint);
    end
end

function JoyTick:getTouchActor(touchPoint, currMap)
    --[[
    local touchMapPoint = currMap:scenePointToMapPoint(touchPoint);
    local touchMapPos = FuncPack:pointToPosition(touchMapPoint);
    local actorList = currMap:getObjectFromMapWithRange({x=touchMapPos.x-5,y=touchMapPos.y-5},
        {x=touchMapPos.x+5,y=touchMapPos.y+5});
    TraceError("|-----------------start--------------------|");
    TraceError("touchMapPoint:"..tostringex(touchMapPoint));
    TraceError("touchMapPos:"..tostringex(touchMapPos));
    TraceError("actorList:"..tostringex(#actorList));

    for k,actor in pairs(actorList) do
        local rect = actor:getCollisionRect();
        TraceError("rect:"..tostringex(rect));

        if FuncPack:rectContainPoint(rect, touchMapPoint) then
            return actor;
        end
    end

    TraceError("|-------------------end-------------------|");
    ]]
	local touchMapPoint = currMap:scenePointToMapPoint(touchPoint);
	local actorList = currMap:getActors();

	for k,actor in pairs(actorList) do
		if actor:isDie() == false then
			local rect = actor:getCollisionRect();

			if FuncPack:rectContainPoint(rect, touchMapPoint) == true then
				return actor;
			end
		end
	end

    return nil;
end


function JoyTick:beginPlayerMove(_cursorPoint)
    self.beginMove = true;
    self.cursorPoint = _cursorPoint;
    self.player:lockActorStatus();
    self.player:stopScripts();
end

function JoyTick:updatePlayerMove()
    if not self.beginMove then
        --TraceError("not begin move");
        return;
    end

    if self.player:getLockBehavior() then
        return true;
    end

    local currMap   = self.player:getMap();

    local tarPoint  = currMap:scenePointToMapPoint(self.cursorPoint);
    local targetPos = FuncPack:pointToPosition(tarPoint);
    local playerPos = self.player:getPositionOfMap();
    if FuncPack:isEqualPoint(playerPos, targetPos) then
        self:endPlayerMove();
        return true;
    end

    local direction = FuncPack:getDirectionWithPosition(playerPos, targetPos);
    local nextOneStepPos = FuncPack:nextPositionWithDir(playerPos, direction, 1);
    local nextOneHasObj = currMap:hasObstacle(nextOneStepPos);
    if nextOneHasObj then
        local findPathTargetPos = FuncPack:nextPositionWithDir(playerPos, direction, 4);
        local path = AStarFindPath:getAStarPath(playerPos,findPathTargetPos,currMap);

        if path then
            self:playerRunToOneStep({x=path[2].x/TILE_WIDTH, y=path[2].y/TILE_HEIGHT});
        end
    else
        local nextTwoStepPos = FuncPack:nextPositionWithDir(playerPos, direction, 2);
        local nextTwoHasObj = currMap:hasObstacle(nextTwoStepPos);
        local distance = FuncPack:getDistanceWithOfPositions(playerPos, targetPos);

        if nextTwoHasObj or distance < 2 then
            self.player:walk(direction);
        else
            self.player:run(direction);
        end
    end

    return true;
end

function JoyTick:chooseEnemy(enemy)
    if self.enemy then
        local oldEnemy = self.enemy;
        oldEnemy:setEffect(0)
    end

    enemy:setEffect(2);

    self.enemy = enemy;
end

function JoyTick:playerRunToOneStep(targetPos)
    local playerPos = self.player:getPositionOfMap();
    local direction = FuncPack:getDirectionWithPosition(playerPos, targetPos);
    local distance = FuncPack:getDistanceWithOfPositions(playerPos, targetPos);
    if distance < 2 then
        self.player:walk(direction);
    else
        self.player:run(direction);
    end
end

function JoyTick:playerMoving(_cursorPoint)
    if self.beginMove then
        self.cursorPoint = _cursorPoint;
    end
end

function JoyTick:endPlayerMove()
    self.beginMove = nil
    self.player:unLockActorStatus();

    --is walk stop
    if self.player.lockBehavior == false then
        self.player:idle();
    end
end
