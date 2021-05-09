AutoFightWithMonster = {}
AutoFightWithMonster.__index = AutoFightWithMonster

function AutoFightWithMonster:create()
    local script = {}
    setmetatable(script, AutoFightWithMonster)
    script:ctor();
    return script
end

function AutoFightWithMonster:ctor()
    self.targetID = -1;
    self.auto = false;
	self.slashRange = 1;
end

function AutoFightWithMonster:getRunning()
    if self.targetID <= 0 then
        return nil;
    end

    return true;
end

function AutoFightWithMonster:execute(value, master)
    self.targetID = value;
    self.enemyPosOfMap = nil;
    --娣诲姞鐩戝惉鍣?
    --self:registMoveListener(master);
    --self:registDieListener(master);
end

function AutoFightWithMonster:stop(object)
	TraceError(object:getID().." auto fight over:"..debug.traceback());
    self:ctor();
    --self:removeDieListener();
    --self:removeMoveListener();
end

function AutoFightWithMonster:update(object)
	LogPrint("adadsawdwdwqd");
    if self.targetID == -1  then
        return;
    end

	if not GCCenter.checkCanSee(object:getID(), self.targetID) then
		TraceError("object:getID() 无法看见"..self.targetID.." 放弃");
		self:stop(object);
		return;
	end

    --鏍规嵁璺濈鍒ゆ柇鏄Щ鍔ㄨ繕鏄繘鏀?
	local enemy        = ActorManager:getActor(self.targetID);
    local enemyPos     = enemy:getPosition();
    local objectPos    = object:getPosition();
    local distance     = FuncPack:getStepBetweenPos(enemyPos, objectPos);
	local skill,reason = object:getProperSkill();

	if skill then
		self.slashRange   = skill:getCastRange();
	else
		print("reason:"..tostringex(reason));
	end

    if distance > self.slashRange or distance == 0 then
		local ret = object:executeScript("findpath", enemyPos);

		if ret then
			TraceError(object:getID().." 对敌人"..self.targetID.." 成功寻路");
		end
    elseif distance <= self.slashRange then
		if skill then
			local dir = FuncPack:calcuteDirFromPoint(objectPos, enemyPos);
			local ret,reason = object:cast(skill:getName(), dir);

			if ret then
				TraceError(object:getID().." 对敌人 "..self.targetID.." 成功攻击");
			else
				print(reason);
			end
		end
    end
end

function AutoFightWithMonster:getRunning(object)
	if self.targetID == -1 then
		return false;
	else
		return true;
	end
end

function AutoFightWithMonster:die()
    self:stop();
end

function AutoFightWithMonster:checkNoFight()
    return self.auto == false and self.targetID == -1
end

function AutoFightWithMonster:checkEnemyMove(enemyPos)
    return FuncPack:isEqualPoint(self.lastEnemyPos, enemyPos) == false
end

function AutoFightWithMonster:registMoveListener(object)
    if self.moveListener then
        return;
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();

    --瀵硅薄绉诲姩鐨勬椂鍊欑洃鍚?
    local AutoFightMove = function(event)
        if event.info.id == self.targetID then
            self:startFight(object);
        end
    end

    self.moveLister = cc.EventListenerCustom:create("move", AutoFightMove)
    eventDispatcher:addEventListenerWithFixedPriority(self.moveLister, 1);
end

function AutoFightWithMonster:registDieListener(object)
    if self.dieLister then
        return
    end

    --鏈夊璞℃浜＄殑鐩戝惉鍣?
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();

    local AutoFightDie = function(event)
        if event.info.id == self.targetID then
            self:die();
        end
    end

    self.dieLister = cc.EventListenerCustom:create("die", AutoFightDie)
    eventDispatcher:addEventListenerWithFixedPriority(self.dieLister, 1)
end

function AutoFightWithMonster:removeMoveListener()
    if not self.moveListener then
        return
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:removeEventListener(self.moveListener);
    self.moveListener = nil;
end

function AutoFightWithMonster:removeDieListener()
    if not self.dieListener then
        return
    end

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:removeEventListener(self.dieListener);
    self.dieListener = nil;
end
