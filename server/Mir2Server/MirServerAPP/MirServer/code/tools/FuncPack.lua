FuncPack = {}
FuncPack.pi = 3.1415926

function FuncPack:IsCircleIntersectLineSeg(x, y, r, x1, y1, x2, y2)
    local vx1 = x - x1;
    local vy1 = y - y1;
    local vx2 = x2 - x1;
    local vy2 = y2 - y1;

    -- len = v2.length()
    local len = math.sqrt(vx2 * vx2 + vy2 * vy2);

    -- v2.normalize()
    local vx2 = vx2/len;
    local vy2 = vx2/len;

    -- u = v1.dot(v2)
    -- u is the vector projection length of vector v1 onto vector v2.
    local u = vx1 * vx2 + vy1 * vy2;

    -- determine the nearest point on the lineseg
    local x0 = 0.0;
    local y0 = 0.0;
    if u <= 0 then
        -- p is on the left of p1, so p1 is the nearest point on lineseg
        x0 = x1;
        y0 = y1;
    elseif u >= len then
        -- p is on the right of p2, so p2 is the nearest point on lineseg
        x0 = x2;
        y0 = y2;
    else
        -- p0 = p1 + v2 * u
        -- note that v2 is already normalized.
        x0 = x1 + vx2 * u;
        y0 = y1 + vy2 * u;
    end

    return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r;
end

function FuncPack:caluateLineAngleX(p1, p2)
    local vx2 = p2.x - p1.x;
    local vy2 = p2.y - p1.y;
    local xLen = p2.x - p1.x;
    local yLen = p2.y - p1.y;
    local arc = math.atan2(yLen,xLen);

    if arc < 0 then
        arc = FuncPack.pi + arc;
    end

    return arc;
end

function FuncPack:parseLineAngleEx(p1, p2)
    local shootVector = {x = p2.x - p1.x, y = p2.y - p1.y}
    --向量标准化(即向量长度为1)
    local normalizedVector = cc.pNormalize(shootVector) ;
    --算出旋转的弧度
    local radians = math.atan2(normalizedVector.y, -normalizedVector.x);
    --将弧度转换成角度
    local degree = radians / FuncPack.pi * 180;

    return degree;
end

function FuncPack:cacluteDir(angle)
    local empty = 23;
    local step = 45;
    local dir = 1;

    if angle < -empty + step and angle >= -empty then
        dir = 3;
    elseif angle < -empty  and angle >= -empty - step then
        dir = 2;
    elseif angle < -empty - step and angle >= -empty - 2*step then
        dir = 1;
    elseif angle < -empty - 2*step and angle >= -empty - 3*step then  ---23-90 -135-23
        dir = 8;
    elseif angle < -empty - 3*step or angle >= empty + 3*step then
        dir = 7;
    elseif angle < empty + 3*step and angle >= empty + 2*step then
        dir = 6;
    elseif angle < empty + 2*step and angle >= empty + step then
        dir = 5;
    elseif angle < empty + step and angle >= empty then
        dir = 4;
    end

    return dir;
end

function FuncPack:calcuteDirFromPoint(from, to)
    local distancex = to.x - from.x
    local distancey = to.y - from.y

    if distancey > 0 and distancex == 0 then
        return 1
    elseif distancey > 0 and distancex > 0 then
        return 2
    elseif distancey == 0 and distancex > 0 then
        return 3
    elseif distancey < 0 and distancex > 0 then
        return 4
    elseif distancey < 0 and distancex == 0 then
        return 5
    elseif distancey < 0 and distancex < 0 then
        return 6
    elseif distancey == 0 and distancex < 0 then
        return 7
    elseif distancey > 0 and distancex < 0 then
        return 8
    end
end

function FuncPack:pointToPosition(point)
    local intx = math.modf(point.x/TILE_WIDTH)
    local inty = math.modf(point.y/TILE_HEIGHT);
    return {x=intx, y=inty}
end

function FuncPack:PositionTopoint(point)
    return {x=point.x*TILE_WIDTH, y=point.y*TILE_HEIGHT}
end

function FuncPack:getCheckPositionOfPoint(point)
    return FuncPack:pointToPosition({x=point.x+TILE_WIDTH/2, y=point.y+TILE_HEIGHT/2})
end

function FuncPack:pointToCheckPoint(point)
    return FuncPack:PositionTopoint(FuncPack:pointToPosition(point))
end

function FuncPack:getAbsoluteDistanceWithOPoints(point1, point2)
    local distancex = math.abs(point1.x - point2.x)
    local distancey = math.abs(point1.y - point2.y)
    local absDis = math.sqrt(distancex*distancex + distancey*distancey);

    return absDis;
end

function FuncPack:getStepBetweenPos(pos1, pos2)
    local distancex = math.abs(pos1.x - pos2.x)
    local distancey = math.abs(pos1.y - pos2.y)

    return math.max(distancex, distancey);
end

function FuncPack:getDistanceWithOPoints(position1, position2)
    --local position1 = FuncPack:getCheckPositionOfPoint(point1);
    --local position2 = FuncPack:getCheckPositionOfPoint(point2);
    local distancex = math.abs(position1.x - position2.x)
    local distancey = math.abs(position1.y - position2.y)

    if distancex > distancey then
        return distancex;
    else
        return distancey;
    end
end

function FuncPack:getDistanceWithOfPositions(position1, position2)
    return AStarFindPath:getHValue(position1, position2)
end

