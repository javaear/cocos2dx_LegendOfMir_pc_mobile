MonsterBaseAI = class("MonsterBaseAI")

function MonsterBaseAI:ctor()
    self.freeClock = Clock:new();
    self.freeClock:setRingTimeDelta(5);

	self.workClock = Clock:new();
    self.workClock:setRingTimeDelta(5);

	self.aiName = "MonsterBaseAI";
end

function MonsterBaseAI:giveUpEnemy(object)
    --object:stopScriptWithName("autofight");
	object:stopScripts();
    self.enemyid = nil;
end

function MonsterBaseAI:fight(master, enemy)
    local enemyCamp = enemy:getCamp();
    local masterCamp = master:getCamp();

    if masterCamp ~= enemyCamp then
        local masterPos = master:getPositionOfMap();
        local enemyPos = enemy:getPositionOfMap();
        local distance = FuncPack:getDistanceWithOfPositions(masterPos,enemyPos)

        if distance <= self.maxAlertTile then
            master:executeScript("autofight", enemy.id);
            self.enemyid = enemy.id;
            return true;
        end
    end

    return false;
end

function MonsterBaseAI:update(object)
	if not object:getAppear() then
		return;
	end

	if not self.enemyid then
		if self:checkFreeClock()  then
			self:execute(object);
		end

	else
		if self:checkEnemyIsValid(object) == false and
			self:checkWorkClock() then
			self:giveUpEnemy(object);
		end

		if not object:getScriptRunning("autofight") then
			self.enemyid = nil;
		end
	end
end

function MonsterBaseAI:execute(object)
	if self:findEnemy(object) then
		return;
	end
end

function MonsterBaseAI:findEnemy(object)
	local objectid = object:getID();
    local actorList = GCCenter.getCanSeeEnemys(objectid)

    for k,actor in pairs(actorList) do
		local enemyid    = actor:getID();
		local enemyCamp  = actor:getCamp();
		local objectCamp = object:getCamp();

		if enemyid ~= objectid and objectCamp ~= enemyCamp then
			self.enemyid = enemyid;
			object:executeScript("autofight", enemyid);
		end
    end
end

function MonsterBaseAI:checkFreeClock()
    if self.freeClock:ring() == false then
        return nil;
    end

    self.freeClock:markRingTime();

    return true;
end

function MonsterBaseAI:checkWorkClock()
    if self.workClock:ring() == false then
        return nil;
    end

    self.workClock:markRingTime();

    return true;
end

function MonsterBaseAI:stop(object)
	if object:getScriptRunning("autofight") then
		object:stopScriptWithName("autofight");
	end
end

function MonsterBaseAI:checkEnemyIsValid(object)
    local enemy = ActorManager:getActor(self.enemyid)

    if not enemy then
        return false;
    end

	if enemy:isDie() then
		return false;
	end

	if not GCCenter.checkCanSee(object:getID(), self.enemyid) then
		return false;
	end

    return true;
end

