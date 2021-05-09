require "include.lua"

local GameScene = class("GameScene",function()
    return cc.Scene:create()
end)

function GameScene.create()
    local scene = GameScene.new()
    scene:createLayer()
    return scene
end


function GameScene:ctor()
    self.visibleSize = cc.Director:getInstance():getVisibleSize()
    self.origin = cc.Director:getInstance():getVisibleOrigin()
end

function GameScene:playBgMusic()
end

-- create layer
function GameScene:createLayer()
    --self:initUI();
    --[[
    local function onData(client, data)
        self:parseData(client, stringToTable(data));
    end

    local function onClient(client)
    end

	local function onCloseClient(client)
	end

    server:addConnectEventListener(SERVER_EVENT_NEW_CLIENT, onClient);
    server:addConnectEventListener(SERVER_EVENT_DATA, onData);
	server:addConnectEventListener(SERVER_EVENT_CLIENT_CLOSE, onCloseClient);]]
	--[[
    local blank = {};
    local blankStr =  TableToString(blank);
    --local ret2 = DBServer:doSql("CREATE TABLE data_account(pid INTEGER PRIMARY KEY,account blob NOT NULL,password blob NOT NULL, actors blob NOT NULL)");

    DBServer:doSql("delete from data_account");
    --local ret = DBServer:select("data_account",{"*"},{"account='1'"});--DBServer:insert("data_account", {"account","password","actors"},{"1","2",blankStr});
    local ret2 = DBServer:insert("data_account", {"account","password","actors"},{"1","2",blankStr});
    local ret = DBServer:select("data_account",{"*"},{"account='1'"});
    self:showMessage("ret:"..tostring(ret));]]
    --self:showMessage("ret:"..tostring(result));

	local function sceneUpdate(delta)
		GCCenter.update(delta);
	end

	self:scheduleUpdateWithPriorityLua(sceneUpdate,1)
end

function GameScene:initUI()
    local visibleSize = cc.Director:getInstance():getVisibleSize();
    local msgLabel = cc.Label:createWithTTF("","fonts/simhei.ttf",20);
    msgLabel:setAlignment(0,0);
	msgLabel:setAnchorPoint(0, 0);
	msgLabel:setWidth(visibleSize.width);
	msgLabel:setHeight(visibleSize.height);
	msgLabel:setPosition(0, 0);
    self.msgLabel = msgLabel;
    self:addChild(msgLabel);

	FuncPack:registShowUI(self.msgLabel);
end

function GameScene:showMessage(str)
    local oldStr = self.msgLabel:getString();
	local newStr = oldStr..str.."\n";
	self.msgLabel:setString(newStr);
end

--game logical
function GameScene:getActorInfo(data)
end

return GameScene
