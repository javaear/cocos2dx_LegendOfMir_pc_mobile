AutoFindPathEx = {}
AutoFindPathEx.__index = AutoFindPathEx
AutoFindPathEx.logSwitch = nil;

function AutoFindPathEx:create()
    local script = {}
    setmetatable(script, AutoFindPathEx)
    script:ctor();
    return script;
end

function AutoFindPathEx:ctor()
    self.tarPoint = {x=-1,y=-1};
    self.curPathID = 1;
    self.AutoFindPathEx = nil;
    self.path = nil;
    self.excCount = 0;
	self.isCannotFindPath = nil;

	if not self.moveClock then
		self.moveClock = Clock:new();
	end
end

--初始化自动寻路基本信息
function AutoFindPathEx:execute(values, master)
    if not values then
        self:stop();
        return;
    end

	if not self.AutoFindPathEx then
		self:countPath(master:getPosition(), values, master);
	end
end

function AutoFindPathEx:countPath(fromPos, newPos, object)
	local dir = FuncPack:calcuteDirFromPoint(fromPos, newPos);
	local mapid = object:getMap();
	local map = MapManager:getMap(mapid);

	local posList = {};
	for i=1,8 do
		local pos = FuncPack:nextPositionWithDir(fromPos, i, 1);

		if not map:hasObstacle(pos) then
			table.insert(posList, #posList+1, pos);
		end
	end

	local nearestDis = nil;
	local nearestPos = nil;
	for k,v in pairs(posList) do
		local dis = FuncPack:getDistanceWithOfPositions(v, newPos);
		if not nearestDis or (nearestDis > dis) then
			nearestDis = dis;
			nearestPos = v;
		end
	end

	if nearestPos then
		local ret = self:moveToPath(object, nearestPos, function(success)
			self.AutoFindPathEx = nil;
		end);
	end
end

function AutoFindPathEx:initPath(sourPos, tarPos, map)
    local path = self:getAStarPath(sourPos, tarPos, map);

    --if self.path == nil then

    --end

    return path;
end

function AutoFindPathEx:stop()
    self:ctor();
end

function AutoFindPathEx:update(object)
	--[[
    if self.AutoFindPathEx ~= nil then
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
			self.AutoFindPathEx = nil;
			self:countPath(finalTarPos);
			return;
		end

		--开始寻路
		local ret = self:moveToPath(object, tarPoint, function(success)
			if success then
				self.curPathID = self.curPathID + 1;
			else
				local finalTarPos = self.path[#self.path];
				self.AutoFindPathEx = nil;
				self:countPath(finalTarPos);
			end
		end);
    end
	]]
end

function AutoFindPathEx:moveToPath(object, tarPoint, callfunc)
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

	return ret;
end

function AutoFindPathEx:over(object, isCannotFindPath)
    self.AutoFindPathEx = nil;
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

function AutoFindPathEx:getRunning()
	return self.AutoFindPathEx;
end

--获取路径
function AutoFindPathEx:getAStarPath(objPos, tarPos, map)
    --判断是否运行跑步
    local step = nil;
    if self.master:getAllowRun() then
        step = 2;
    end

    local path = AStarFindPath:getAStarPath(objPos, tarPos, map, step) --path get
    return path;
end
