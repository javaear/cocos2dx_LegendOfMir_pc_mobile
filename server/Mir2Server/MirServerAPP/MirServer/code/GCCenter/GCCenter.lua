GCCenter = {}
GCCenter.init = function()
    GCCenter.initMap();

	GCCenter.synClock = Clock:new();
	GCCenter.synClock:setRingTimeDelta(5);
end

GCCenter.initModule = function()
	require "GCCenter/Login.lua"
	require "GCCenter/Game.lua"
end

GCCenter.initMap = function()
	LogPrint("read map......")

	MapManager:launch();

	local loadMapCount = 0;
	local totalMapCount = #MapConf;
	for k,v in pairs(MapConf) do
		local id = v.id;

		local map = MapManager:getMap(id, function()
			LogPrint("loading map id:"..id)
			loadMapCount = loadMapCount + 1;

			if loadMapCount == #MapConf then
				LogPrint("all map load completed");
			end

			if totalMapCount == loadMapCount then
				initServer();
				initDB();
				GCCenter.registDataCallFunc();

				LogPrint("init module")
				GCCenter.initModule();
				LogPrint("init module complete")

				LogPrint("init success all");
				GCCenter.isInit = true;

				--GCCenter.showDebugInfo();
			end
		end)
	end
	--Login.checkAccount(1, {account=2, password=2})

	--ItemManager:createItem(1, 1);
	--GCCenter.synActorPosiiton();
end

