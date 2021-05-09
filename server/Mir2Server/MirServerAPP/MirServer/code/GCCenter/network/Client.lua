--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/15
--此文件由[BabeLua]插件自动生成



--endregion
local Client = class("Client",function()
    return cc.Node:create()
end)

NETWORK_EVENT_CLOSE = 1
NETWORK_EVENT_DATA = 2
NETWORK_EVENT_CONNECT_OVERTIME = 3
NETWORK_EVENT_CONNECT_SUCCESS = 4

function Client:ctor()
    self.msgCallbackStack = {};
end

function Client:connect(ip, port)
    if not self.init then
        self.client = nw.ODClient:create();
        self.client:createSocket(2,1,0);
    end

    self.ip = ip;
    self.port = port;
    self.init = true;
    self.isConnect = false;
	self.msgCallbackStack = {};

    self:registLoginListener();
end

function Client:setOvertime(time)
    if not self.overtimeClock then
        self.overtimeClock = Clock:new();
    end

    self.overtimeClock:setRingTimeDelta(time);
    self.overtimeClock:markRingTime();
end

function Client:registLoginListener()
    local function loginUpdateFunc(delta)
        self:LoginUpdate(delta);
    end

    local scheduler = cc.Director:getInstance():getScheduler()
    self.loginUpdate = scheduler:scheduleScriptFunc(loginUpdateFunc, 1, false);
end

function Client:removeLoginListener()
    local scheduler = cc.Director:getInstance():getScheduler()
    scheduler:unscheduleScriptEntry(self.loginUpdate);
end

function Client:startConnect()
    local function ClientUpdateData()
        self:updateData();
    end

    local scheduler = cc.Director:getInstance():getScheduler()
    self.dataUpdate = scheduler:scheduleScriptFunc(ClientUpdateData, 1, false);

    self.client:listen();
    self.successFunc();
    self.isConnect = true;
end

function Client:closeDataQuest()
	local scheduler = cc.Director:getInstance():getScheduler()
    scheduler:unscheduleScriptEntry(self.dataUpdate);
end

function Client:send(msg)
	print("send message:"..msg);
    self.client:send(msg);
end

function Client:updateData()
    local offline = self.client:getOffLine();
    if offline then
        self.closeFunc();
        self.isConnect = false;
		self:closeDataQuest();
    end

    local hasMsg = self.client:hasNewMessage();
    if hasMsg then
        local msg = self.client:getNewMessage();
        --self.dataFunc(msg);
        self:parseData(msg);
    end
end

function Client:LoginUpdate(delta)
    if self.overtimeClock:ring() then
		print(":overtime");
        self.overtimeFunc("overtime");
        self:removeLoginListener();
    else
        local ret = self.client:connect(self.ip, self.port);
		print("connect:"..tostring(ret));
        if ret == true then
            self:removeLoginListener();
            self:startConnect();
        end
    end
end

function Client:addConnectEventListener(etype, func)
    if etype == NETWORK_EVENT_CLOSE then
        self.closeFunc = func;
    elseif etype == NETWORK_EVENT_DATA then
        self.dataFunc = func;
    elseif etype == NETWORK_EVENT_CONNECT_OVERTIME then
        self.overtimeFunc = func;
    elseif etype == NETWORK_EVENT_CONNECT_SUCCESS then
        self.successFunc = func;
    end
end

function Client:parseData(data)
    local dataTable = stringToTable(data);

    if not dataTable.id then
        TraceError("invalid msg:"..data);
        return;
    end

    local msgName = dataTable.id;

    if not self.msgCallbackStack[dataTable.id] then
        TraceError("not find message type:"..dataTable.id);
        return;
    end

    self.msgCallbackStack[dataTable.id](dataTable);
end

function Client:sendMessageWithRecall(id, values, func)
    values.id = id;

    local msgStr = TableToString(values);
    self:send(msgStr);

    --self.msgCallbackStack[msgName] = func;
    self:registMessageCallBack(id, func);
end

function Client:addMessageEventListener(msgName, func)
    self:registMessageCallBack(msgName, func);
end

function Client:registMessageCallBack(id, func)
	if self.msgCallbackStack[id] then
		print(id.." message exists");
	end

    self.msgCallbackStack[id] = func;
end

function Client:close()
    self.client:close();
    self:unScheduleUpdateWithPriorityLua(ClientUpdateData);
end

TableToString = function(_t)
    local szRet = "{"
    function doT2S(_i, _v)
        if "number" == type(_i) then
            szRet = szRet .. "[" .. _i .. "] = "
            if "number" == type(_v) then
                szRet = szRet .. _v .. ","
            elseif "string" == type(_v) then
                szRet = szRet .. '"' .. _v .. '"' .. ","
            elseif "table" == type(_v) then
                szRet = szRet .. sz_T2S(_v) .. ","
            else
                szRet = szRet .. "nil,"
            end
        elseif "string" == type(_i) then
            szRet = szRet .. '["' .. _i .. '"] = '
            if "number" == type(_v) then
                szRet = szRet .. _v .. ","
            elseif "string" == type(_v) then
                szRet = szRet .. '"' .. _v .. '"' .. ","
            elseif "table" == type(_v) then
                szRet = szRet .. sz_T2S(_v) .. ","
            else
                szRet = szRet .. "nil,"
            end
        end
    end
    table.foreach(_t, doT2S)
    szRet = szRet .. "}"
    return szRet
end

stringToTable = function(string)
    local str = "return "..string
    local func = loadstring(str)
    return func();
end

return Client;
