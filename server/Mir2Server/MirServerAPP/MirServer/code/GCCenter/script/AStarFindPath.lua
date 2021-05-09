AStarFindPath = {}

local open_list = {}
local open_list_index = {}
local close_list = {}
local map = nil
local toPoint = nil
local fromPoint = nil
local findLog = "";

function AStarFindPath:getAStarPath(to, from, _map, maxStep)
	if not to or not from or not _map then
		--TraceError("AStarFindPath:getAStarPath NULL parameter : "..debug.traceback());
		return;
	end

    local list = self:aStarFindPath(to, from, _map);
    local path = {}

    if list == nil then
        return nil
    end

    while list ~= nil do
        table.insert(path, #path+1, {x=list.x, y=list.y});
        list = list.parent;
    end

    table.insert(path, 1, {x=to.x, y=to.y});
    path[#path] = nil;

    if maxStep ~= nil then
        path = self:OptimalPath(path, maxStep);
    end
    --local newPath =
	if not path then
		print("find path failed, find log:"..tostringex(findLog));
	end

    return path;
end

--优化路径
function AStarFindPath:OptimalPath(path, step)  --step表示可以连续的最大步数
    local newPath = {}
    local lastPointIndex = 1

    for k,v in pairs(path) do
        if k == #path then
            break;
        end

        if k ~= 1 then
            local nextLine = {x=path[k+1].x-v.x, y=path[k+1].y-v.y}
            local lastLine = {x=v.x-path[k-1].x, y=v.y-path[k-1].y}

            --当前点的下一个线段和上一个线段不是同一直线则换方向
            if nextLine.x*lastLine.y ~= nextLine.y*lastLine.x or k - lastPointIndex >= step then  --或者已经走了最大步数
                table.insert(newPath, #newPath+1, v)

                lastPointIndex = k;
            end
        end
    end

    table.insert(newPath, 1, path[1])
    table.insert(newPath, #newPath+1, path[#path])

    return newPath;
end

function AStarFindPath:initList()
    open_list = {};
    open_list_index = {};
    close_list = {};
	findLog = "";
end

function AStarFindPath:aStarFindPath(to, from, _map)
    toPoint = to;
    fromPoint = from;
    map = _map;

    self:initList();

    from.g = 0;
    from.h = self:getHValue(from, to);
    self:signValidOfPoint(from, true);

	findLog = findLog.."from point("..from.x..","..from.x..")  to point("..to.x..","..to.y..")";

    local pathList = ni;
    while self:arrive(open_list[1], to) == false do
        --更新初始点附近的节点
        --print(open_list[1].x.."---"..open_list[1].y);
        self:getNextPoint(open_list[1], to);

        --删除已经检测的节点
        self:signValidOfPoint(open_list[1], false);findLog = findLog.."find point("..open_list[1].x..","..")";
        table.remove(open_list, 1)


        --排序
        open_list = self:sort(open_list);

        --更新open_list_index和open_list对应值:
        --open_list_index的主要作用是不需要每一个点计算的时候都遍历开放队列
        open_list_index = {};
        for k, v in pairs(open_list) do
            --关闭列表里有该点
            local index = v.x + v.y*map.mapSize.width;
            open_list_index[index] = k;
        end

        if #open_list < 1 then
            return nil;
        end
    end

    return open_list[1];
end

function AStarFindPath:arrive(pos1, pos2, step)
    local minStep = step or 2;
    local distance = FuncPack:getDistanceWithOfPositions(pos1, pos2)

    if distance < minStep then
        return true;
    end

    return false;
end

function AStarFindPath:getNextPoint(from, to)
    local upPoint = {x=from.x, y=from.y+1, parent=from}
    local upRightPoint = {x=from.x+1, y=from.y+1, parent=from}
    local rightPoint = {x=from.x+1, y=from.y, parent=from}
    local rightDownPoint = {x=from.x+1, y=from.y-1, parent=from}
    local downPoint = {x=from.x, y=from.y-1, parent=from}
    local downLeftPoint = {x=from.x-1, y=from.y-1, parent=from}
    local leftPoint = {x=from.x-1, y=from.y, parent=from}
    local leftUpPoint = {x=from.x-1, y=from.y+1, parent=from}

    upPoint.h = self:getHValue(upPoint, to);
    upRightPoint.h = self:getHValue(upRightPoint, to);
    rightPoint.h = self:getHValue(rightPoint, to);
    rightDownPoint.h = self:getHValue(rightDownPoint, to);
    downPoint.h = self:getHValue(downPoint, to);
    downLeftPoint.h = self:getHValue(downLeftPoint, to);
    leftPoint.h = self:getHValue(leftPoint, to);
    leftUpPoint.h = self:getHValue(leftUpPoint, to);

    upPoint.g = from.g + self:getHValue(upPoint, from);
    upRightPoint.g = from.g + self:getHValue(upRightPoint, from);
    rightPoint.g = from.g + self:getHValue(rightPoint, from);
    rightDownPoint.g = from.g + self:getHValue(rightDownPoint, from);
    downPoint.g = from.g + self:getHValue(downPoint, from);
    downLeftPoint.g = from.g + self:getHValue(downLeftPoint, from);
    leftPoint.g = from.g + self:getHValue(leftPoint, from);
    leftUpPoint.g = from.g + self:getHValue(leftUpPoint, from);

    self:analysePoint(upPoint)
    self:analysePoint(upRightPoint)
    self:analysePoint(rightPoint)
    self:analysePoint(rightDownPoint)
    self:analysePoint(downPoint)
    self:analysePoint(downLeftPoint)
    self:analysePoint(leftPoint)
    self:analysePoint(leftUpPoint)
end

function AStarFindPath:sort(list)
    table.sort(list, compare)
    return list;
end

function AStarFindPath:analysePoint(point)
    if point.x == 15 and point.y == 8 then
        local abc = 20;
    end

    if self:checkValidOfPoint(point) == false then
        self:signValidOfPoint(point, false);
    else
        self:signValidOfPoint(point, true);
    end
end

function AStarFindPath:checkValidOfPoint(point)
    local mapSize = map.mapSize;
    local index = point.x + point.y*mapSize.width;

    if point.x > mapSize.width or point.y > mapSize.height then
        return false;
    end

    --是否有障碍物
    if map:hasObstacle(point) then
        return false;
    end

    --超过起终点的矩形搜索范围
    local range = 6;
    if point.x < math.min(toPoint.x, fromPoint.x)-range or point.x > math.max(toPoint.x, fromPoint.x)+range or
        point.y < math.min(toPoint.y, fromPoint.y)-range or point.y > math.max(toPoint.y, fromPoint.y)+range then
        return false;
    end

    --已经在关闭列表里面
    if close_list[index] == 1 then
        return false;
    end

    --该点已经出现过
    if open_list_index[index] ~= nil then
        local pointIndex = open_list_index[index];
        local oldPoint = open_list[pointIndex];

        --如果新的路程比老的少则替换
        if oldPoint.g > point.g then
            open_list[pointIndex] = point;
        end

        return false;
    end

    return true;
end

function AStarFindPath:getGValue(from, to)
    local distancex = math.abs(from.x - to.x)
    local distancey = math.abs(from.y - to.y)
end

function AStarFindPath:getHValue(from, to)
    local distancex = math.abs(from.x - to.x)
    local distancey = math.abs(from.y - to.y)

    if distancex == 0 or distancey == 0 then
        return distancex + distancey;
    else
        if distancex > distancey then
            return distancex - distancey + distancey*1.4;
        else
            return distancey - distancex + distancex*1.4;
        end
    end
end

function AStarFindPath:signValidOfPoint(point, isValid)
    local mapSize = map.mapSize;
    local index = point.x + point.y*mapSize.width;

    if isValid == true then
        table.insert(open_list, #open_list+1, point);
        open_list_index[index] = #open_list;
    else
        close_list[index] = 1;
    end
end

function compare(p1, p2)
    return p1.h < p2.h
end
