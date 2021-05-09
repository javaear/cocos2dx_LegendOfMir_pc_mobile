BuffSpell = class("BuffSpell",  function()
    return BaseSpell:new();
end)

function BuffSpell:ctor()
	self.currDamage = 0;
    self.attack = 0;
    self.level = 1
    self.attackType = 1;  --1.物理;2.魔法;3.道术
    self.name = "slash"
    self.power = 1  --威力大到一定程度会使目标后�?
    self.action = 1;      --对应动作id
    self.auto = false;   --是否在执�?
    self.priority = 1;
	self.type = 2;

	self.castClock = Clock:new();
	self.runningClock = Clock:new();

    --预留给子类的特效
    self.effect = nil
end

function BuffSpell:initAttribute(param)
    self.baseDamage  = param.baseDamage;
    self.growDamage  = param.growDamage;
    self.attackType  = param.attackType
    self.name        = param.sz_name
	self.sz_cn_name  = param.sz_cn_name
    self.event       = param.sz_event
    self.action      = param.action
    self.specialFunc = param.sepcialFunc;
    self.triggerRate = param.triggerRate;
    self.priority    = param.priority;
    self.castRange   = 0;--param.range;
	self.type        = param.type;
	self.needMagic   = param.needMagic;
    self.castClock:setRingTimeDelta(param.coolDown);
	self.runningClock:setRingTimeDelta(param.runningTime);
end

function BuffSpell:run(object, value)
	self:markCastTime(object);
	TraceError(self.name.."  start");
	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=values,srcPos=object:getPosition()});

    self:calculate(object, values);

	self.isRun = true;
end

function BuffSpell:update(object)
	--TraceError("getDeltaTime:"..self.runningClock:getDelayTime());
	if self.runningClock:ring() and self.isRun then
		self:close(object);
	end
end

function BuffSpell:close()
	self.isRun = nil;
end

function BuffSpell:calculate(object)
	self.currDamage = self.baseDamage;
end

function BuffSpell:getDamage(object, num)
	local oldNum = num;
	if self.isRun then
		num = num*(1-self.growDamage)
		if num < 0 then
			num = 0;
		end

		self.currDamage = self.currDamage - num;
		if self.currDamage > num then
			num = 0;
		else
			num = num - self.currDamage;

			self:close(object);
		end
	else
	end

	return num;
end

function BuffSpell:close(object)
	self.isRun = nil;
	--GCCenter.sendSameScreenBroadcastWithFromObj(object, {id="BC_BUFFSPELL_CLOSE", fromid=object:getID(), skillName=self.name});

	LogPrint(self.name.."  end");
end

function BuffSpell:satifyCastPremise(object, values)
    if self.castClock:ring() == false then
		--TraceError("cast "..self.name.." failed, because coolDown rest time:"..self.castClock:getDeltaTime());
        return false, "cooling down";
    end

	if object:checkCastClockRing() == false then
		--TraceError("cast "..self.name.." failed, because cast public coolDown rest time:");
        return false;
    end

	if self.needMagic > object:getMp() then
		return false, "no enough magic";
	end

    return true;
end

function BuffSpell:markCastTime(object)
	self.castClock:markRingTime();
	self.runningClock:markRingTime();
	object:markCastRingTime();
end
