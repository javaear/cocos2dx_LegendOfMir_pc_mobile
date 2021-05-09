FireWallUnit = class("FireWallUnit")
FireWallUnit.logSwitch = nil;

function FireWallUnit:ctor()
	self.calcDamageTimer = TimerManager:getLongTimer();
	self.runningTimer = TimerManager:getLongTimer();
	self.runningTime = 0;
end

function FireWallUnit:initAttribute(param)
	self.baseDamage  = param.baseDamage;
    self.growDamage  = param.growDamage;
    self.attackType  = param.attackType
	self.sz_cn_name = param.sz_cn_name;
end

function FireWallUnit:start(mapid, point, object)
	self.isRun = true;
	self.mapid = mapid;

	self.runningTimer:scheduleOnce(self.runningTime, function()
		print("close FireWallUnit");
		self.isRun = nil;
	end)

	self:initPosition(point, object);
end

function FireWallUnit:close()
	self.isRun = nil;
end

function FireWallUnit:setRunningTime(_time)
	self.runningTime = _time;
end

function FireWallUnit:initPosition(point, object)
	local upPos = FuncPack:nextPositionWithDir(point, 1, 1);
	local leftPos = FuncPack:nextPositionWithDir(point, 7, 1);
	local rightPos = FuncPack:nextPositionWithDir(point, 3, 1);
	local downPos = FuncPack:nextPositionWithDir(point, 5, 1);
	local centerPos = point;

	self.calcDamageTimer:schedule(1, function()
		--print("FireWallUnit:initPosition   self.isRun:"..tostring(self.isRun));
		if self.isRun then
			local atkInfo1 = self:packageAttackInfo(object, centerPos);
			local atkInfo2 = self:packageAttackInfo(object, upPos);
			local atkInfo3 = self:packageAttackInfo(object, leftPos);
			local atkInfo4 = self:packageAttackInfo(object, rightPos);
			local atkInfo5 = self:packageAttackInfo(object, downPos);

			local info = {};
			info.fromid = object:getID();
			info.atkValue = {};

			for _,v in pairs(atkInfo1) do
				table.insert(info.atkValue, #info.atkValue+1, v);
			end

			for _,v in pairs(atkInfo2) do
				table.insert(info.atkValue, #info.atkValue+1, v);
			end

			for _,v in pairs(atkInfo3) do
				table.insert(info.atkValue, #info.atkValue+1, v);
			end

			for _,v in pairs(atkInfo4) do
				table.insert(info.atkValue, #info.atkValue+1, v);
			end

			for _,v in pairs(atkInfo5) do
				table.insert(info.atkValue, #info.atkValue+1, v);
			end

			--[[
			if FireWallUnit.logSwitch then
				print("curr point:"..point.x..","..point.y);
				print("curr upPos:"..upPos.x..","..upPos.y);
				print("curr leftPos:"..leftPos.x..","..leftPos.y);
				print("curr rightPos:"..rightPos.x..","..rightPos.y);
				print("curr downPos:"..downPos.x..","..downPos.y);
				print("FireWallUnit attack:"..tostringex(info.atkValue));
			end]]

			AttackScript:exec(info, {skillName=self:getName()});
		else
			print("close FireWallUnit");
			self.calcDamageTimer:close();
		end
	end, param)
end

function FireWallUnit:getName()
	return self.sz_cn_name;
end

function FireWallUnit:packageAttackInfo(object, tarPos)
	local info = {}

    local baseAttack = object:getRandomAttack(self.attackType);
    local totalAttack = baseAttack*self.growDamage + self.baseDamage;
	local map = MapManager:getMap(object:getMap(), nil);
	local targets = map:getObjectFromMap(tarPos);

	if targets then
		for k,v in pairs(targets) do
			if v:getID() ~= object:getID() then
				table.insert(info, #info+1, {aty=self.attackType,
					atk=totalAttack, toid=v:getID()});
			end
		end
	end

	return info;
end
