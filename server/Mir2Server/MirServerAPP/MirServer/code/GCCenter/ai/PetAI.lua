PetAI = class("PetAI")

function PetAI:ctor()
	self.farestDis = 2;
	self.flashDis = 15;
	self.aiName = "PetAI";
end

function PetAI:start(object, master)
	object:setCamp(master:getCamp());
	object:setName(object:getName().."("..master:getName()..")");

	self.getDamageFuncId = master:regGetDamageCallbackFunc(function(fromid, num)
		if not object:getAppear() then
			return;
		end

		if not object:getScriptRunning("autofight") then
			local ret = object:executeScript("autofight", fromid);
		end
	end)

	self.selfGetDamageFuncId = object:regGetDamageCallbackFunc(function(fromid, num)
		if not object:getAppear() then
			return;
		end

		if not object:getScriptRunning("autofight") then
			local ret = object:executeScript("autofight", fromid);
		end
	end)

	self.atkFuncId = master:regAtkCallbackFunc(function(targetid)
		if not object:getAppear() then
			return;
		end

		if not object:getScriptRunning("autofight") then
			local ret = object:executeScript("autofight", targetid);
		end
	end);

	self.dieFuncId = master:regDieCallbackFunc(function()
		if not object:getAppear() then
			return;
		end

		print("master die:");
		object:die();
		self:stop(object);
	end)

	self.selfDieFuncId = object:regDieCallbackFunc(function()
		if not object:getAppear() then
			return;
		end

		TraceError("pet die:");
		self:stop(object);
	end)

	self.offLineFuncId = master:regOffLineCallbackFunc(function(targetid)
		object:die();
		self:stop(object);
	end);

	self.timer = TimerManager:getLongTimer();

	local moveSpeed = object:getAttribute().speed[1];
	self.timer:schedule(moveSpeed + 0.1, function()
		if not object:getAppear() then
			return;
		end

		if not object:getScriptRunning("autofight") then
			local objPos = object:getPosition();
			local mstPos = master:getPosition();

			if object:getMap() ~= master:getMap() then
				local map = MapManager:getMap(master:getMap());
				Game.changeMap(object:getID(), master:getMap(), mstPos);
			else
				local dist = FuncPack:getStepBetweenPos(objPos, mstPos);
				if dist >= self.flashDis then
					Game.changeMap(object:getID(), master:getMap(), mstPos);
					object:stopScriptWithName("findpath");
					object:stopScriptWithName("autofight");
				elseif dist >= self.farestDis then
					object:executeScript("findpath", mstPos);
				end
			end
		end
	end, 123)

	object:setMasterId(master:getID());
	self.masterId = master:getID();
end

function PetAI:update(object)
end

function PetAI:stop(object)
	if object:getScriptRunning("autofight") then
		object:stopScriptWithName("autofight");
	end

	if object:getScriptRunning("findpath") then
		object:stopScriptWithName("findpath");
	end

	local master = ActorManager:getActor(self.masterId);
	if master then
		master:unRegDieCallbackFunc(self.dieFuncId);
		master:unRegAtkCallbackFunc(self.atkFuncId);
		master:unRegGetDamageCallbackFunc(self.getDamageFuncId);
		master:unRegOffLineCallbackFunc(self.offLineFuncId);
	end

	object:unRegDieCallbackFunc(self.selfDieFuncId);
	object:unRegGetDamageCallbackFunc(self.selfGetDamageFuncId);

	if self.timer then
		self.timer:close();
	end
end
