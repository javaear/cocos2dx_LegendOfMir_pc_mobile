Skill = {}
Skill.__index = Skill

function Skill:create()
    local skill = {}
    setmetatable(skill, Skill)
    skill:ctor();
    return skill;
end

function Skill:ctor()
    self.level = 0
    self.attack = 0
    self.type = 1;  --1.物理;2.魔法;3.道术
    self.name = ""
    self.specialFunc = 1; --1.无作用;2.麻痹;3.缚足
    self.action = 1;      --对应动作id
    self.castTime = -20;
    self.auto = false;   --是否在执行
end

function Skill:update(object)
    local coolingDownCallFunc = function()
        self.coolDown = false
    end
    
    --设置技能定时时间
    --(coolingDownCallFunc,1)
end

--技能基本属性
function Skill:initAttribute(parameter)
    self.attack = parameter.attack
    self.type = parameter.type
    self.name = parameter.sz_name
    self.event = parameter.sz_event
    self.action = parameter.action
    self.specialFunc = parameter.sepcialFunc;
    
    --特效
    self.effect = engine.readActionSpriteFromIndex(parameter.sz_effect)
    self.effect:retain();
end

--执行
function Skill:run(object, values)
    self.castTime = engine.gettime();  --标记释放时间
    self:playEffect(object, values);  --播放特效
    self.auto = true;   --标记状态
end

function Skill:isCoolDown(attackRate)
    local currTime = socket.gettime();
    local timeDelta = currTime - self.castTime;   --距离上次释放时间
    
    if attackRate < timeDelta then
        return nil;
    end

    return 1;
end

function Skill:playEffect(object, values)
    self:adjustEffectPos(object)

    if self.effect.sprite:getParent() == nil then
        self.effect:addTo(object:getLayer(), object.zOrder + LayerzOrder.SKILL);
    end
    
    self.effect.sprite:setVisible(true);
    self.effect:runAction(tostring(object:getDir()));
end

--调整ui位置
function Skill:adjustEffectPos(object)
    local pos = object:getPosition();
    self.effect:setPosition(pos.x, pos.y);
end

--结束动画进行结算
function Skill:over(object, values)
    object.lockStatus = false;
    object:idle();
    self.effect.sprite:setVisible(false);
    
    local info = self:packageAttackInfo(object, values);
    engine.dispachEvent("attack", info);
end

--打包战斗信息
function Skill:packageAttackInfo(object, values)
    local info = {}
    info.fromid = object.id;
    info.toid = values;
    
    return info;
end

--是否符合条件
function Skill:satifyCastPremise(object, values)
    if self:isCoolDown(object.attackRate) then
        return false;
    end

    return true;
end

function Skill:release()
    self.effect:release();
end