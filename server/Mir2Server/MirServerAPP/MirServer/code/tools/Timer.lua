Timer = class("Timer")

function Timer:ctor()
	self.clock = Clock:new();
	self.sleep = true;
end

function Timer:update()
	if self.clock:ring() then
		if self.func then
			if self.once then
				self.sleep = true;
			end

			self.func(param);
			self.clock:markRingTime();
		end
	end
end

function Timer:scheduleOnce(delay, func, param)
	self.clock:setRingTimeDelta(delay);
	self.clock:markRingTime();
	self.func = func;
	self.param = param;
	self.once = true;
	self.sleep = false;
end

function Timer:schedule(delay, func, param)
	self.clock:setRingTimeDelta(delay);
	self.clock:markRingTime();
	self.func = func;
	self.param = param;
	self.once = nil;
	self.sleep = false;
end

function Timer:moveTo()

end

function Timer:setSleep(sleep)
	self.sleep = sleep;
end

function Timer:getSleep()
	return self.sleep;
end

function Timer:close()
	self.sleep = true;
	self.func = nil;
end
