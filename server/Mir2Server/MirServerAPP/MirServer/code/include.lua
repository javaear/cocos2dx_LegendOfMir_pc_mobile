require "socket"
require "tools/FuncPack.lua"
require "tools/tools.lua"
require "tools/Clock.lua"
require "tools/Timer.lua"

require "DB/DBTableDef.lua"
require "DB/DBServer.lua"
require "Server.lua"
require "GCCenter/GCCenter.lua"

require "GCCenter/scene/Map.lua"
require "GCCenter/scene/MapMonsterGenerator.lua"
require "GCCenter/manager/MapManager.lua"
require "GCCenter/manager/ActorManager.lua"
require "GCCenter/manager/ItemManager.lua"
require "GCCenter/manager/SkillManager.lua"
require "GCCenter/manager/TimerManager.lua"

require "GCCenter/actor/Actor.lua"
require "GCCenter/actor/GodMon.lua"
require "GCCenter/actor/Monster.lua"
require "GCCenter/actor/Attribute.lua"
require "GCCenter/actor/NPC.lua"

require "GCCenter/good/Item.lua"
require "GCCenter/good/BloodVial.lua"
require "GCCenter/good/Equipment.lua"
require "GCCenter/good/Ticket.lua"
require "GCCenter/good/GoodPack.lua"
require "GCCenter/skill/base/BaseSpell.lua"
require "GCCenter/skill/base/BuffSpell.lua"
require "GCCenter/skill/base/SlashSpell.lua"
require "GCCenter/skill/base/ThrustFencing.lua"
require "GCCenter/skill/base/RangeSpell.lua"
require "GCCenter/skill/base/HalfMoonSlash.lua"
require "GCCenter/skill/base/FireWallUnit.lua"
require "GCCenter/skill/base/FireWall.lua"
require "GCCenter/skill/base/GodAtkSpell.lua"
require "GCCenter/skill/base/CallPet.lua"
require "GCCenter/skill/base/SpeedUpSpell.lua"
require "GCCenter/skill/base/ShootSpell.lua"

require "GCCenter/script/AStarFindPath.lua"
require "GCCenter/script/AttackScript.lua"
require "GCCenter/script/MoveScript.lua"
require "GCCenter/script/AutoFindPath.lua"
require "GCCenter/script/AutoFindPathEx.lua"
require "GCCenter/script/AutoFight.lua"
require "GCCenter/ai/MonsterBaseAI.lua"
require "GCCenter/ai/PetAI.lua"

global = {};
global.tabFiles =
{
	"conf/map/map.tab",
	"conf/actor/actor.tab",
	"conf/actor/actorAttribute.tab",
	"conf/skill/skill.tab",
	"conf/equip/equipment.tab",
	"conf/sprite/sprite.tab",
};

function start()
	TILE_WIDTH = 48
    TILE_HEIGHT = 32

	MapConf   		 = readTabFile("conf/map/map.tab")
	ActorConf    	 = readTabFile("conf/actor/actor.tab")
	ActorGrowConf    = readTabFile("conf/actor/actorAttribute.tab")
	ActorLvAttribute = readActorLevelAttributeConf();
	skillConf        = readTabFile("conf/skill/skill.tab")
    EquipmentConf    = readTabFile("conf/equip/equipment.tab")
	spriteConf       = readTabFile("conf/sprite/sprite.tab")
	npcConf          = readTabFile("conf/npc/npc.tab")
	talkConf         = readTabFile("conf/npc/talkConf.tab")

    for k,v in pairs(EquipmentConf) do
        if v.sz_atk ~= nil then
            EquipmentConf[k].atk = StringToTable(v.sz_atk);
        end

        if v.sz_dfs ~= nil then
            EquipmentConf[k].dfs = StringToTable(v.sz_dfs);
        end
    end

	for k,v in pairs(ActorConf) do
        --ActorConf[k].speed = StringToTable(v.sz_speed);
		ActorConf[k].name = v.sz_name;

		if v.allowRun == 1 then
			ActorConf[k].allowRun = true;
		else
			ActorConf[k].allowRun = false;
		end
    end

	LogPrint("server init success");
	GCCenter.init();

	return 0;
end

function initServer()
	if server then
		server:close();
	end

	LogPrint("server init");
	local Server = require("Server")
    server = Server:new();
    server:retain();

	local ret = server:start();
	if ret == false then
		LogPrint("server init failed");
		return 1;
	else
		LogPrint("server init succeed");
	end
end

function initDB()
	local ret = DBServer:init("SQLite/Mir2");
	if ret == false then
		LogPrint("SQLite/Mir2 init failed");
		return 2;
	else
		LogPrint("SQLite/Mir2 init succeed");
	end
end

