Actor = class("Actor")
--[[
ActorDir =
{
    "up",
    "upright",
    "right",
    "rightdown",
    "down",
    "downleft",
    "left",
    "leftup",
}]]

--方向 1...8 表示正向上顺时针旋转
--状态1.。5 表示站立,走路,跑步,挥砍,施法
local statusAniStep = 8 --每个状态同方向的动画之间间隔

function Actor:ctor()
    --基本属性
    self.attribute   = Attribute:create();

    --初始化就不可以改了的
	self.style        = 1;
	self.name         = "";
    self.sex          = 1  --1 man 2 woman
    self.camp         = 1  --阵营 ,1为人类  其他为怪物
	self.gold         = 0;
	self.money        = 0;
	self.level        = 1;
	self.exc          = 0;

	self.baseData     = nil;

    --可以设置的属性
	self.attackMode   = 1;
    self.slashDelta   = 2;     --挥砍间隔
    self.moveDelta    = 0;     --移动间隔
    self.slashClock   = nil;   --挥砍计时时钟
    self.allowRun     = true;
	self.isAppear     = nil;

    self.type         = 1  --角色类型 对应actor.tab的id
    self.id           = 1  --人物唯一标识符

    self.x = 0
    self.y = 0
    self.zOrder = 0
	self.alertArea = 10;

    --身体部件
    --装备数组包括已经装备的
    self.parts =
    {
        [1] = nil,   --衣服
        [2] = nil,   --武器
        [3] = nil,   --头盔
        [4] = nil,   --项链
        [5] = nil,   --手镯
        [6] = nil,   --手镯
        [7] = nil,   --戒指
        [8] = nil,   --戒指
        [9] = nil,   --头发
        [10] = nil,  --待定
    }

    --技能
    self.skills = {}
	--self.equip = {}
	self.items = {};
	self.itemCount = 40;

	self.scripts = {};

	self.map = nil;
	self.monitorList = {};


	--callback func
	self.atkCallbackFunc = {};
	self.getDamageCallbackFunc = {};
	self.dieCallbackFunc = {};
	self.offLineCallbackFunc = {};
end

function Actor:setBaseData(data)
	self.baseData = data;
end

function Actor:setMasterId(id)
	self.masterId = id;
end

function Actor:getBaseData()
	self.baseData.name  = self.name;
	self.baseData.level = self.level;
	self.baseData.money = self.money;
	self.baseData.gold  = self.gold;
	self.baseData.curHp = self.attribute.hp;
	self.baseData.curMp = self.attribute.mp;
	self.baseData.skill = self:getCurrSkillData();
	self.baseData.item  = self:getCurrItemData();
	self.baseData.equip = self:getCurrEquipData();
	self.baseData.worldid = self.map or self.baseData.worldid;
	self.baseData.worldpos = self:getPosition();
	self.baseData.x = self.baseData.worldpos.x;
	self.baseData.y = self.baseData.worldpos.y;
	self.baseData.masterId = self.masterId;
	self.baseData.camp = self.camp;

	return self.baseData;
end

