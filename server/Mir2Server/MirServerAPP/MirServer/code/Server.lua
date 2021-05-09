--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/16
--此文件由[BabeLua]插件自动生成
require "tools/tools.lua"


--endregion
local Server = class("class", function()
    return cc.Node:create();
end)

SERVER_EVENT_NEW_CLIENT = 1
SERVER_EVENT_CLIENT_CLOSE = 2
SERVER_EVENT_DATA = 3

local SERVER_CONNECT_PORT = 7991;

function Server:ctor()
    self.server = et.ODServer:create();
    self.server:createSocket(2,1,0);
    self.server:bind(SERVER_CONNECT_PORT);
    self:addChild(self.server);
    self.clientGroups = {};
    self.dataCallFuncs = {};
end

function Server:registEventListener()
    local function updateFunc(dt)
        self:update(dt);
    end

    local scheduler = cc.Director:getInstance():getScheduler();
    scheduler:scheduleScriptFunc(updateFunc, 0, false);
    --self:scheduleUpdateWithPriorityLua(updateFunc,0);
end

function Server:removeEventListener()

end

function Server:start()
    local ret = self.server:listen(true);

    if ret == true then
        self:registEventListener();
    end

	local client = self.server:popBackClient();

    return ret;
end

function Server:close()
	for k, v in pairs(self.clientGroups) do
		self:closeClient(k);
	end

	self.server:clean();
end

function Server:update(dt)
	---local client = cc.Director:getInstance():getRunningScene():getScheduler();
	local client = self.server:popBackClient();
	--self.server:getFreeClient();
    while client do
        client:listen();
        self:addClient(client);

        if self.clientFunc then
            self.clientFunc(client);
        end

		client = self.server:popBackClient();
    end

    for k,v in pairs(self.clientGroups) do
        local offline = v:getOffLine();

        if offline then
			--print(k.."  close");
            self.closeFunc(v);
            self.clientGroups[k] = nil;
			v:clean();
        end

        self:readMsg(v);
    end
end

function Server:readMsg(client)
	while client:hasNewMessage() do
		local message = client:getNewMessage();
		local data = StringToTable(message);

		if not self:onDataFunc(client, data) then
			self:readMsg(client);
		end
	end
end

function Server:closeClient(id)
	if self.clientGroups[id] then
		self.clientGroups[id]:clean();
		self.clientGroups[id] = nil;
	end

	--self.server:clean();
end

function Server:send(id, msg)
    local client = self.clientGroups[id];

	if not msg or msg == "" then
		--print("no msg:"..debug.traceBack());
		return
	end

    if client then
		msg.time = FuncPack:gettime();
        local dataStr = TableToString(msg);
        client:send(dataStr);

		--print("client:"..tostring(client).." send client "..id.." msg "..msg.id)
	else
		LogPrint("no find client:"..id)
    end
end

function Server:addClient(client)
    local id = client:getID();

	--print("init id:"..id.."  client:"..tostring(client));
    self.clientGroups[id] = client;
end

function Server:alterClientId(oldId, newId)
    local client = self.clientGroups[oldId];

	if client then
		self.clientGroups[newId] = client;
		self.clientGroups[oldId] = nil;
		client:setID(newId);

		--print("client:"..tostring(client).." change id from "..oldId.." to "..newId);
		LogPrint(oldId.." id change to "..newId.." id");
	end
end

function Server:addConnectEventListener(etype, func)
    if etype == SERVER_EVENT_NEW_CLIENT then
        self.clientFunc = func;
    elseif etype == SERVER_EVENT_CLIENT_CLOSE then
        self.closeFunc = func;
    elseif etype == SERVER_EVENT_DATA then
    end
end

function Server:onDataFunc(client, message)
    local id = message.id;

    if not self.dataCallFuncs[id] then
        print("invalid message:"..tostringex(message));
        return;
    end

	--print("receive message:"..tostringex(message).."     callfunc:"..tostring(self.dataCallFuncs[id]));
    self.dataCallFuncs[id](client:getID(), message);

	return true;
end

function Server:registDataCallFunc(id, func)
    if self.dataCallFuncs[id] then
        --print(id.." exists :"..debug.traceback());
    end

    self.dataCallFuncs[id] = func;
end

return Server;
