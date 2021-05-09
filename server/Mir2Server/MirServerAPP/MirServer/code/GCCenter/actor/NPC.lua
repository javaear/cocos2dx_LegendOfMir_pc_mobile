NPC = class("NPC", function()
	return Actor:new();
end)

--[[
ActorDir =
{
    "up",
    "upright",
    "right",
    "rightdown",
    "down",
    "downleft",
    "left",
    "leftup",
}]]

--方向 1...8 表示正向上顺时针旋转
--状�?.�? 表示站立,走路,跑步,挥砍,施法
local statusAniStep = 3 --每个状态同方向的动画之间间�?

function NPC:ctor()
	self.commands = {};
end

function NPC:init(conf)
	local tConf = talkConf[conf.talkId];

	--local commands = tConftb_content.tConf;
	for k,v in pairs(tConf.tb_content) do
		table.insert(self.commands, #self.commands+1,
			{funcType=v.funcType,funcStr=v.funcStr});
	end
end

function NPC:request(pid, data)
	local conf = talkConf[data.confId];
	local command = conf.tb_content[data.commandIdx];
	local funcType = command.funcType;
	local funcStr = command.funcStr;

	if funcType == 2 then
		Game.changeMap(pid, funcStr.id, {x=funcStr.x,y=funcStr.y});
	end
end
