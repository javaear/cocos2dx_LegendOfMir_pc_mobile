BaseSkill = class("BaseSkill")

function BaseSkill:ctor()
    self.attack = 0;
    self.level = 1
    self.attackType = 1;  --1.物理;2.魔法;3.道术
    self.name = "slash"
    self.power = 1  --威力大到一定程度会使目标后仰
    self.action = 1;      --对应动作id
    self.castClock = Clock:new();
    self.auto = false;   --是否在执行
    self.priority = 1;
    
    --预留给子类的特效
    self.effect = nil
end

--技能基本属性
function BaseSkill:initAttribute(param)
    self.attack = param.attack
    self.attackType = param.attackType
    self.name = param.sz_name
    self.action = param.action
    self.specialFunc = param.sepcialFunc;
    self.triggerRate = param.triggerRate;
    self.priority    = param.priority;
    self.castClock:setRingTimeDelta(param.coolDown);
    
    self.effect = engine.readSingleSprite(effectConf[param.effectid]);
end

--执行
function BaseSkill:run(object, values)
    self:markCastTime();
    self:playEffect(object, values);  --播放特效
    
    object:markSlashRingTime();
end

--普攻没有特效,如需要,则子类重载此函数
function BaseSkill:playEffect(object, values)
    if not self.effect then
        return;
    end

    self:adjustEffectPos(object)

    if self.effect.sprite:getParent() == nil then
        self.effect:addTo(object:getLayer(), object.zOrder + LayerzOrder.SKILL);
    end

    --setSpeed
    self.effect:setAllActionsSpeed(object:getSlashSpeed());
    self.effect:runAction(tostring(object:getDir()));
    self.effect.sprite:setVisible(true);
end

function BaseSkill:update(object)
end

function BaseSkill:isCoolDown()
    if self.castClock:ring() then
        return nil;
    end

    return 1;
end

--调整ui位置,父类不需要
function BaseSkill:adjustEffectPos(object)
    local pos = object:getPosition();
    self.effect:setPosition(pos.x, pos.y);
end

--结束动画进行结算
function BaseSkill:over(object, values)
    object.lockStatus = false;
    object:idle();

    self:closeEffect();
    
    local info = self:packageAttackInfo(object, values);
    engine.dispachEvent("attack", info);
end

function BaseSkill:closeEffect()
    if self.effect then
        self.effect.sprite:setVisible(false);
        self.effect:stopAllActions();
    end
end

--打包战斗信息
function BaseSkill:packageAttackInfo(object, values)
    local info = {}
    info.fromid = object.id;
    info.toid = values.id;
    info.attackInfo = {type=self.attackType,attack=self.attack, power=self.power}

    return info;
end

--是否符合条件
function BaseSkill:satifyCastPremise(object, values)
    if self:isCoolDown(self.coolDown) then
        return false;
    end

    if self.triggerRate then
        local rate = FuncPack:getRandomNumber(1, 100)

        if rate > self.triggerRate * 100 then
            return true
        end
    end
    
    if object:checkSlashClockRing() == false then
        return false;
    end

    return true;
end

function BaseSkill:markCastTime()
    self.castClock:markRingTime(); 
end

function BaseSkill:release()
    if not self.effect then
        self.effect:release();
    end
end