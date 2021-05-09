Clock = class("Clock")

function Clock:ctor()
    self.ringTimeDelta = 0;
    self.lastRingTime = 0;
end

function Clock:setRingTimeDelta(delta)
    if delta == nil then
        delta = 0;
    end

    self.ringTimeDelta = delta;
end

function Clock:getRingTimeDelta()
	return self.ringTimeDelta
end

function Clock:update()
end

function Clock:ring()
    local currTime = FuncPack:gettime();
    local timeDelta = currTime - self.lastRingTime;

    if timeDelta >= self.ringTimeDelta then
        return true;
    end

    return false;
end

function Clock:markRingTime()
    self.lastRingTime = FuncPack:gettime();
end

function Clock:getDelayTime()
	local currTime = FuncPack:gettime();
    local timeDelta = currTime - self.lastRingTime;

	return timeDelta;
end
