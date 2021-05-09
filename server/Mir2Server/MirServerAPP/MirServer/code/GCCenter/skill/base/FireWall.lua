FireWall = class("RangeSpell", function()
    return RangeSpell:new();
end)

function FireWall:initAttribute(param)
    self.baseDamage  = param.baseDamage;
    self.growDamage  = param.growDamage;
    self.attackType  = param.attackType
    self.name        = param.sz_name
	self.sz_cn_name  = param.sz_cn_name;
    self.event       = param.sz_event
    self.action      = param.action
    self.specialFunc = param.sepcialFunc;
    self.triggerRate = param.triggerRate;
    self.priority    = param.priority;
    self.castRange   = param.castRange;
	self.type        = param.type
	self.needMagic   = param.needMagic;
	self.maxWallNum  = 4;
	self.wallList    = {};
    self.castClock:setRingTimeDelta(param.coolDown);

	for i=1, self.maxWallNum do
		local wall = FireWallUnit:new();
		wall:initAttribute(param);
		wall:setRunningTime(param.runningTime);
		table.insert(self.wallList, #self.wallList+1, wall);
	end

	self.currWallUnit = 0;
end

function FireWall:run(object, tarPos)
	self.from = object;
	self.tarPos = tarPos;
    self:markCastTime(object);

	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=tarPos,srcPos=object:getPosition()});

	self:calculate(object, tarPos);
end

--结束动画进行结算
function FireWall:calculate(object, tarPos)
    local info = self:packageAttackInfo(object, tarPos);

	if info then
		self.calcDamageTimer:scheduleOnce(object:getCastSpeed(), function(param)
			local wall = self:getNextFireWallUnit();
			wall:start(object:getMap(), tarPos, object);
		end)
    end
end

function FireWall:getNextFireWallUnit()
	local wall = self.wallList[self.currWallUnit+1];

	self.currWallUnit = (self.currWallUnit + 1) % (self.maxWallNum);

	return wall;
end
