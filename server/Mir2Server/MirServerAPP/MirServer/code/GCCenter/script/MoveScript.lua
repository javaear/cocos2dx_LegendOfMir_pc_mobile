MoveScript = {}

--[[
function MoveScript:walk(object, dir, callFunc)
    local oldPos = object:getPosition();
	local newPos = FuncPack:nextPositionWithDir(oldPos, dir, 1);
	local speed =  object.attribute.speed[1];
	local map = MapManager:getMap(object.map);
	local success = map:alterObjectPosition(object, newPos)

	if not success then
		GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=oldPos});
	end

	object:moveOver();

	if callFunc then
		callFunc(object, success);
	end

	return success;
end
]]
function MoveScript:walk(object, dir, callFunc)
    local oldPos = object:getPosition();
	local newPos = FuncPack:nextPositionWithDir(oldPos, dir, 1);
	local speed =  object.attribute.speed[1];
	local map = MapManager:getMap(object.map);
	local success = map:alterObjectPosition(object, newPos)

	if success then
		local netDelay = 0;
		if not object.isNative then
			netDelay = speed/2;
		end

		object.moveTimer = TimerManager:getTimer():scheduleOnce(speed - netDelay, function()
			--TraceError(object:getID().."  walk from ("..oldPos.x..","..oldPos.y..") to ("..newPos.x..","..newPos.y..") successfully");
			object:moveOver();

			if callFunc then
				callFunc(object, success);
			end
		end);
	else
		GCCenter.sendSameScreenBroadcast(object, {_error="has obstacle", id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=oldPos});

		object:moveOver();

		if callFunc then
			callFunc(object, success);
		end
	end

	return success;
end

--[[
function MoveScript:run(object, dir, callFunc)
	local newPos  = FuncPack:nextPositionWithDir(object:getPosition(), dir, 1);
	local map     = MapManager:getMap(object.map);
	local speed   = object.attribute.speed[2];
	local success = map:alterObjectPosition(object, newPos)
	local _newPos = FuncPack:nextPositionWithDir(newPos, dir, 1);

	if success then
		object.moveTimer = TimerManager:getTimer():scheduleOnce(speed, function()
			success = map:alterObjectPosition(object, _newPos)

			if not success then
				GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=object:getPosition()});
			end

			object:moveOver();

			if callFunc then
				callFunc(object, success);
			end
		end);
	else
		GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=object:getPosition()});
		object:moveOver();
		return false;
	end

    return true;
end
]]
function MoveScript:run(object, dir, callFunc)
	local oldPos  = object:getPosition();
	local newPos  = FuncPack:nextPositionWithDir(oldPos, dir, 1);
	local map     = MapManager:getMap(object.map);
	local speed   = object.attribute.speed[2];

	local netDelay = 0;
	if not object.isNative then
		netDelay = speed/4;
	end

	object.moveTimer = TimerManager:getTimer():scheduleOnce(speed/2 - netDelay, function()
		local success = map:alterObjectPosition(object, newPos)
		local _newPos = FuncPack:nextPositionWithDir(newPos, dir, 1);

		--TraceError(object:getID().."  run 1 from ("..oldPos.x..","..oldPos.y..") to ("..newPos.x..","..newPos.y..") successfully");

		if success then
			object.moveTimer = TimerManager:getTimer():scheduleOnce(speed/2 - netDelay, function()
				success = map:alterObjectPosition(object, _newPos)

				if not success then
					GCCenter.sendSameScreenBroadcast(object, {_error="has obstacle", id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=object:getPosition()});
				else
					--TraceError(object:getID().."  run 2 from ("..newPos.x..","..newPos.y..") to (".._newPos.x..",".._newPos.y..") successfully");
				end

				object:moveOver();

				if callFunc then
					callFunc(object, success);
				end
			end);
		else
			GCCenter.sendSameScreenBroadcast(object, {_error="has obstacle", id="BC_ACTOR_MOVE_STOP", pid=object.id, pos=object:getPosition()});
			object:moveOver();
			return false;
		end
	end);

    return true;
end
