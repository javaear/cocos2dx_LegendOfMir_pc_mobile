Game = {}

Game.netMove = function(pid, data)
	local actor = ActorManager:getActor(pid);
	local mapid = actor:getMap();
	local map =  MapManager:getMap(mapid);
	local actorPos = actor:getPosition();
	local isCanMove,reason = Game.checkMoveValid(map, actorPos, data);

	if isCanMove == true then
		local moveRet,reason = actor:move(data.isRun, data.dir, Game.moveEnd);

		if moveRet then
			GCCenter.sendSameScreenBroadcast(actor, {id="BC_ACTOR_MOVE", pid=pid, isRun=data.isRun, dir=data.dir, pos=actorPos});
		else
			--TraceError("actor:move failed, reason:"..tostring(reason).." data:"..tostringex(data));
		end
	else
		actor:moveOver();
		--TraceError("pid "..pid.."  isRun:"..tostring(data.isRun).." dir "..data.dir.." failed:"..tostringex(actorPos));
		GCCenter.sendSingleActor(actor, {ret=0, id="BC_ACTOR_MOVE_STOP", pos=actorPos, pid=pid})
	end
end

Game.checkMoveValid = function(map, fromPos, data)
	local nextPos = FuncPack:nextPositionWithDir(fromPos, data.dir, 1);
	if map:hasObstacle(nextPos) then
		LogPrint("1  ("..fromPos.x..","..fromPos.y..")  to "..tostringex(nextPos).." has obstacle, isRun:"..tostring(data.isRun).." \n");
		--LogPrint("1.1 client pos:("..data.pos.x..","..data.pos.y..")".."  server pos:("..fromPos.x..","..fromPos.y..")\n");
		return false, "has obstacle";
	end

	if data.isRun == 1 then
		local secondPos = FuncPack:nextPositionWithDir(fromPos, data.dir, 2);

		if map:hasObstacle(secondPos) then
			LogPrint("2  ("..fromPos.x..","..fromPos.y..")  to "..tostringex(secondPos).." has obstacle, isRun:"..tostring(data.isRun).." \n");
			--LogPrint("2.1 client pos:("..data.pos.x..","..data.pos.y..")".."  server pos:("..fromPos.x..","..fromPos.y..")\n");
			return false, "forward 2 has obstacle";
		end
	end

	if data.pos.x ~= fromPos.x or data.pos.y ~= fromPos.y then
		LogPrint("pos not match client pos:"..tostringex(data.pos).."   server pos:"..tostringex(fromPos));
		return false;
	end

	return true;
end

--移动结束
Game.moveEnd = function(actor, success)
	local actors = GCCenter.getCanSeeActors(actor:getID());
	for k,v in pairs(actors) do
		if not actor:hasMonitor(v:getID()) then
			print(actor:getID().." move end monitor "..v:getID());

			GCCenter.sendSingleActor(actor, {id="BC_UPDATE_NEW_ACTOR", actorData=v:getBaseData()});

			actor:addMonitor(v:getID());
		end
	end
end

Game.netRequestActorData = function(pid, data)
	local requestActor = ActorManager:getActor(data.pid);

	if requestActor then
		local data = requestActor:getBaseData();
		local actor = ActorManager:getActor(pid);
		GCCenter.sendSingleActor(actor, {id="CLIENT_REQUEST_ACTOR_DATA", ret=1, actorData=data});
	end
end

Game.netAttack = function(pid, data)
	--local actor = ActorManager:getActor(pid);
	--actor:cast(data.skillName, data.values);
	--actor:cast(data.skillName, data.values);
end

Game.netCast = function(pid, data)
	local actor = ActorManager:getActor(pid);
	actor:cast(data.skillName, data.values);
end

Game.netUseItem = function(pid, data)
	local actor = ActorManager:getActor(pid);
	local itemGridIndex = actor:getItemGridIndex(data.itemId);
	local item = actor:getItem(itemGridIndex);

	if item then
		local ret, msg = item:use(actor, data.extraContent);

		if msg then
			if ret then
				GCCenter.sendSameScreenBroadcastWithFromObj(actor, msg);
			else
				GCCenter.sendSingleActor(actor, msg);
			end
		end
	else
		GCCenter.sendSingleActor(actor, {id="BC_ACTOR_USE_EQUIP", ret=0, itemid=data.itemId,error="no item "..data.itemId});
	end
