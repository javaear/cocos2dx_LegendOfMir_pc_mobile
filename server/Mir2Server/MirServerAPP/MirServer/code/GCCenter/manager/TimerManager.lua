TimerManager = {}
TimerManager.timers = {};
TimerManager.longTimers = {};

function TimerManager:getTimer()
	for k,v in pairs(TimerManager.timers) do
		if v:getSleep() == true then
			v:setSleep(false);
			return v;
		end
	end

	local timer = self:createTimer();
	timer:setSleep(false);
	return timer;
end

function TimerManager:getLongTimer()
	--[[
	for k,v in pairs(TimerManager.longTimers) do
		if v:getSleep() == true then
			v:setSleep(false);
			return v;
		end
	end
	]]
	local timer = self:createLongTimer();
	timer:setSleep(false);
	return timer;
end

function TimerManager:update(dt)
	for k,v in pairs(TimerManager.timers) do
		if v:getSleep() == false then
			v:update(dt);
		end
	end

	for k,v in pairs(TimerManager.longTimers) do
		if v:getSleep() == false then
			v:update(dt);
		end
	end
end

function TimerManager:createTimer()
	local timer = Timer:new();
	table.insert(TimerManager.timers, #TimerManager.timers+1, timer);

	return timer;
end

function TimerManager:createLongTimer()
	local timer = Timer:new();
	table.insert(TimerManager.longTimers, #TimerManager.longTimers+1, timer);

	return timer;
end

function TimerManager:closeTimer(id)
	if TimerManager.timers[id] then
		TimerManager.timers[id]:close();
	end
end
