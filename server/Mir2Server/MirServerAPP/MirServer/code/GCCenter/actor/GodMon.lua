GodMon = class("GodMon", function()
    return Actor:new()
end)

function GodMon:ctor()
	self.isStand = nil;
	self.poseTimer = TimerManager:getLongTimer();
	self.poseTimer:setSleep(true);

	self.appearTimer = TimerManager:getLongTimer();
	self.appearTimer:setSleep(true);

	self.appearTime = 0.2;
	self.isAppear = nil;
end

function GodMon:getIsStand()
	return self.isStand;
end

function GodMon:appear()
	if not self.appearTimer:getSleep() or self.isAppear then
		return;
	end

	GCCenter.sendSameScreenBroadcast(self, {id="BC_MON_APPEAR", monData=self:getBaseData(), masterId=self.masterId});

	self.appearTimer:scheduleOnce(self.appearTime + 0.1, function()
		self.isAppear = true;
	end);
end

function GodMon:stand()
	if not self.poseTimer:getSleep() or self.isStand then
		return;
	end

	self.lockBehavior = true;
	self.poseTimer:scheduleOnce(0.1, function()
		self.isStand = true;
		self.lockBehavior = nil;
	end);

	GCCenter.sendSameScreenBroadcastWithFromObj(self, {id="BC_ACTOR_CHANGE_POSE", pid=self.id, stand=1});
end

function GodMon:climb()
	if not self.poseTimer:getSleep() or not self.isStand then
		return;
	end

	self.lockBehavior = true;
	self.poseTimer:scheduleOnce(0.1, function()
		self.isStand = nil;
		self.lockBehavior = nil;
	end);

	GCCenter.sendSameScreenBroadcastWithFromObj(self, {id="BC_ACTOR_CHANGE_POSE", pid=self.id});
end
