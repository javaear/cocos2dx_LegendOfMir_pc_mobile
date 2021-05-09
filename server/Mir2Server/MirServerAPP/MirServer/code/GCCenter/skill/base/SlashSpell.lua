SlashSpell = class("SlashSpell", function()
    return BaseSpell:new();
end)

function SlashSpell:ctor()
    self.attack = 0;
    self.level = 1
    self.attackType = 1;  --1.物理;2.魔法;3.道术
    self.name = "slash"
    self.power = 1  --威力大到一定程度会使目标后�?
    self.action = 1;      --对应动作id
    self.castClock = Clock:new();
    self.auto = true;   --是否在执�?
    self.priority = 1;
	self.type = 1;
	self.calcDamageTimer = TimerManager:getLongTimer();

    --预留给子类的特效
    self.effect = nil
end

--执行
function SlashSpell:run(object, values)
    self:markCastTime(object);

	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=values,srcPos=object:getPosition()});

    self:calculate(object, values);
end

--结束动画进行结算
function SlashSpell:calculate(object, dir)
	if dir <= 0 or dir > 8 then
		return;
	end

    local info = self:packageAttackInfo(object, dir);
    if info then
		self.calcDamageTimer:setSleep(false);

		self.calcDamageTimer:scheduleOnce(object:getSlashSpeed(), function(param)
			AttackScript:exec(info, {skillName=self:getName(), values=dir});
		end)
    end
end

--打包战斗信息
function SlashSpell:packageAttackInfo(object, dir)
    local info = {}
    info.fromid = object:getID();
	info.atkValue = {};

	local map = MapManager:getMap(object:getMap(), nil);
    local objPos = object:getPosition();
    local tarPos = FuncPack:nextPositionWithDir(objPos,dir,1)
	local targets = map:getObjectFromMap(tarPos);

    local baseAttack = object:getRandomAttack(self.attackType);
    local totalAttack = baseAttack*self.growDamage + self.baseDamage;

	if targets then
		for k,v in pairs(targets) do
			table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack, toid=v:getID()});
		end
	end

    return info;
end

--是否符合条件
function SlashSpell:satifyCastPremise(object, values)
    if self.castClock:ring() == false then
        return false;
    end

	if object.slashClock:ring() == false then
		return false;
    end

	--[[
    if self.triggerRate then
        local rate = FuncPack:getRandomNumber(1, 100)

        if rate > self.triggerRate * 100 then
            return false
        end
    end]]
	if self.needMagic > object:getMp() then
		return false, "no enough magic";
	end

    return true;
end

function SlashSpell:markCastTime(object)
    self.castClock:markRingTime();
	object:markSlashRingTime();
end

function SlashSpell:close()
	if self.calcDamageTimer then
		self.calcDamageTimer:close();
	end
end
