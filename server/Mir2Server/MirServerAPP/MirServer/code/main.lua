
-- CC_USE_DEPRECATED_API = true
require "cocos.init"
require "include"

-- cclog
local cclog = function(...)
    print(string.format(...))

	--FuncPack:dispatchEvent("SHOW_MESSAGE", string.format(...));
	--[[local ret_file = io.open("log.txt","a+")
	ret_file:write(os.date("%Y-%m-%d %X", os.time())..":  "..string.format(...));
	ret_file:close();]]
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------\n")

	local file = io.open("D:/mfc_log.txt", "a+");
	file:write("----------------------------------------------");
	file:write(os.date("%Y-%m-%d %X ", os.time()).."    msg:"..msg.."   :"..debug.traceback());
	file:write("----------------------------------------------\r\n\r\n");
	file:close();

	print("----------------------------------------");
	print("LUA ERROR: " .. tostring(msg) .. "\n");
	print(debug.traceback());
	print("----------------------------------------\n");

    return msg
end

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    cc.FileUtils:getInstance():addSearchPath("src")
    cc.FileUtils:getInstance():addSearchPath("res")
    --cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(600, 400, 0)

	--load lua module


    --create scene
	--local file = io.open("D:/Coco-workplace/mfc_log.txt", "w");
	--file:close();

    local scene = require("GameScene")
    local gameScene = scene.create()
    gameScene:playBgMusic()
    g_gameScene = gameScene;

    if cc.Director:getInstance():getRunningScene() then
        cc.Director:getInstance():replaceScene(gameScene)
    else
        cc.Director:getInstance():runWithScene(gameScene)
    end

end


local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    error(msg..":"..debug.traceback())
	LogPrint(msg..":"..debug.traceback());
end