GCCenter.synActorPosiiton = function()
	local function scheduleSyncFunc()
		--print("syn pos");

		for k,v in pairs(MapManager.maps) do
			local mapid = v:getID();
			local actors = v:getActorsGroup();

			for id, actor in pairs(actors) do
				if actor:getClient() then
					local posMsg = {};
					local _actors = GCCenter.inspect(actor:getID());

					for k,v in pairs(_actors) do
						if not v.isMove then
							local pos = v:getPosition();
							table.insert(posMsg, #posMsg+1, {pos=pos,pid=v:getID()});
						end
					end

					----print("BC_SYNCHRONIZE_POSITION:"..tostringex(posMsg));
					GCCenter.sendSingleActor(actor, {id="BC_SYNCHRONIZE_POSITION",data=posMsg});
				end
			end
		end
	end

	TimerManager:getTimer():schedule(5, scheduleSyncFunc);
end

GCCenter.enterWorld = function(id, data)
	local aid = id;
	local actorData = Login.accounts[aid].actorsInfo[data.side];

	if actorData then
		local actor = ActorManager:getActor(actorData.pid);
		if not actor then
			actor = ActorManager:createActor(actorData);
			actor:setClient(id);
		end

		--[[
		if actor:isDie() then
			actor:revive();

			local mainCityId = MapConf[actorData.worldid].masterCity;
			local pos = MapConf[mainCityId].tb_masterCityPos;

			actorData.worldid = mainCityId;
			actorData.worldpos = pos;
		end]]

		local worldid = actorData.worldid;
		local worldpos = actorData.worldpos;
		TraceError("worldid:"..worldid);
		TraceError("worldpos:"..tostringex(worldpos));
		local map = MapManager:getMap(worldid, nil);
		map:addObject(actor, worldpos, true);

		local actorData = actor:getBaseData();
		local otherActorsData,otherActors = GCCenter.getSameScreenActorsData(actorData.pid);
		local sameScreenItem = GCCenter.getSameScreenItems(actorData.pid);

		actor:clearMonitor();
		actor:addMonitor(otherActors);

		GCCenter.sendSingleActor(actor, {ret=1, id="ENTER_WORLD", others=otherActorsData, mapItemsData=sameScreenItem});
		--server:send(id, )

		GCCenter.sendSameScreenBroadcast(actor, {id="BC_UPDATE_NEW_ACTOR", actorData=actorData});
		Login.accounts[aid].currActor = actorData.pid;
	else
        server:send(id, {ret=0, id="ENTER_WORLD"});
	end
end

GCCenter.getSameScreenActorsData = function(pid)
	local otherActors = GCCenter.getCanSeeActors(pid);
	local actorsData = {};

	for k,v in pairs(otherActors) do
		local data = v:getBaseData();
		data.ai_level = nil;
		data.reviveTime = nil;

		table.insert(actorsData, #actorsData+1, data);
	end

	return actorsData, otherActors;
	--GCCenter.sendSingleActor(actor, {actors=actorsData, id="UPDATE_OBJECTS"});
end

GCCenter.getSameScreenItems = function(pid)
	local actor = ActorManager:getActor(pid);
	local mapid = actor:getMap();
	local map =  MapManager:getMap(mapid);
	local itemsData = {};

	for k,v in pairs(map:getItemsGroup()) do
		local isSameScreen = true;--GCCenter.isSameScreenForItems(actor, v);
		local data = v:getBaseData();
		data.position = v:getPosition();

		if isSameScreen then
			table.insert(itemsData, #itemsData+1, data);
		else
			print("getSameScreenItems isSameScreen: "..tostring(isSameScreen));
		end
	end

	return itemsData;
end

local oldDebugStr = "";
GCCenter.update = function(dt)
	if not GCCenter.isInit then
		return;
	end

	GCCenter.updateMaps();

	--GCCenter.showDebugInfo();
	TimerManager:update(dt);
end

GCCenter.updateMaps = function(dt)
	for id,map in pairs(MapManager.maps) do
		--LogPrint("map id "..id.."  update");
		if map.update then
			map:update(dt);
		else
			print("no update for map:"..map:getID());
		end
	end
end

GCCenter.showDebugInfo = function()
	local debugStr = "";
	for id,map in pairs(MapManager.maps) do
		--LogPrint("map id "..id.."  update");
		if map.update then
			map:update(dt);
		else
			print("no update for map:"..map:getID());
		end

		debugStr = debugStr.."-----------------mapid:"..map:getID().."-----------------\r\n";
		local tiles = map:getActorsFromTiles();
		for posIndex,v in pairs(tiles) do
			for index,actor in pairs(v) do
				local pos = map:tranferIndexToPos(posIndex);
				local hp = actor:getHp();
				--debugStr = debugStr.."posIndex:"..posIndex.."  pos:("..pos.x..","..pos.y..")  actorid:"..actor:getID().."  ".."  hp:"..hp.."\r\n";
				debugStr = debugStr.."actorid:"..actor:getID().."  name:"..actor:getName().."    level:"..actor:getLevel().."  hp:"..hp.."  pos:("..pos.x..","..pos.y..")\r\n";
			end
		end
	end

	if oldDebugStr ~= debugStr then
		--print(debugStr);
		DebugStr(debugStr);
		oldDebugStr = debugStr;
	end


	--LogPrint("after map id "..id.."  update");
end

GCCenter.sendSingleClient = function(clientid, msg)
	--print("clientid:"..clientid.."     msg:"..tostringex(msg));
	server:send(clientid, msg);
end

GCCenter.sendSingleActor = function(actor, msg)
	local clientid = actor:getClient();

	if clientid then
		server:send(clientid, msg);
	end
end

GCCenter.sendSameScreenBroadcast = function(actor, msg)
	local mapid = actor:getMap();
	local map =  MapManager:getMap(mapid)

	if not map then
		return;
	end

	for k,v in pairs(map:getActorsGroup()) do
		if GCCenter.isSameScreen(actor, v) and v:getID() ~= actor:getID() then
			local clientid = v:getClient();

			if clientid then
				server:send(clientid, msg);
			end
		end
	end
end

GCCenter.sendSameScreenBroadcastWithFromObj = function(actor, msg)
	local map =  MapManager:getMap(actor:getMap())

	if not map then
		return;
	end

	if map then
		for k,v in pairs(map:getActorsGroup()) do
			if GCCenter.isSameScreen(actor, v) then
				local clientid = v:getClient();

				if clientid then
					server:send(clientid, msg);
				end
			end
		end
	end
end

GCCenter.sendAreaBroadcast = function(mapid, msg)
	local map =  MapManager:getMap(mapid)

	if not map then
		return;
	end

	for k,v in pairs(map:getActorsGroup()) do
		local clientid = v:getClient();
		if clientid then
			server:send(clientid, msg);
		end
	end
end

local sameScreenCellLength = 15;

GCCenter.isSameScreen = function(from, to)
	local fromPos = from:getPosition();
	local toPos = to:getPosition();

	local dis = FuncPack:getAbsoluteDistanceWithOPoints(fromPos, toPos);
	if dis <= sameScreenCellLength then
		--两个玩家同屏,则添加监听
		--from:addMonitor(to:getID());

		return true;
	else
		return false;
	end
end

GCCenter.isSameScreenForItems = function(actor, item)
	local fromPos = from:getPosition();
	local toPos = to:getPosition();

	local dis = FuncPack:getAbsoluteDistanceWithOPoints(fromPos, toPos);
	if dis <= sameScreenCellLength then
		return true;
	else
		return false;
	end
end

--是否可视
GCCenter.checkCanSee = function(from, to)
	local fromObj = ActorManager:getActor(from);
	local mapid = fromObj:getMap();
	local map = MapManager:getMap(mapid);

	if map then
		local actor = map:getActorFromID(to);

		if actor then
			local fromPos = fromObj:getPosition();
			local toPos = actor:getPosition();
			local dis = FuncPack:getAbsoluteDistanceWithOPoints(fromPos, toPos);

			if actor and not actor:isDie() and dis <= fromObj:getAlertArea() then
				return true;
			else
			end
		else
			return false;
		end
	end
end

--获取角色的可视范围内的敌人
GCCenter.getCanSeeEnemys = function(pid)
	local actor = ActorManager:getActor(pid)
	local mapid = actor:getMap();

	if mapid then
		local canSeeActors = {};
		local map = MapManager:getMap(mapid);
		local actors = map:getActorsGroup();

		for k,v in pairs(actors) do
			local canSee = GCCenter.checkCanSee(actor:getID(), v:getID());
			if pid ~= v:getID() and canSee and v:getCamp() ~= 3 then
				local isSameCamp = (v:getCamp() == actor:getCamp());

				if not isSameCamp then
					table.insert(canSeeActors, #canSeeActors+1, v);
				end
			end
		end

		return canSeeActors;
	end
end

GCCenter.getCanSeeActors = function(pid)
	local actor = ActorManager:getActor(pid)
	local mapid = actor:getMap();

	if mapid then
		local canSeeActors = {};
		local map = MapManager:getMap(mapid);
		local actors = map:getActorsGroup();

		for k,v in pairs(actors) do
			local canSee = GCCenter.checkCanSee(actor:getID(), v:getID());

			if pid ~= v:getID() and canSee then
				table.insert(canSeeActors, #canSeeActors+1, v);
			end
		end

		return canSeeActors;
	end
end

GCCenter.registDataCallFunc = function()
	server:registDataCallFunc("ENTER_WORLD", GCCenter.enterWorld)
	--server:registDataCallFunc("ACTOR_MOVE", GCCenter.actorMove);
	--server:registDataCallFunc("UPDATE_OBJECTS", GCCenter.updateObjects);
	--server:registDataCallFunc("ACTOR_ATTACK", GCCenter.actorAttack);
	--server:registDataCallFunc("ACTOR_USE_ITEM", GCCenter.useItem);
	server:addConnectEventListener(SERVER_EVENT_CLIENT_CLOSE, function(client)
		GCCenter.closeClient(client);
	end);

	server:addConnectEventListener(SERVER_EVENT_NEW_CLIENT, function(newClient)

	end);
end

GCCenter.closeClient = function(client)
	local aid = client:getID();
	local pid = Login.accounts[aid].currActor;

	if not pid then
		print("no find need to close client pid:"..tostring(aid));
		GCCenter.offLine(aid);
		return;
	end

	--print("close currActor id:"..pid);
	local actor = ActorManager:getActor(pid);
	local mapid = actor:getMap();
	--print("close currActor mapid:"..tostring(mapid));
	if mapid then
		local pos = actor:getPosition();
		local map = MapManager:getMap(mapid);
		map:removeObject(pid);

		actor:setMap(map:getID());
		actor:offLine();
		actor:clearMonitor();

		--send leave message
		LogPrint("Player "..pid.." leave game");
		GCCenter.sendSameScreenBroadcast(actor, {id="BC_ACTOR_LEAVE", pid=pid});

		DBServer:update("data_actor", {worldid=mapid, worldpos=pos}, {pid=pid});
		--DBServer:update("data_actor", {worldid=4, worldpos=‘sadas’}, {pid=1000});

		actor:setMap(nil);
		GCCenter.offLine(aid);
	end
end

GCCenter.offLine = function(aid)
	if Login.accounts[aid] then
		Login.accounts[aid].currActor = nil;
		Login.accounts[aid].isLogin = nil;
	end
	--Login.accounts[aid] = nil;
end

GCCenter.registActorEventFunc = function(name, func)
	server:registDataCallFunc(name, function(id, data)
		local pid = Login.accounts[id].currActor;

		if pid then
			local actor = ActorManager:getActor(pid);

			if actor and not actor:isDie() then
				if func then
					func(pid, data);
				else
					print("no func "..name);
				end
			else
				GCCenter.sendSingleActor(actor, {id="BC_GAME_ERROR",_error="你已经死亡,请选择复活"});
				print("no found pid:"..pid.." actor:"..tostring(actor).." name:"..name);
			end
		else
			print("no found "..pid);
		end
	end);
end
