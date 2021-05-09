RangeSpell = class("RangeSpell", function()
    return BaseSpell:new();
end)

function RangeSpell:ctor()
    self.attack = 0;
    self.level = 1
    self.attackType = 1;  --1.物理;2.魔法;3.道术
    self.name = "slash"
    self.power = 1  --威力大到一定程度会使目标后�?
    self.action = 1;      --对应动作id
    self.castClock = Clock:new();
    self.auto = true;   --是否在执�?
    self.priority = 1;
    self.flyEffectSpeedPerPixel = 0.0008;
	self.type = 2;
	self.calcDamageTimer = TimerManager:getLongTimer();

    --预留给子类的特效
    self.effect = nil
end

function RangeSpell:getSpriteTime(id)
	if id == 0 then
		return id;
	end

	local _time = spriteConf[id].ftime;
	return _time;
end

--执行
function RangeSpell:run(object, tarPos)
	self.from = object;
	self.tarPos = tarPos;
    self:markCastTime(object);
	self.calcDamageTimer:setSleep(false);

	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=tarPos,srcPos=object:getPosition()});

	self:calculate(object, tarPos);
end

function RangeSpell:update(object)
end

--结束动画进行结算
function RangeSpell:calculate(object, tarPos)
    local info = self:packageAttackInfo(object, tarPos);

	if info then
		local objpos = object:getPosition();
		self.calcDamageTimer:scheduleOnce(object:getCastSpeed(), function(param)
			local enemypos = {x=TILE_WIDTH*tarPos.x, y=TILE_HEIGHT*tarPos.y}
			local objpos = {x=TILE_WIDTH*objpos.x, y=TILE_HEIGHT*objpos.y}
			local distance = FuncPack:getAbsoluteDistanceWithOPoints(enemypos, objpos);
			local flyTime = self.flyEffectSpeedPerPixel * distance;
			local boomingTime = 0.1;

			TimerManager:getTimer():scheduleOnce(boomingTime + flyTime,function(param)
				AttackScript:exec(info, {skillName=self:getName(), values=dir});
			end);
		end)
    end
end

--打包战斗信息
function RangeSpell:packageAttackInfo(object, tarPos)
    local info = {}
    info.fromid = object:getID();
	info.atkValue = {};

    local baseAttack = object:getRandomAttack(self.attackType);
    local totalAttack = baseAttack*self.growDamage + self.baseDamage;

	local map = MapManager:getMap(object:getMap(), nil);
	local targets = map:getObjectFromMap(tarPos);

	if targets then
		for k,v in pairs(targets) do
			table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack, toid=v:getID()});
		end
	end

	return info;
end

--是否符合条件
function RangeSpell:satifyCastPremise(object, tarPos)
    if self.castClock:ring() == false then
        return false, "not coolDown";
    end

	if object:checkCastClockRing() == false then
		--TraceError("cast "..self.name.." failed, because cast public coolDown rest time:");
        return false, "not coolDown";
    end
	--��������,�����ܵ��ͷųɹ���
	--[[
    if self.triggerRate then
        local rate = FuncPack:getRandomNumber(1, 100)

        if rate > self.triggerRate * 100 then
            return true
        end
    end]]
	if self.needMagic > object:getMp() then
		return false, "no enough magic";
	end

    return true;
end

function RangeSpell:markCastTime(object)
    self.castClock:markRingTime();
	object:markCastRingTime();
end

function RangeSpell:close()
	if self.calcDamageTimer then
		self.calcDamageTimer:close();
	end
end
