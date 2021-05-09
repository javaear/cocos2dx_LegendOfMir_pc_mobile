ShootSpell = class("ShootSpell", function()
    return RangeSpell:new();
end)

function ShootSpell:ctor()
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

function ShootSpell:run(object, tarPos)
	self.from = object;
	self.tarPos = tarPos;
    self:markCastTime(object);
	self.calcDamageTimer:setSleep(false);
	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=tarPos,srcPos=object:getPosition()});

	self:calculate(object, tarPos);
end

--结束动画进行结算
function ShootSpell:calculate(object, tarPos)
    local info = self:packageAttackInfo(object, tarPos);

	if info then
		local objpos = object:getPosition();
		self.calcDamageTimer:scheduleOnce(object:getCastSpeed(), function(param)
			local enemypos = {x=TILE_WIDTH*tarPos.x, y=TILE_HEIGHT*tarPos.y}
			local objpos = {x=TILE_WIDTH*objpos.x, y=TILE_HEIGHT*objpos.y}
			local distance = FuncPack:getAbsoluteDistanceWithOPoints(enemypos, objpos);
			local flyTime = self.flyEffectSpeedPerPixel * distance;

			TimerManager:getTimer():scheduleOnce(flyTime,function(param)
				AttackScript:exec(info, {skillName=self:getName(), values=dir});
			end);
		end)
    end
end
