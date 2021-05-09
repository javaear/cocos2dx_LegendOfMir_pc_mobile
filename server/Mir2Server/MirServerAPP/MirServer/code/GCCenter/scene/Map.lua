Map = {}
Map.__index = Map

local objLayerIndex = 2
local itemLayerIndex = 1

function Map:create()
    local map = {};
    setmetatable(map, Map)
    map:ctor();
    return map;
end

function Map:ctor()
	self.currMonId = 0;

	--portal info
	self.portalList = {};

	--object tile
    self.mapTiles = {}
	self.mapTiles[1] = {}
	self.mapTiles[2] = {}

	self.actorGroups = {};

    self.loadedTilesRects = {};
    self.layer = et.MirTileMap:create();

	self.monGenerator = MapMonsterGenerator:new();
end

function Map:initAll(conf)
    self:initWithJsonFile(conf.sz_path, "loadMapComplete");
	self:setID(conf.id);

	self.conf = conf;
end

function Map:initWithJsonFile(filename, callback)
    self.layer:initWithMapFile(filename, callback);
end

function Map:initWithSize(tileSize)
    self.tileSize = tileSize;
end

function Map:updateMapSize()
    self.mapSize = {width=self.layer:getWidth(), height=self.layer:getHeight()}
	self.tileSize = {width=TILE_WIDTH, height=TILE_HEIGHT};
end

function Map:initConf()
	self:initMonster();
	self:initPortal();
	self:initNPC();
end

function Map:initMonster()
	local monsterConf = readTabFile(self.conf.sz_monster_distribute);
	if not monsterConf then
		return;
	end

	for k,v in pairs(monsterConf) do
		v.pid = self:getNextFreeId();
		--v.skill = StringToTable(v.sz_skill);

		local monster = ActorManager:createMonster(v);
		self:addObject(monster, {x=v.x, y=v.y}, true);

		if v.sz_aiScript then
			local createFunc = loadstring("return "..v.sz_aiScript..":new()")--"return "..v.sz_aiScript..":new();";
			local ai = createFunc();
			if ai then
				monster:addScript("ai", ai);
			else
				print("no found class "..v.sz_aiScript);
			end
		end

		monster:appear();
		self.monGenerator:addMonster(monster, v.reviveTime);
	end
end

function Map:initNPC()
	local npcConf = readTabFile(self.conf.sz_npc_conf);
	if not npcConf then
		return;
	end

	for k,v in pairs(npcConf) do
		v.pid = self:getNextFreeId();

		local npc = ActorManager:createNPC(v);
		local ret = self:addObject(npc, {x=v.x, y=v.y}, true);

		if not ret then
			LogPrint("add npc to map failed");
		end
	end
end

function Map:initPortal()
	local portalConf = readTabFile(self.conf.sz_portal_conf);
	if not portalConf then
		return;
	end

	for k,v in pairs(portalConf) do
		local x = v.x;
		local y = v.y;
		local TargetMapId = v.TargetMapId;
		local TargetX = v.TargetX;
		local TargetY = v.TargetY;
		local index = self:tranferPosToIndex({x=x,y=y});
		self.portalList[index] = {x=TargetX,y=TargetY,mapId=TargetMapId};
	end
end

function Map:getPortal(pos)
	if self:checkPosValid(pos) == false then
		return nil;
	end

	local index = self:tranferPosToIndex({x=pos.x,y=pos.y});
	return self.portalList[index];
end

function Map:getNextFreeId()
	local id = self.currMonId + self.id*1000000;
	self.currMonId = self.currMonId + 1;

	return id;
end

function Map:update(dt)
	for k,actor in pairs(self.actorGroups) do
		if actor:isDie() then
			--self:removeObject(actor:getID());
		else
			actor:update(dt);
		end
	end

	self.monGenerator:update();
end

function Map:addObject(object, point, isIgnoreLand)
	if self:checkPosValid(point) == false then
		return false, "no valid point";
	end

    local curLayer = self.mapTiles[objLayerIndex];
    local mapSize = self.mapSize;
    local tileSize = self.tileSize;

    if self:getObjectFromMap(point) == nil or isIgnoreLand then
        --标记玩家位置
        self:sigalObjectPosition(object, point);

		self:sigalObject(object);

		object:setMap(self.id);
		--LogPrint("name:"..tostring(object:getName()).." id:"..tostring(object:getID()).." add to mapid:"..self.id.." with pos:("..point.x..","..point.y..")");

        return true;
	else

    end

    return false, "has obstacle";
end

function Map:alterObjectPosition(object, pos)
	if not self.actorGroups[object:getID()] then
		return;
	end

	if self:hasObstacle(pos) then
		return;
	end

	self:sigalObjectPosition(object, pos);

	return true;