function FuncPack:isEqualPoint(p1, p2)
    if not p1 or not p2 then
        return false;
    end

    if p1.x == p2.x and p1.y == p2.y then
        return true;
    end

    return false;
end

function FuncPack:getEightDirectionPosition(pos)
    local positions = {};

    table.insert(positions, #positions+1, {x=pos.x-1,y=pos.y});
    table.insert(positions, #positions+1, {x=pos.x+1,y=pos.y});
    table.insert(positions, #positions+1, {x=pos.x,y=pos.y-1});
    table.insert(positions, #positions+1, {x=pos.x,y=pos.y+1});
    table.insert(positions, #positions+1, {x=pos.x+1,y=pos.y+1});
    table.insert(positions, #positions+1, {x=pos.x+1,y=pos.y-1});
    table.insert(positions, #positions+1, {x=pos.x-1,y=pos.y-1});
    table.insert(positions, #positions+1, {x=pos.x-1,y=pos.y+1});

    return positions;
end

function FuncPack:getRandomNumber(min, max)
    --math.randomseed(tostring(os.time()):reverse():sub(1, 6))
	local ret = 0;
	if min < max then
		ret = math.random(min, max);
	else
		ret = math.random(max, min);
	end

    return ret;
end

math.randomseed(os.time());
math.random(100);

function FuncPack:rectCross(ra, rb)
    local a_cx
    local a_cy; --/* 第一个中心点*/
    local b_cx
    local b_cy; --/* 第二个中心点*/

    a_cx = ra.x + (ra.w/2);
    a_cy = ra.y + (ra.h/2);

    b_cx = rb.x + (rb.w/2);
    b_cy = rb.y + (rb.h/2);

    return ( (_abs(a_cx - b_cx) <= (ra.w/2 + rb.w/2))
     and (_abs(a_cy - b_cy) <= (ra.h/2 + rb.h/2)));
end

function FuncPack:rectInter(ra, rb)
    local tl_x;
    local tl_y;
    local br_x;
    local br_y;

    tl_x = math.max(ra.x,rb.x);
    tl_y = math.max(ra.y,rb.y);

    br_x = math.min(ra.x+ra.w,rb.x+rb.w);
    br_y = math.min(ra.y+ra.h,rb.y+rb.h);

    if (tl_x > br_x ) or (tl_y > br_y ) then
        return nil; --/* 没有交集*/
    end

    local result = {};
    result.x = tl_x ;
    result.y = tl_y ;
    result.w = br_x - tl_x ;
    result.h = br_y - tl_y ;

    return result;
end

function FuncPack:nextPositionWithDir(originalPoint, dir, moveCheckCount)
    local point = {};
    local offsetx = moveCheckCount;
    local offsety = moveCheckCount;

    if dir == 1 then
        point = {x=originalPoint.x, y=originalPoint.y + offsety};
    elseif dir == 2 then
        point = {x=originalPoint.x + offsetx, y=originalPoint.y + offsety}
    elseif dir == 3 then
        point = {x=originalPoint.x + offsetx, y=originalPoint.y}
    elseif dir == 4 then
        point = {x=originalPoint.x + offsetx, y=originalPoint.y - offsety}
    elseif dir == 5 then
        point = {x=originalPoint.x, y=originalPoint.y - offsety}
    elseif dir == 6 then
        point = {x=originalPoint.x - offsetx, y=originalPoint.y - offsety}
    elseif dir == 7 then
        point = {x=originalPoint.x -offsetx, y=originalPoint.y}
    elseif dir == 8 then
        point = {x=originalPoint.x - offsetx, y=originalPoint.y + offsety}
    end

    return point;
end

function FuncPack:getDirectionWithPosition(playerPos, targetPos)
    local angle = FuncPack:parseLineAngleEx(targetPos, playerPos);
    local direction = FuncPack:cacluteDir(angle);

    return direction;
end

function FuncPack:rectContainPoint(rect, point)
    if point.x >= rect.left and point.y <= rect.right and
        point.y >= rect.bottom and point.y <= rect.top then
        return true;
    end

    return false;
end

FuncPack.listenerGroup = {};
function FuncPack:addEventListener(name, func)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()

    FuncPack.listenerGroup[name] = cc.EventListenerCustom:create(name, func)
    --eventDispatcher:addCustomEventListener(name, func)

    eventDispatcher:addEventListenerWithFixedPriority(FuncPack.listenerGroup[name], 2);
end

function FuncPack:print(str)
    FuncPack:dispatchEvent("SHOW_MESSAGE", str);
end

function FuncPack:removeEventListener(name)
	local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    eventDispatcher:removeCustomEventListeners(name);

    if engine.listenerGroup[name] then
        local listener = FuncPack.listenerGroup[name];
        local eventDispatcher = cc.Director:getInstance():getEventDispatcher()

        eventDispatcher:removeEventListener(listener);
    end
end

function FuncPack:dispatchEvent(name, info)
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    local event = cc.EventCustom:new(name)
    event.info = info;
    eventDispatcher:dispatchEvent(event);
end

function FuncPack:registShowUI(showUI)
	FuncPack.showUI = showUI;
end

function LogPrint(str)
	local logSystem = et.LogSystem:getInstance();
	local _date = getCurrDate(FuncPack:gettime());
	logSystem:print(1, _date.."  :"..str.."\n");
end

function DebugStr(str)
	local logSystem = et.LogSystem:getInstance();
	logSystem:print(2, str.."\r\n");
end

function FuncPack:gettime()
	return socket.gettime();
end