function Actor:getCurrItemData()
	local items = {};

	for k,v in pairs(self.items) do
		local data = v:getBaseData();
		data.gridIndex = k;
		table.insert(items, #items+1, data);
	end

	return items;
end

function Actor:appear()
	GCCenter.sendSameScreenBroadcastWithFromObj(self, {id="BC_UPDATE_NEW_ACTOR", actorData=self:getBaseData()});

	self.isAppear = true;
end

function Actor:getAppear()
	return self.isAppear;
end

function Actor:getCurrSkillData()
	local skills = {};

	for k,v in pairs(self.skills) do
		local data = v:getBaseData();
		table.insert(skills, #skills+1, data);
	end

	return skills;
end

function Actor:getCurrEquipData()
	local equips = {};

	for k,v in pairs(self.parts) do
		local data = v:getBaseData();
		table.insert(equips, #equips+1, data);
	end

	return equips;
end

function Actor:init(value)
	self:updateBaseAttribute();
    self:setAtb(value);
end

function Actor:updateBaseAttribute()
	local attribute = GetActorLevelAttribute(self.attributeId, self.level);
    self:setLevelAttribute(attribute);

	for _, part in pairs(self.parts) do
		self.attribute:plus(part.attribute);
	end

	--self:setSlashSpeed(self.attribute.slashSpeed);
end

function Actor:setLevelAttribute(value)
    --设置面板属性，玩家可查看的
	self.attribute:ctor();
	self.attribute:init(value);
end

function Actor:setAtb(value)
    --设置基本隐藏属性
    --self.attribute:setSlashSpeed(value.slashSpeed);
	--self.attribute:setCastSpeed(value.castSpeed);
    --self.attribute:setSpeed(value.speed);

	self.slashDelta             = value.slashDelta;    --挥砍间隔
	self.castDelta              = value.castDelta or 0;
    self.moveDelta              = value.moveDelta;     --移动间隔
    self.allowRun               = value.allowRun;      --是否允许奔跑
    self.camp                   = value.camp;          --阵营,不同阵营只能强制PK,并且计算PK值
	self.conf                   = value;

	if self.isNative then
		self.slashClock = Clock:new();
		self.slashClock:setRingTimeDelta(self.slashDelta + 0.2);

		self.moveClock = Clock:new();
		self.moveClock:setRingTimeDelta(self.moveDelta + 0.2);

		self.castClock = Clock:new();
		self.castClock:setRingTimeDelta(self.castDelta + 0.2);
	else
		self.slashClock = Clock:new();
		self.slashClock:setRingTimeDelta(self.slashDelta - 0.2);

		self.moveClock = Clock:new();
		self.moveClock:setRingTimeDelta(self.moveDelta - 0.2);

		self.castClock = Clock:new();
		self.castClock:setRingTimeDelta(self.castDelta - 0.2);
	end
end

function Actor:getProperSkill()
	local skills = self.skills;
	local currSlashSkill = nil;

	for k, v in pairs(skills) do
		local ret,reason = v:satifyCastPremise(self, values);
		if ret then
			if not currSlashSkill then
				currSlashSkill = v;
			elseif currSlashSkill.priority < v.priority then
				currSlashSkill = v;
			end
		end
	end

	if currSlashSkill then
		return currSlashSkill, reason;
	end
end

function Actor:slashSpeedUp(value)
	local speed = self:getSlashSpeed();
	self:setSlashSpeed(speed - value);

	local _clock = self:getSlashClock();
	local delta = _clock:getRingTimeDelta();
	_clock:setRingTimeDelta(delta - value);
end

function Actor:getSlashClock()
	return self.slashClock;
end

function Actor:getMoveClock()
	return self.moveClock();
end

function Actor:update(delta)
    --self:showContactRect();
	for k,v in pairs(self.scripts) do
		if v.update then
			v:update(self);
		end
    end

	for k,v in pairs(self.skills) do
		if v.update then
			v:update(self);
		end
    end
end

function Actor:equip(part, isLeftOrRight)
    local partType = part:getType();
	isLeftOrRight = isLeftOrRight or 0;

	partType = partType + isLeftOrRight;

    if partType > 10 or partType <= 0 then
        print("invalid part "..partType);
        return;  --组件不合�?
    end

    --卸载旧装�?
    local oldPart = self.parts[partType];
    if oldPart then
        self:unEquip(partType);
	else
		oldPart = 1;
    end

	self.parts[partType] = part;
	self.attribute:plus(part.attribute);
    ----更新attribute
    --self:setSlashSpeed(self.attribute.slashSpeed);

    return oldPart;
end

function Actor:unEquip(partType, isLeftOrRight)
	isLeftOrRight = isLeftOrRight or 0;

	partType = partType + isLeftOrRight;

    --self:showContactRect();
	if partType > 10 or partType <= 0 then
        return;  --组件不合�?
    end

	local part = self.parts[partType];

	if not part then
		print("no found "..partType.." type equip");
		return ;
	end
    --计算拿下装备的属�?
    self.attribute:minus(part.attribute);

	--更新attribute
    --self:setSlashSpeed(self.attribute.slashSpeed);

	self.parts[partType] = nil;

    return part;
end

function Actor:getEquip(partType)
	return self.parts[partType];
end

function Actor:updateAttribute()

end

function Actor:useItem(item)

end

function Actor:getIsStand()
	return true;
end

function Actor:addScript(name, script, value)
	if self.scripts[name] then
		self.scripts[name]:stop(self);
	end

	self.scripts[name] = script;

	if script.start then
		script:start(self, value);
	end
end

function Actor:executeScript(name, values)
	--print("1  self.scripts:"..tostring(self.scripts["autofight"]));
	if self.scripts[name] then
		return self.scripts[name]:execute(values, self);
	else
		print("not this scripts:"..name);
	end
end

function Actor:getScriptRunning(name)
	if self.scripts[name] then
		return self.scripts[name]:getRunning();
	end
end

function Actor:setAtkTarget(targetId)
    self.atkTarget = targetId;

	for k,v in pairs(self.atkCallbackFunc) do
		v(targetId);
	end
end

function Actor:regAtkCallbackFunc(func)
	table.insert(self.atkCallbackFunc, #self.atkCallbackFunc+1, func);

	return #self.atkCallbackFunc;
end

function Actor:regDieCallbackFunc(func)
	table.insert(self.dieCallbackFunc, #self.dieCallbackFunc+1, func);

	return #self.dieCallbackFunc;
end

function Actor:unRegDieCallbackFunc(id)
	self.dieCallbackFunc[id] = nil;
end

function Actor:regOffLineCallbackFunc(func)
	table.insert(self.offLineCallbackFunc, #self.offLineCallbackFunc+1, func);

	return #self.offLineCallbackFunc;
end

function Actor:unRegOffLineCallbackFunc(id)
	self.offLineCallbackFunc[id] = nil;
end


function Actor:unRegAtkCallbackFunc(id)
	self.atkCallbackFunc[id] = nil;
end

function Actor:unRegGetDamageCallbackFunc(id)
	self.getDamageCallbackFunc[id] = nil;
end

function Actor:regGetDamageCallbackFunc(func)
	table.insert(self.getDamageCallbackFunc, #self.getDamageCallbackFunc+1, func);
	return #self.getDamageCallbackFunc;
end

function Actor:getAtkTarget()
    return self.atkTarget
end

function Actor:getAtkedBy()
    return self.attackedBy
end

function Actor:getDamage(fromid, num)
    if self.attribute.hp <= 0 then
        return;
    end

	for _,v in pairs(self.skills) do
		if v.getDamage then
			num = v:getDamage(self, num);
		end
	end

    self.attackedBy = fromid;
    self.attribute.hp = self.attribute.hp - num;

    if self.attribute.hp <= 0 then
        self.attribute.hp = 0;

		self:die();
    end

	for k,v in pairs(self.getDamageCallbackFunc) do
		v(fromid, num);
	end

	return num;
end

function Actor:checkMove()
    if self.status == self.statusEnum["walk"] or self.status == self.statusEnum["run"] then
        return true;
    end

    return false;
end

function Actor:stopScripts()
	for k,v in pairs(self.scripts) do
		v:stop(self);
	end
end

function Actor:stopScriptWithName(name)
	local script = self.scripts[name];
	script:stop(self);
end

function Actor:die()
	self.attribute.hp = 0;
	self:closeAction();

	for k,v in pairs(self.dieCallbackFunc) do
		v(self.id);
	end

	GCCenter.sendSameScreenBroadcast(self, {id="BC_ACTOR_DIE", pid=self.id});
end

function Actor:offLine()
	for k,v in pairs(self.offLineCallbackFunc) do
		v(self.id);
	end

	self:closeAction();
end

function Actor:closeAction()
	self:moveOver();

	for k,v in pairs(self.skills) do
		v:close(self);
	end
end

function Actor:revive()
    self.attribute.hp = self.attribute.maxHp
    self.attribute.mp = self.attribute.maxMp
end

function Actor:move(isRun, dir, callFunc)
	if self:isDie() then
		return nil, "dead";
	end

	if not self.moveClock:ring() then
		if self.camp == 1 then
			--LogPrint(self.id.." move delay not cool down:"..self.moveClock:getDelayTime());
		end

		return nil, "move clock cooling down";
	end

	if self.lockBehavior then
		return nil, "lock Behavior";
	end

	if self.isMove then
		if self.camp == 1 then
			--LogPrint(self.id.." move to fast:"..tostringex(self:getPosition()));
		end

		self.moveToFast = true;

		return nil, "move too fast";
	end

	self.isMove = true;

	local ret = nil;
	if isRun == 1 and self.allowRun then
		ret = self:run(dir, callFunc);
	else
		ret = self:walk(dir, callFunc);
	end

	if ret then
		self.moveClock:markRingTime();
	end

	return ret, "move failed";
end

function Actor:walk(dir, callFunc)
	return MoveScript:walk(self, dir, callFunc);
end

function Actor:run(dir, callFunc)
	return MoveScript:run(self, dir, callFunc);
end

function Actor:moveOver()
	self.isMove = nil;

	if self.moveToFast then
		GCCenter.sendSameScreenBroadcast(self, {id="ACTOR_MOVE", pid=self.id, pos=self:getPosition()});
		self.moveToFast = nil;
	end

	if self.moveTimer then
		self.moveTimer:close();
	end
end

--当前位置已经有了对象的时候需要返回原来的位置
function Actor:backLastPosition(curPoint)
    local oppositeDir = (self.dir + 3)%#ActorDir + 1
    local lastPosition = MoveScript:getMovePoint(curPoint, oppositeDir, self.status-1);
    self:setPosition(lastPosition.x, lastPosition.y);
end

function Actor:addSkill(skill)
	if self.skills[skill.name] ~= nil then
        TraceError(skill.name.." already exist");
    end

    self.skills[skill.name] = skill;
end

function Actor:delSkill(skillid)
	local skill = nil;

	for k,v in pairs(self.skills) do
		local baseData = v:getBaseData();
		if baseData.skillid == skillid then
			skill = v;
			self.skills[k] = nil;
			break;
		end
	end

	return skill;
end

function Actor:addItem(item, index)
	if index then
        if not self.items[index] then
            self.items[index] = item;
            return index;
        else
            return;
        end
    end

    for i=1, self.itemCount do
        if self.items[i] == nil then
            self.items[i] = item;
            return i;
        end
    end

    return nil;
end

function Actor:getItemGridIndex(itemId)
	for k,v in pairs(self.items) do
		if v:getID() == itemId then
			return k;
		end
	end
end

function Actor:getNextFreeItemSpace()
	for i=1, self.itemCount do
		if self.items[i] == nil then
			return i;
		end
	end

	return nil;
end

function Actor:getItem(index)
    return self.items[index]
end

function Actor:removeItem(index)
	local item = self.items[index];
    self.items[index] = nil;

	return item;
end

function Actor:getItemCurCount()
	local count = 0;
	for k, v in pairs(self.items) do
		count = count + 1;
	end

    return count;
end

function Actor:getItemMaxCount()
    return self.itemCount;
end

function Actor:cast(name, values)
	if self.isMove then
		return nil, "still moving";
	end

	local skill = self.skills[name]
    if not skill then
        print(name.." no exist");
        return false, "no skill";
    end

    --不符合条件则释放失败
    if skill:satifyCastPremise(self, values) == false then
		--print(self:getID().." cast "..name.." can not satifyCastPremise");
        return false, "not satify premise";
    end

	skill:run(self, values);
	skill:calcConsume(self);

	return true;
end

function Actor:climb()
end

function Actor:lockActorStatus()
    self.lockStatus = true;
end

function Actor:unLockActorStatus()
    self.lockStatus = false;
end

function Actor:getLockBehavior()
    return self.lockBehavior;
end

function Actor:getStyle()
	return self.baseData.style;
end

function Actor:getBusy()
	return self.isBusy;
end

function Actor:setBusy(busy)
	self.isBusy = busy;
end

function Actor:setMap(id)
	if not id then
		self.baseData.worldid = self.map;
	end

    self.map = id;
end

function Actor:getMap()
    return self.map;
end

function Actor:getMp()
	return self.attribute.mp;
end

function Actor:setMp(_mp)
	self.attribute.mp = _mp;
end

function Actor:setClient(id)
	self.clientid = id;
end

function Actor:getClient()
	return self.clientid;
end

function Actor:setSlashSpeed(speed)
    self.attribute.slashSpeed = speed;
end

function Actor:getSlashSpeed()
    return self.attribute.slashSpeed;
end

function Actor:getCastSpeed()
	return self.attribute.castSpeed;
end

function Actor:setName(_name)
    self.name = _name
end

function Actor:getName()
    return self.name;
end

function Actor:setMoney(money)
	self.money = money;
end

function Actor:getMoney()
	return self.money;
end

function Actor:setGold(gold)
	self.gold = gold;
end

function Actor:getGold()
	return self.gold;
end

function Actor:setExc(exc)
	self.exc = exc;
end

function Actor:addExc(exc)
	local newLevel,newExc = getLevelFromExc(self.conf.sz_excConf, self.level, self.exc+exc);
	local isLevelUp = nil;
	local isAddExc = nil;
	if newLevel ~= self.level then
		isLevelUp = true;
	elseif newExc ~= self.exc then
		isAddExc = true;
	end

	self.level = newLevel;
	self.exc = newExc;

	if isLevelUp then
		self:levelUp();

		return 1;
	elseif isAddExc then
		return 1;
	end
end

function Actor:getExc()
	return self.exc;
end

function Actor:getPosition()
	return {x=self.x,y=self.y}
end

function Actor:setPosition(_x, _y)
    self.x = _x
    self.y = _y
end

function Actor:setType(type)
    self.type = type;
end

function Actor:isDie()
    return self.attribute.hp <= 0;
end

function Actor:markSlashRingTime()
    self.slashClock:markRingTime();
end

function Actor:markCastRingTime()
	self.castClock:markRingTime();
end

function Actor:checkSlashClockRing()
    return self.slashClock:ring();
end

function Actor:checkCastClockRing()
    return self.castClock:ring();
end

function Actor:levelUp()
	self:updateBaseAttribute();

	--engine.dispachEvent("ACTOR_LEVEL_UP", self.id);
end

function Actor:addMonitor(pid)
	if type(pid) == "number" then
		self.monitorList[pid] = 1;
	elseif type(pid) == "table" then
		for k,v in pairs(pid) do
			self:addMonitor(v:getID());
		end
	end

	--print(tostringex(self.monitorList).."  name:"..self.name.."     debug:"..debug.traceback());
end

function Actor:delMonitor(pid)
	self.monitorList[pid] = nil;
end

function Actor:getMonitor()
	return self.monitorList;
end

function Actor:hasMonitor(pid)
	return self.monitorList[pid];
end

function Actor:clearMonitor()
	self.monitorList = {};
end

---------------------------------------------------------------
-----
-----            set   get   function
-----
---------------------------------------------------------------
function Actor:setCamp(_camp)
    self.camp = _camp
end

function Actor:getCamp()
    return self.camp
end

function Actor:setLevel(_level)
    self.level = _level
end

function Actor:setSex(_sex)
    self.sex = _sex
end

function Actor:getSex()
    return self.sex
end

function Actor:getLevel()
    return self.level;
end

function Actor:getSlashRange()
	local skill = self.skills["slash"];

	if skill then
		return skill:getCastRange();
	end

    return -1;
end

function Actor:getSpeed(type)
    return self.attribute.speed[type]
end

function Actor:setAllowRun(_allowRun)
    self.allowRun = _allowRun;
end

function Actor:getAllowRun()
    return self.allowRun;
end

function Actor:getID()
    return self.id;
end

function Actor:setID(id)
    self.id = id;
end

function Actor:getAttribute()
    return self.attribute;
end

function Actor:getHp()
	return self.attribute.hp;
end

function Actor:addHp(hp)
	self.attribute.hp = (self.attribute.hp + hp);

	if self.attribute.hp > self.attribute.maxHp then
		self.attribute.hp = self.attribute.maxHp;
	end
end

function Actor:addMp(mp)
	self.attribute.mp = (self.attribute.mp +mp);

	if self.attribute.mp > self.attribute.maxMp then
		self.attribute.mp = self.attribute.maxMp;
	end
end

function Actor:setAttributeId(_attributeId)
	self.attributeId = _attributeId;
end

function Actor:setAlertArea(_area)
	self.alertArea = _area;
end

function Actor:getAlertArea()
	return self.alertArea;
end

function Actor:getDir()
	return self.dir;
end

function Actor:getAttributeId()
	return self.attributeId;
end

function Actor:getMoveDelta()
    return self.moveDelta;
end

function Actor:getRandomAttack(type)
    local ATKParam = self.attribute.atk[type];
    local randomAttack = FuncPack:getRandomNumber(ATKParam[1], ATKParam[2]);

    return randomAttack;
end

function Actor:getRandomDefense(type)
    return self.attribute.dfs[type] or 0;
end