end

function Map:removeObject(id)
	local layer = objLayerIndex;
    local actor = self.actorGroups[id];

    if actor then
        local pos = actor:getPosition();
        local index  = self:tranferPosToIndex(pos);
        local objects = self.mapTiles[layer][index];

        for k,v in pairs(objects) do
            if v:getID() == id then
                self.mapTiles[layer][index][k] = nil;
            end
        end

		actor.map = nil;
        self.actorGroups[id] = nil;
    end
end

function Map:getObjectWithId(id)
    return self.actorGroups[id];
end

function Map:sigalObject(object)
	--id
    self.actorGroups[object:getID()] = object;
end

function Map:sigalObjectPosition(object, pos)
	if self:checkPosValid(pos) == false then
		return nil;
	end

	local isAlreadyInMap = ni;
	local layer = objLayerIndex;

    if object:getMap() then
        local oldPos   = object:getPosition();
        self:delObjectWithIdAndPosition(object:getID(), oldPos);

		isAlreadyInMap = true;
    end

    local index = self:tranferPosToIndex(pos);
	if not self.mapTiles[layer][index] then
		self.mapTiles[layer][index] = {};
	end

	table.insert(self.mapTiles[layer][index], #self.mapTiles[layer][index]+1, object);

	object:setPosition(pos.x, pos.y);

	--add object to map succeed
	local portal = self:getPortal(pos);
	if portal and isAlreadyInMap and object:getClient() then
		object:stopScripts();
		Game.changeMap(object:getID(), portal.mapId, {x=portal.x,y=portal.y});
	end
end

function Map:delObjectWithIdAndPosition(id, pos)
	if self:checkPosValid(pos) == false then
		return false;
	end

    local index = self:tranferPosToIndex(pos);
    local objects = self.mapTiles[objLayerIndex][index];

	if objects then
		for k,v in pairs(objects) do
			if id == v:getID() then
				self.mapTiles[objLayerIndex][index][k] = nil;

				--LogPrint("actor "..id.." be deleted from ("..pos.x..","..pos.y..")");
			end
		end
	end

	return true;
end


function Map:addItem(item, position)
	if not self:checkPosValid(position) then
		return;
	end

    if self:getItemFromMap(position) == nil then
        item:setPosition(position.x, position.y);
        item.map = self:getID();

        --标记玩家位置
        self:sigalItemPosition(item, position);
        return true;
    end

    return;
end

function Map:removeItem(position)
	if self:checkPosValid(position) == false then
		return;
	end

    local item = self:getItemFromMap(position)
    self:sigalItemPosition(nil, position);

	return item;
end

function Map:getItemFromMap(position)
	if self:checkPosValid(position) == false then
		return nil;
	end

    local itemLayer = itemLayerIndex;
    local index = self:tranferPosToIndex(position);

    return self.mapTiles[itemLayer][index];
end

function Map:sigalItemPosition(item, position)
    local itemLayer = itemLayerIndex;
    local index = self:tranferPosToIndex(position);--position.x + position.y*self.mapSize.width
    --删除老位置
    self.mapTiles[itemLayer][index] = item;

	return 1;
end

function Map:getEmptyItemPosition(pos)
	for i=1, 10 do
		local newPos = self:getEmptyItemPositionEx(pos, i);
		if newPos then
			return newPos;
		end
	end
end

function Map:getEmptyItemPositionEx(pos, distance)
	local x = pos.x - distance;
	local y = pos.y - distance;
	local len = 2*distance;

	for i=x, x+len,1 do
		for j=y,y+len,1 do
			local newPos = {x=i,y=j};

			if not self:getItemFromMap(newPos) and not (pos.x==i and pos.y==j) then
				return newPos;
			end
		end
	end
end

function Map:getEmptyObjectPosition(pos)
	for i=0, 10 do
		local newPos = self:getEmptyObjectPositionEx(pos, i);
		if newPos then
			return newPos;
		end
	end
end

function Map:getEmptyObjectPositionEx(pos, distance)
	local x = pos.x - distance;
	local y = pos.y - distance;
	local len = 2*distance;

	for i=x, x+len,1 do
		for j=y,y+len,1 do
			if i ~= pos.x or j ~= pos.y then
				local newPos = {x=i,y=j};

				if not self:getObjectFromMap(newPos) then
					return newPos;
				end
			end
		end
	end
end

--[[
function Map:getClosedPosition(fromPos, toPos)
	if self:checkPosValid(fromPos) == false then
		return nil;
	end

	if self:checkPosValid(toPos) == false then
		return nil;
	end

    local distance = nil;
    local closedPos = nil;

    local positions = FuncPack:getEightDirectionPosition(toPos);

    for k,v in pairs(positions) do
        local newDistance = self:getFreeSpaceDistanceToPosition(v, fromPos);
        if not distance or newDistance < distance then
            closedPos = v;
            distance = newDistance;
        end
    end

    return closedPos;
end

function Map:getFreePlaceAroundPosition(position, count)
	if self:checkPosValid(position) == false then
		return nil;
	end

    local positions = FuncPack:getEightDirectionPosition(position);
    local freePositions = {};

    for k,v in pairs(positions) do
        if self:getItemFromMap(v) == nil then
            table.insert(freePositions,#freePositions+1,v);
            count = count - 1;

            if count <= 0 then
                return freePositions;
            end
        end
    end

    return freePositions;
end

function Map:getFreeSpaceDistanceToPosition(pos, pos2, distance)
	if self:checkPosValid(pos) == false then
		return nil;
	end

	if self:checkPosValid(pos2) == false then
		return nil;
	end

    if self:getObjectFromMap(pos) then
       return 10000;
    end

    return FuncPack:getDistanceWithOfPositions(pos, pos2)
end]]

function Map:setID(id)
    self.id = id;
end

function Map:getID()
    return self.id;
end

function Map:retain()
    if self.layer then
        self.layer:retain();
    end
end

function Map:release()
    if self.layer then
        self.layer:release();
    end
end

function Map:getLoadingDataComplete()
    return self.layer:getInitComplete();
end


function Map:getActorsFromTiles()
    return self.mapTiles[objLayerIndex];
end

function Map:getActorsGroup()
    return self.actorGroups;
end

function Map:getItemsGroup()
    return self.mapTiles[itemLayerIndex];
end

function Map:getActorFromID(id)
	return self.actorGroups[id];
end

function Map:hasObstacle(pos, isLog)
	if self:checkPosValid(pos) == false then
		if isLog then
			LogPrint("("..pos.x..","..pos.y..")".." invalid");
		end
		return true;
	end

    local mapObj = self:getObjectFromMap(pos);

    if mapObj and #mapObj > 0 and self:allowOverlap(pos) == false then
		if isLog then
			LogPrint("("..pos.x..","..pos.y..")".." has obstacle");

			for k,v in pairs(mapObj) do
				LogPrint("obstacle id:"..v:getID());
			end
		end

        return true;
    end

    if self:getCanWalk(pos) == false then
		if isLog then
			LogPrint("("..pos.x..","..pos.y..")".." can not walk");
		end
        return true;
    end
end

function Map:getCanWalk(pos)
	local mapTile = self.layer:getMapTile(pos.x, pos.y);

    return mapTile:getCanWalk();
end

function Map:checkPosValid(pos)
	if not pos then
		return;
	end

	if not pos.x or not pos.y then
		return;
	end

	if pos.x >= self.mapSize.width or pos.x < 0 or pos.y >= self.mapSize.height or pos.y < 0 then
		return;
	end

	return true;
end

function Map:getObjectFromMap(pos)
	if self:checkPosValid(pos) == false then
		return nil;
	end

    local layer = objLayerIndex;
    local index  = pos.x + pos.y*self.mapSize.width
    local objects = self.mapTiles[layer][index];

	--local _objects = {}
    if objects then
		for k,v in pairs(objects) do
			if not v:isDie() then
				return objects;
			end
		end
    end

    return nil;
end

function Map:allowOverlap(pos)
    return false;
end

function Map:getObjectFromMapWithRange(leftBottom, rightTop)
    local leftBottomIndex = self:tranferPosToIndex(leftBottom);
    local rightTopIndex = self:tranferPosToIndex(rightTop);
    local rowOffset = rightTop.x - leftBottom.x;
    local colOffset = rightTop.y - leftBottom.y;

    local objList = {};
    local objLayer = self.mapTiles[objLayerIndex];

    for k,v in pairs(objLayer) do
        for col=0, colOffset do
            local rowMaxIndex = leftBottomIndex + rowOffset + col*self.mapSize.width;
            local rowMinIndex = leftBottomIndex + col*self.mapSize.width;

            if k >= rowMinIndex and k <= rowMaxIndex and v:isDie() == false then
                table.insert(objList, #objList+1, v);
            end
        end
    end

    return objList;
end

function Map:tranferPosToIndex(pos)
    return pos.x + pos.y*self.mapSize.width
end

function Map:tranferIndexToPos(index)
	local col,digit = math.modf(index/self.mapSize.width);
	local row = index - col*self.mapSize.width;

	return {x=row, y=col};
end

function Map:clearObjList()
    self.objList = nil;
end

--------------------------------------------------
---------
---------		network method
---------
--------------------------------------------------


