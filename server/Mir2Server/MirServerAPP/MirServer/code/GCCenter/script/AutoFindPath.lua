AutoFindPath = {}
AutoFindPath.__index = AutoFindPath
AutoFindPath.logSwitch = nil;

function AutoFindPath:create()
    local script = {}
    setmetatable(script, AutoFindPath)
    script:ctor();
    return script;
end

function AutoFindPath:ctor()
    self.tarPoint = {x=-1,y=-1};
    self.curPathID = 1;
    self.autoFindPath = nil;
    self.path = nil;
    self.excCount = 0;
	self.isCannotFindPath = nil;

	if not self.moveClock then
		self.moveClock = Clock:new();
	end
end

--初始化自动寻路基本信息
function AutoFindPath:execute(values, master)
    if not values then
        self:stop();
        return;
    end

	if self.isCannotFindPath then
		return;
	end

    self.master = master;
	self.map = MapManager:getMap(self.master:getMap());

	if FuncPack:isEqualPoint(self.tarPos, values) == false then
		self.tarPos = values;

		return self:countPath(values);
	end
end

function AutoFindPath:countPath(newPos)
	if not newPos then
		self:over(self.master);
		return;
	end

    if self.autoFindPath == nil then
        local fromPos = self.master:getPosition();
        self.path = self:initPath(fromPos, newPos, self.map);

        if self.path then
            --object锁定状态
            self.autoFindPath = 1;
			self.curPathID = 1;

			return 1;
        else
            self:over(self.master, true);
			TraceError(self.master:getID().." find path failed, maybe the distance between 2 points is too long");
			--TraceError("hahahahahahhahahahhaha");
        end
    else
        --找寻最优路径
        local shortestDistance = nil;
        local shortestDistancePos = nil;
        local shortestDistanceId = -1;
		local targetPos = newPos;
        for i=self.curPathID+1, #self.path do
            local tarPos   = self.path[i];
            local distance = FuncPack:getDistanceWithOfPositions(tarPos, targetPos)

            --新路径更优
            if not shortestDistance or distance < shortestDistance then
                shortestDistance = distance;
                shortestDistancePos = tarPos;
                shortestDistanceId = i;
            else
                self.path[i] = nil;
            end
        end

        --合并新老路径
        local newPath = self:initPath(shortestDistancePos, targetPos)
        if newPath == nil then
            self:over(self.master, true);
			TraceError(self.master:getID().." find new path failed, maybe the distance between 2 points is too long");
            return;
        end

        for i=1, #newPath do
            self.path[shortestDistanceId+i] = newPath[i];
        end

		return 1;
    end
end

function AutoFindPath:initPath(sourPos, tarPos, map)
    local path = self:getAStarPath(sourPos, tarPos, map);

    --if self.path == nil then

    --end

    return path;
end

function AutoFindPath:stop()
    self:ctor();
end

function AutoFindPath:update(object)
    if self.autoFindPath ~= nil then
        --是否开始移动
        if object.isMove then
            return;
        end

        --开始自动寻路，第一步生成寻路路径
        local objPoint = object:getPosition();
        local tarPoint = self.path[self.curPathID];  --根据生成的寻路路径得出开始点和结束点

            --到头了结束寻路
		if tarPoint == nil then
			self:over(object);
			return;
		end

		if FuncPack:isEqualPoint(objPoint, tarPoint) then
			self.curPathID = self.curPathID + 1;
			return;
		end

		--遇到障碍物重新计算路径
		local map = MapManager:getMap(object:getMap());
		if map:hasObstacle(tarPoint) then
			local finalTarPos = self.tarPos;
			self.autoFindPath = nil;
			self:countPath(finalTarPos);
			return;
		end

		--开始寻路
		local ret = self:moveToPath(object, tarPoint, function(success)
			if success then
				self.curPathID = self.curPathID + 1;
			else
				local finalTarPos = self.path[#self.path];
				self.autoFindPath = nil;
				self:countPath(finalTarPos);
			end
		end);
    end
end

function AutoFindPath:moveToPath(object, tarPoint, callfunc)
    local objPoint = object:getPosition();   --角色坐标

    --计算方向并移动目标对象
    local dir = FuncPack:calcuteDirFromPoint(objPoint, tarPoint)
    local step = FuncPack:getDistanceWithOPoints(objPoint, tarPoint)
	local isRun = nil;
    if step >= 2 and object:getAllowRun() then
        isRun = 1;
    else
        isRun = 0;
    end

	local oldPos = object:getPosition();
    local ret = object:move(isRun, dir, callfunc);

	if ret then
		GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_MOVE", pid=object:getID(), isRun=isRun, dir=dir,pos=oldPos});
	end
end

function AutoFindPath:over(object, isCannotFindPath)
    self.autoFindPath = nil;
    self.curPathID = 1;
	object.isMove = nil;
	self.tarPos = {x=-1,y=-1};

	if isCannotFindPath then
		self.isCannotFindPath = isCannotFindPath;
		TimerManager:getTimer():scheduleOnce(5, function()
			self.isCannotFindPath = nil;
		end);
	end

	LogPrint("auto findpath over:");
end

function AutoFindPath:getRunning()
	return self.autoFindPath;
end

--获取路径
function AutoFindPath:getAStarPath(objPos, tarPos, map)
    --判断是否运行跑步
    local step = nil;
    if self.master:getAllowRun() then
        step = 2;
    end

    local path = AStarFindPath:getAStarPath(objPos, tarPos, map, step) --path get
    return path;
end