end

Game.netPickupItem = function(pid, data)
	local actor = ActorManager:getActor(pid);
	local mapid = actor:getMap();
	local map = MapManager:getMap(mapid);

	if map then
		local point = data.point;
		local item = map:getItemFromMap(point);

		if item then
			local index = Game.addItem(pid, item);
			if index then
				Game.removeItemFromMap(mapid, point, item:getID());
			else
				TraceError("Game.netPickupItem cannot find bag space");
			end
		else
			TraceError("Game.netPickupItem cannot find item");
		end
	else
		TraceError("Game.netPickupItem cannot find map");
	end
end

Game.isCanEquip = function(actor, itemId)
	if actor:getItemGridIndex(itemId) then
		return true;
	end

	return nil;
end

Game.removeItemFromMap = function(mapid, point, itemid)
	local map = MapManager:getMap(mapid);
	if map then
		map:removeItem(point);

		GCCenter.sendAreaBroadcast(mapid, {id="BC_REMOVE_MAP_ITEM", point=point, itemid=itemid,mapid=mapid});

		return 1;
	end
end

--net使用某个装备，并且把旧的装备放回背包
Game.netUseEquip = function(pid, item, gridIndex, itemIndex)
	local actor = ActorManager:getActor(pid);
	local lastEquip = Game.useEquip(pid, item);

	if lastEquip then
		if lastEquip ~= 1 then
			Game.addItem(pid, lastEquip, gridIndex);
		end

		local equipData = item:getBaseData();
		GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_ACTOR_USE_EQUIP", pid=pid,
			equipData=equipData,ret=1,gridIndex=gridIndex,itemIndex=itemIndex});
	else
		TraceError(pid.." failed to use item:"..item.id);
		GCCenter.sendSameScreenBroadcast(actor, {id="BC_ACTOR_USE_EQUIP", pid=pid,equipData=equipData,ret=0});
	end
end

Game.netChangeItemPos = function(pid, data)
	local actor = ActorManager:getActor(pid);

	if not Game.userGridIndexIsValid(actor, data.index1) or not Game.userGridIndexIsValid(actor, data.index2) then
		TraceError("grid index invalid"..tostringex(data));
		return;
	end

	local item1 = Game.delItem(pid, data.index1);
	local item2 = Game.delItem(pid, data.index2);

	if item1 then
		Game.addItem(pid, item1, data.index2);
	end

	if item2 then
		Game.addItem(pid, item2, data.index1);
	end

	if item1 or item2 then
		GCCenter.sendSingleActor(actor, {id="BC_CHANGE_ITEM_POS", ret=1, grid1=data.index1,grid2=data.index2,pid=pid});
	end
end

Game.userGridIndexIsValid = function(actor, gridIndex)
	local itemMaxCount = actor:getItemMaxCount();

	if gridIndex <= 0 or gridIndex > itemMaxCount then
		return;
	end

	return true;
end

Game.changeMap = function(pid, newMapId, pos)
	local actor = ActorManager:getActor(pid);

	if actor then
		local mapId = actor:getMap();

		if mapId then
			local map = MapManager:getMap(mapId);
			map:removeObject(actor:getID());
		end

		mapId = mapId or 0;
		local newMap = MapManager:getMap(newMapId);
		local ret = newMap:addObject(actor, pos, true);

		if ret then
			if mapId == newMapId or not actor:getClient() then
				GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_CHANGE_OBJECT_POS", mapId=newMapId, pos=pos, pid=pid});
			else
				local otherActorsData,otherActors = GCCenter.getSameScreenActorsData(pid);
				local sameScreenItem = GCCenter.getSameScreenItems(pid);

				actor:clearMonitor();
				actor:addMonitor(otherActors);

				GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_CHANGE_OBJECT_POS", mapId=newMapId, pos=pos, pid=pid,others=otherActorsData, mapItemsData=sameScreenItem});
			end

			if mapId ~= newMapId then
				GCCenter.sendAreaBroadcast(mapId, {id="BC_ACTOR_LEAVE", pid=pid});
			end
		else
			TraceError("pid:"..pid.." change new map:"..newMapId.." failed");
		end
	else
		TraceError("pid:"..pid.." change new map:"..newMapId.." failed, because this actor no exists");
	end

	return true;
