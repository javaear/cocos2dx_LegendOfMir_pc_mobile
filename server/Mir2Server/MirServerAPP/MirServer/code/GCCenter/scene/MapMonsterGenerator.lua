MapMonsterGenerator = class("MapMonsterGenerator")

function MapMonsterGenerator:ctor()
	self.monLiveGroups = {};
	self.monDeadGroups = {};
end

function MapMonsterGenerator:addMonster(mon, reviveTime)
	local workClock = Clock:new();
    workClock:setRingTimeDelta(reviveTime);

	self.monLiveGroups[mon:getID()] = {mon=mon,tick=workClock};
end

function MapMonsterGenerator:update(dt)
	for k,v in pairs(self.monLiveGroups) do
		--print("live mon:"..k);
		if v.mon:isDie() then
			self.monLiveGroups[k].tick:markRingTime();
			self.monDeadGroups[k] = self.monLiveGroups[k];
			self.monLiveGroups[k] = nil;

			print("id "..k.." has been dead  tick:"..self.monDeadGroups[k].tick:getDelayTime());
		end
	end

	for k,v in pairs(self.monDeadGroups) do
		if v.mon:isDie() then
			--print("donot worry, id "..k.." will be fine, with magic power, he will revive soon");

			if v.tick:ring() then
				print("revive: "..v.mon:getID().." after:"..v.tick:getDelayTime());
				Game.revive(v.mon:getID());
				--self.monDeadGroups[k].mon:revive();

				self.monLiveGroups[k] = self.monDeadGroups[k];
				self.monDeadGroups[k] = nil;
			else
				--print("id "..k.." has "..v.tick:getDelayTime().." before reviving");
			end
		else
			--print("dead group should not have live creature");
		end
	end
end
