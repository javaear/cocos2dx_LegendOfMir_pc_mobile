AutoFight = {}
AutoFight.__index = AutoFight
AutoFight.logSwitch = nil;

function AutoFight:create()
    local script = {}
    setmetatable(script, AutoFight)
    script:ctor();
    return script
end

function AutoFight:ctor()
    self.targetID = -1;
    self.auto = false;
	self.keepStandTimer = TimerManager:getLongTimer();
	self.keepStandTimer:setSleep(true);
	self.slashRange = 0;
end

function AutoFight:getRunning()
    if self.targetID <= 0 then
        return nil;
    end

    return true;
end

function AutoFight:execute(value, master)
	if master:getID() == value then
		return;
	end

    self.targetID = value;

	return value;
end

function AutoFight:stop(object)
	TraceError(object:getID().." auto fight over:");
    self:ctor();

	self.keepStandTimer:scheduleOnce(10, function()
		object:climb();
	end);
end


function AutoFight:update(object)
    if self.targetID == -1  then
        return;
    end

	self.keepStandTimer:close();

	local enemy = ActorManager:getActor(self.targetID);
	if not enemy or enemy:isDie() or object:isDie() or object:getID() == self.targetID then
		self:stop(object);
		return;
	end
	--[[
	if object:getScriptRunning("findpath") then
		--print("is running");
		return;
	end]]

	if not GCCenter.checkCanSee(object:getID(), self.targetID) then
		TraceError("object:getID() can not see"..self.targetID);
		self:stop(object);
		return;
	end

	if not object:getIsStand() then
		object:stand();

		return;
	end

    --根据距离判断是移动还是进�?
    local enemyPos     = enemy:getPosition();
    local objectPos    = object:getPosition();
    local distance     = FuncPack:getStepBetweenPos(enemyPos, objectPos);
    local skill        = object:getProperSkill();

	if skill then
		self.slashRange = skill:getCastRange();
	end

	if self.slashRange == 0 then
		return;
	end

    if distance > self.slashRange or distance == 0 then
		local ret = object:executeScript("findpath", enemyPos);
    elseif distance <= self.slashRange then
		if skill then
			local skillType = skill:getType();

			if skillType == 1 then
				local dir = FuncPack:calcuteDirFromPoint(objectPos, enemyPos);
				object:cast(skill:getName(), dir);
			else
				local point = FuncPack:PositionTopoint(enemyPos);
				object:cast(skill:getName(), enemyPos);
			end
		end
    end
end

function AutoFight:getRunning(object)
	if self.targetID == -1 then
		return false;
	else
		return true;
	end
end

function AutoFight:die()
    self:stop();
end

function AutoFight:checkNoFight()
    return self.auto == false and self.targetID == -1
end

function AutoFight:checkEnemyMove(enemyPos)
    return FuncPack:isEqualPoint(self.lastEnemyPos, enemyPos) == false
end

function AutoFight:registMoveListener(object)
    if self.moveListener then
        return;
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();

    --对象移动的时候监�?
    local AutoFightMove = function(event)
        if event.info.id == self.targetID then
            self:startFight(object);
        end
    end

    self.moveLister = cc.EventListenerCustom:create("move", AutoFightMove)
    eventDispatcher:addEventListenerWithFixedPriority(self.moveLister, 1);
end

function AutoFight:registDieListener(object)
    if self.dieLister then
        return
    end

    --有对象死亡的监听�?
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();

    local AutoFightDie = function(event)
        if event.info.id == self.targetID then
            self:die();
        end
    end

    self.dieLister = cc.EventListenerCustom:create("die", AutoFightDie)
    eventDispatcher:addEventListenerWithFixedPriority(self.dieLister, 1)
end

function AutoFight:removeMoveListener()
    if not self.moveListener then
        return
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:removeEventListener(self.moveListener);
    self.moveListener = nil;
end

function AutoFight:removeDieListener()
    if not self.dieListener then
        return
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:removeEventListener(self.dieListener);
    self.dieListener = nil;
end