end

Game.revive = function(pid)
	local actor = ActorManager:getActor(pid);
	if actor then
		if actor:isDie() then
			actor:revive();

			GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_ACTOR_REVIVE", pid=pid, pos=actor:getPosition()});
		end
	end
end

--增加指定类型的道具给某个玩家
Game.addItemWithTypeId = function(pid, typeid, count)
	count = count or 1;

	local actor = ActorManager:getActor(pid);
	local restCount = actor:getItemMaxCount() - actor:getItemCurCount();

	if restCount >= count then
		if count == 1 then
			local index = actor:getNextFreeItemSpace();
			local item = ItemManager:createItem(typeid, pid, index);

			Game.addItem(pid, item, index);
		else
			local items = ItemManager:createItems(typeid, pid, 0, count);
			Game.addItems(pid, items);
		end

		--GCCenter.sendSingleActor(actor, {id="BC_ACTOR_ADD_ITEMS", pid=pid, itemData=data, index=index});
	end
end

Game.addItems = function(pid, itemGroups)
	local actor = ActorManager:getActor(pid);
	local itemsData = {};

	for k,item in pairs(itemGroups) do
		local index = actor:addItem(item);
		local data = item:getBaseData();

		itemsData[index] = data;

		DBServer:update("data_item", {isEquip=0,gridIndex=index,pid=pid}, {itemid=item.id})
	end

	GCCenter.sendSingleActor(actor, {id="BC_ACTOR_ADD_ITEMS", pid=pid, itemsData=itemsData});

	return true;
end

--增加某个实例item给某个玩家
Game.addItem = function(pid, item, index)
	local actor = ActorManager:getActor(pid);
	local index = actor:addItem(item, index);

	if not index then
		TraceError("add item has no space to place, please check code")
		return;
	end

	local data = item:getBaseData();
	GCCenter.sendSingleActor(actor, {id="BC_ACTOR_ADD_ITEM", pid=pid, itemData=data, index=index});
	----print("db update ret:"..tostring(ret).."         sql:"..tostring(sql));

	--update db data
	local ret,sql = DBServer:update("data_item", {isEquip=0,gridIndex=index,pid=pid}, {itemid=item.id})

	return index;
end

Game.useEquip = function(pid, item, extraContent)
	local actor = ActorManager:getActor(pid);
	local lastEquip = actor:equip(item, extraContent);

	if not lastEquip then
		LogPrint("Game.unEquip failed:"..item.id)
	end

	extraContent = extraContent or 0;
	--update db data
	local ret,sql = DBServer:update("data_item", {isEquip=1,gridIndex=0,extraContent=extraContent}, {itemid=item.id})
	if not ret then
		LogPrint("db update ret:"..tostring(ret).."         sql:"..tostring(sql));
	end

	return lastEquip;
end

Game.netDelEquip = function(pid, data)
	local actor = ActorManager:getActor(pid);
	local freeGridindex = actor:getNextFreeItemSpace();

	if freeGridindex then
		local oldEquip = actor:unEquip(data.etype);

		if oldEquip then
			local grid = Game.addItem(pid, oldEquip, freeGridindex);

			GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_ACTOR_REMOVE_EQUIP", pid=pid, etype=data.etype,grid=grid,ret=1});
		else
			GCCenter.sendSameScreenBroadcast(actor, {id="BC_ACTOR_REMOVE_EQUIP", pid=pid, etype=data.etype,error="no found equip",ret=0});
		end
	end
end

Game.netDelItem = function(pid, itemId)
	local actor = ActorManager:getActor(pid);
	local itemIndex = actor:getItemGridIndex(itemId);
	local item = nil;

	if itemIndex then
		local ret,sql = DBServer:doSql("delete from data_item where itemid="..itemId);

		if ret then
			item = actor:removeItem(itemIndex);

			if item then
				GCCenter.sendSingleActor(actor, {id="REMOVE_ITEM", itemId=itemId, pid=pid});

				return 1;
			else
				TraceError("motify database failed for no find item:"..itemId);
			end
		else
			TraceError("motify database failed for deling item:"..itemId);
		end
	end

	return item;
end

Game.delItem = function(pid, itemIndex)
	local actor = ActorManager:getActor(pid);
	local item = actor:removeItem(itemIndex);

	return item;
end