function readActorLevelAttributeConf()
	local conf = {};

	for key,value in pairs(ActorGrowConf) do
		conf[key] = {};

		for k,v in pairs(value) do
			local title = k;
			local value = v;
			local grow = 0;

			if string.find(title, "sz_") then
				local keys = split(k, "_");
				title = keys[2];
			end

			if string.find(v, "%(") then
				if string.find(v, "{") then
					local array = split(v, "(")
					value = StringToTable(array[1]);

					grow = StringToTable(string.sub(array[2], 2, string.len(array[2])-1));
				else
					local values = split(v, "(");
					value = tonumber(values[1]);
					grow = tonumber(string.sub(values[2], 1,
						string.len(values[2])-1));
				end
			else
				if string.find(v, "{") then
					value = StringToTable(v);
				end
			end

			local growTitle = title.."_Grow";
			conf[key][title] = value;
			conf[key][growTitle] = grow;
			conf[key]["description_Grow"] = nil;
			conf[key]["id_Grow"] = nil;
		end
	end

	--TraceError("conf:"..tostringex(conf));
	return conf;
end

function GetActorLevelAttribute(id, _level)
	local level = _level - 1;
	local conf = ActorLvAttribute[id];
	if not conf then
		return;
	end

	local attribute = {};
	attribute.maxHp = conf.maxHp + conf.maxHp_Grow*level;
	attribute.maxMp = conf.maxMp + conf.maxMp_Grow*level;
	attribute.atk = {{0,0},{0,0},{0,0}}--conf.attack;
	attribute.dfs = {0, 0, 0}--conf.defense;

	for k,v in pairs(attribute.atk) do
		local grow = 0;
		if conf.attack_Grow and type(conf.attack_Grow) == "table" then
			grow = conf.attack_Grow[k];
		end

		attribute.atk[k][1] = v[1] + grow*level;
		attribute.atk[k][2] = v[2] + grow*level;

		if conf.attack[k] then
			attribute.atk[k][1] = attribute.atk[k][1] + conf.attack[k][1];
			attribute.atk[k][2] = attribute.atk[k][2] + conf.attack[k][2];
		end
		--attribute.atk[k][3] = v[3] + grow*level;
	end

	for k,v in pairs(attribute.dfs) do
		local grow = 0;
		if conf.defense_Grow and type(conf.defense_Grow) == "table" then
			grow = conf.defense_Grow[k];
		end

		attribute.dfs[k] = v + grow*level;

		if conf.defense[k] then
			attribute.dfs[k] = attribute.dfs[k] + conf.defense[k];
		end
	end

	attribute.castSpeed = conf.castSpeed;
	attribute.slashSpeed = conf.slashSpeed;
	attribute.speed = conf.speed;

	attribute.strength = (conf.strength or 0) + (conf.strength_Grow or 0)*level;
	attribute.aligity = (conf.aligity or 0) + (conf.aligity_Grow or 0)*level;
	attribute.taoistMagic = (conf.taoistMagic or 0) + (conf.taoistMagic_Grow or 0)*level;
	attribute.critRate = (conf.critRate or 0) + (conf.critRate_Grow or 0)*level;
	attribute.defenCrit = (conf.defenCrit or 0) + (conf.defenCrit_Grow or 0)*level;
	attribute.lucky = (conf.lucky or 0) + (conf.lucky_Grow or 0)*level;
	attribute.precise = (conf.precise or 0) + (conf.precise_Grow or 0)*level;
	attribute.dodge = (conf.dodge or 0) + (conf.dodge_Grow or 0)*level;

	return attribute;
end

function getLevelFromExc(sz_conf, level, exc)
	local conf = readTabFile(sz_conf);
	if conf then
		local maxExc = conf[level].maxExc;
		while exc >= maxExc do
			if conf[level+1] then
				exc = exc - maxExc;
				level = level + 1;

				maxExc = conf[level].maxExc;
			else
				exc = maxExc;
				break;
			end
		end
	end

	return level, exc;
end

function getMaxExc(sz_conf, level)
	local conf = readTabFile(sz_conf);
	if conf and conf[level] then
		return conf[level].maxExc;
	end

	return 0;
end

function getMapConfTxt(_type)
	local result = "";

	for k,v in pairs(MapConf[1]) do
		result = result..k.."\t"
	end

	result = result.."\n";

	for k,v in pairs(MapConf) do
		for key, value in pairs(v) do
			result = result..value.."\t"
		end

		result = result.."\n";
	end

	return result;
end

function getPlayerList(_type)
	local result = "";

	for k,v in pairs(Login.accounts) do
		LogPrint("1 v.currActor:"..tostring(v.currActor));
		if v.currActor then
			local actor = ActorManager:getActor(v.currActor);
			result = result..actor:getID()..","..actor:getName()..","..actor:getLevel().."\n";
		end
	end

	--print("result:"..String2UTF8(result));
	return String2UTF8(result);
end

function Close()
	if server then
		server:close();
	end
end