Game.delItemForId = function(pid, itemId)
	local actor = ActorManager:getActor(pid);
	local gridIndex = actor:getItemGridIndex(itemId);

	if gridIndex then
		local item = actor:removeItem(gridIndex);

		return item;
	end
end

Game.addExc = function(pid, exc)
	local actor = ActorManager:getActor(pid);

	if actor then
		local ret = actor:addExc(exc);
		if ret then
			DBServer:update("data_actor", {level=actor:getLevel(),exc=actor:getExc()}, {pid=actor:getID()})

			GCCenter.sendSingleActor(actor, {id="BC_ACTOR_ADD_EXC", exc=exc, pid=actor:getID()});
		end
	end
end

local TransFloatToRandom = function(per)
	local denominator = 1;

	while per < 1 do
		per = per*10;
		denominator = denominator*10;
	end

	return per,denominator;
end

Game.dropItemForMonDead = function(id)
	local monster = ActorManager:getActor(id);
	local pos = monster:getPosition();
	local mapid = monster:getMap();
	local map = MapManager:getMap(mapid);
	local conf = ActorConf[monster:getStyle()];
	if conf and map and pos then
		local dropItemConf = StringToTable(conf.sz_dropItem);

		for k,v in pairs(dropItemConf) do
			local per,denominator = TransFloatToRandom(v.per);

			local rand = FuncPack:getRandomNumber(1, denominator);
			if rand <= per then
				local typeid = v.typeid;

				local dropItemPos = map:getEmptyItemPosition(pos);
				if dropItemPos then
					Game.throwItemWithTypeId(typeid, mapid, dropItemPos);

					print("drop item "..typeid.." in map "..mapid.." at ("..dropItemPos.x..","..dropItemPos.y..")");
				else
					print("no found pos to drop item");
				end
			end
		end
	end--Game.dropItemForMonDead(1100001)
end

Game.addSkill = function(pid, skillid, level, exc)
	local actor = ActorManager:getActor(pid);

	if actor then
		local skill = SkillManager:addSkill({skillid=skillid,level=level,exc=exc})

		if skill then
			actor:addSkill(skill);

			--send addskill message
			GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_ADD_SKILL", pid=pid, skillInfo={skillid=skillid,level=level,exc=exc}});

			--update db
			local ret = DBServer:insert("data_skill", {"pid","skillid","level","exc"}, {pid, skillid, level, exc})
			if not ret then
				print("Game.addSkill update database failed");
			end

		else
			print("no found skill "..tostringex(v));
		end
	else
		print("no found actor:"..pid.." in Game.addSkill");
	end
end

Game.deleteSkill = function(pid, skillid)
	local actor = ActorManager:getActor(pid);

	if actor then
		local skill = actor:delSkill(skillid);
		if skill then
			GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_DEL_SKILL", pid=pid, skillid=skillid});

			local ret = DBServer:doSql("delete from data_skill where pid="..pid.." and skillid="..skillid);
			if not ret then
				print("Game.deleteSkill update database failed");
			end
		end
	end
end

Game.netThrowItem = function(pid, data)
	local item = Game.delItemForId(pid, data.itemId);
	if item then
		local actor = ActorManager:getActor(pid);
		local mapid = actor:getMap();
		local map = MapManager:getMap(mapid);
		local pos = map:getEmptyItemPosition(actor:getPosition());

		GCCenter.sendSingleActor(actor, {id="REMOVE_ITEM", itemId=data.itemId, pid=pid});
		Game.throwItem(item, mapid, pos);

		DBServer:update("data_item", {isEquip=0,gridIndex=index,pid=0}, {itemid=data.itemId});
	end
end

Game.throwItemWithTypeId = function(typeid, mapid, pos)
	local map = MapManager:getMap(mapid);

	if not map then
		TraceError("no found map:"..mapid);
		return;
	end

	if map:getItemFromMap(pos) then
		TraceError("no space for new item");
		return;
	end

	local item = ItemManager:createItem(typeid, 0, 0);
	if item then
		local ret = map:addItem(item, pos);
		if ret then
			GCCenter.sendAreaBroadcast(mapid, {id="BC_THROW_ITEM", items={{mapid=mapid, itemData=item:getBaseData(),pos=pos}}});
		else
			TraceError("add item failed");
		end
	else
		TraceError("create item failed");
	end
end

Game.throwItem = function(item, mapid, pos)
	local map = MapManager:getMap(mapid);

	if not map then
		TraceError("no found map:"..mapid);
		return;
	end

	if map:getItemFromMap(pos) then
		TraceError("no space for new item");
		return;
	end

	if item then
		local ret = map:addItem(item, pos);
		if ret then
			GCCenter.sendAreaBroadcast(mapid, {id="BC_THROW_ITEM", items={{mapid=mapid, itemData=item:getBaseData(),pos=pos}}});
		else
			TraceError("add item failed");
		end
	else
		TraceError("create item failed");
	end
end

Game.addMonForPet = function(masterId, data)
	local monster = ActorManager:getActor(data.pid);
	if not monster then
		local master = ActorManager:getActor(masterId);
		local mapid = master:getMap();
		local map = MapManager:getMap(mapid);

		local monster = ActorManager:createMonster(data);
		monster.masterId = masterId;
		local ret, con = map:addObject(monster, {x=data.x, y=data.y});

		if ret then
			monster:setAlertArea(15);
			monster:addScript("ai", PetAI:new(), master);
			monster:appear();
		else
			TraceError("Game.addMonForPet failed for "..con);
		end
	else
		TraceError("Game.addMonForPet failed for existing monster "..data.pid);
	end
end

--Game.addMonForPet(3, {pid=1000001,style=4, x=210, y=217});Game.addMonForPet(3, {pid=100000001,style=4, x=211, y=218});

Game.executeCode = function(pid, str)
	local actor = ActorManager:getActor(pid);

	if actor then
		GCCenter.sendSingleActor(actor, {id="BC_EXECUTE_CODE", code=str});
	end
end

Game.netSendMessage = function(pid, data)
	local actor = ActorManager:getActor(pid)

	if actor then
		local content = actor:getName()..":"..data.content;
		GCCenter.sendSameScreenBroadcastWithFromObj(actor, {id="BC_ACTOR_SEND_MESSAGE", content=content, type=data.type});
	end
end

Game.netNPCRequest = function(pid, data)
	--local actor = ActorManager:getActor(pid)
	local npcId = data.npcId;
	local npc = ActorManager:getActor(npcId);

	--LogPrint("Game.netNPCRequest :"..tostringex(data));
	if npc then
		npc:request(pid, data);
	end

	--local command = conf.tb_content[data.commandIdx];
	--local funcType = command.funcType;
	--local funcStr = command.funcStr;
end

Game.goHome = function(pid)
	local actor = ActorManager:getActor(pid)

	if actor then
		local mapId = actor:getMap();
		local mainCityId = MapConf[mapId].masterCity;
		local pos = MapConf[mainCityId].tb_masterCityPos;

		Game.changeMap(pid, mainCityId, pos);
	end

end

--test code:Game.throwItemWithTypeId(3, 1, {x=212, y=212})

--test Game.executeCode(3,"local a=ActorManager:getActor(3);print(a.attribute.slashSpeed)")

GCCenter.registActorEventFunc("ACTOR_MOVE", Game.netMove);
GCCenter.registActorEventFunc("UPDATE_OBJECTS", Game.netUpdateObjects);
GCCenter.registActorEventFunc("ACTOR_ATTACK", Game.netAttack);
GCCenter.registActorEventFunc("ACTOR_CAST", Game.netCast);
GCCenter.registActorEventFunc("ACTOR_USE_ITEM", Game.netUseItem);
GCCenter.registActorEventFunc("ACTOR_PICK_UP_ITEM", Game.netPickupItem);
GCCenter.registActorEventFunc("ACTOR_REMOVE_ITEM", Game.netDelItem);
GCCenter.registActorEventFunc("ACTOR_REMOVE_EQUIP", Game.netDelEquip);
GCCenter.registActorEventFunc("ACTOR_CHANGE_ITEM_POS", Game.netChangeItemPos);
GCCenter.registActorEventFunc("CLIENT_REQUEST_ACTOR_DATA", Game.netRequestActorData);
GCCenter.registActorEventFunc("ACTOR_SEND_MESSAGE", Game.netSendMessage);
GCCenter.registActorEventFunc("NPC_REQUEST", Game.netNPCRequest);
GCCenter.registActorEventFunc("ACTOR_THROW_ITEM", Game.netThrowItem);


