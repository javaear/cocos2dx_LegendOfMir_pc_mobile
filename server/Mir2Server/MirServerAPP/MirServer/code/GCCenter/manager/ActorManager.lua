ActorManager = {}
ActorManager.actors = {}
ActorManager.monsters = {}

function ActorManager:initActorBody(actor, actorData, attribute)
    if attribute.type == "Actor" then
        if actorData.sex == 2 then
            actor.nakedBody = engine.readBodyMapSprite("human1", 600);
        else
            actor.nakedBody = engine.readBodyMapSprite("human1", 0);
        end
    else
        actor.nakedBody = engine.readMonsterSprite(attribute.conf.path, attribute.conf.offset);
    end
end

function ActorManager:initActorExtra(actor, actorData, conf)
	local skill = SkillManager:addSkill({skillid=1,exc=0,level=0})
	if skill then
		actor:addSkill(skill);
	else
		print("no found skill "..tostringex(v));
	end

	local skillTable = StringToTable(conf.sz_skill);
	if skillTable then
		for k,v in pairs(skillTable) do
			local skill = SkillManager:addSkill(v)

			if skill then
				actor:addSkill(skill);
			else
				LogPrint("no found skill "..tostringex(v));
			end
		end
	end

	--local skill = SkillManager:addSkill({skillid=1, level=1, exc=0})
	--actor:addSkill(skill);
	if actorData.skill then
		for k,v in pairs(actorData.skill) do
			local skill = SkillManager:addSkill(v)

			if skill then
				actor:addSkill(skill);
			else
				print("no found skill "..tostringex(v));
			end
		end
	end

	if actorData.equip then
		for k,v in pairs(actorData.equip) do
			local extraContent = v.extraContent;
			local equip = ItemManager:registItem(v);

			if not equip then
				print("no equip:"..tostringex(v));
			else
				actor:equip(equip, extraContent);
			end
		end
	end

	if actorData.item then
		for k,v in pairs(actorData.item) do
			local item = ItemManager:registItem(v);
			if item then
				actor:addItem(item, v.gridIndex);
			else
				TraceError("no item:"..tostringex(v));
			end
		end
	end
end

function ActorManager:initActorScript(actor)
    --增加脚本
    local findPathScript = AutoFindPathEx:create();
    actor:addScript("findpath", findPathScript)

    local fightScript = AutoFight:create();
    actor:addScript("autofight", fightScript);
end

function ActorManager:createNPC(actorData)
	if ActorManager:getActor(actorData.pid) then
		LogPrint(actorData.pid.." already exists");
		return ActorManager:getActor(actorData.pid);
	end

	local conf = npcConf[actorData.style];
	local npc = NPC:new();
	npc:setBaseData(actorData);
	npc:setName(conf.sz_name);
	npc:setCamp(3);
	npc:init(conf);

	self:registActorWithID(npc, actorData.pid);

	return npc;
end

function ActorManager:createActor(actorData)
	if ActorManager:getActor(actorData.pid) then
		LogPrint("actor "..actorData.pid.." already exists   debug:"..debug.traceback());
		return ActorManager:getActor(actorData.pid);
	end

    local conf = ActorConf[actorData.style];
	local createFunc = loadstring("return "..conf.sz_class..":new()")
    local actor = createFunc();

	actor:setBaseData(actorData);
    actor:setName(actorData.name);
    actor:setSex(actorData.sex);
    actor:setType(actorData.style);
    actor:setLevel(actorData.level);
	actor:setMoney(actorData.money);
	actor:setGold(actorData.gold);
	actor:setExc(actorData.exc);
	actor:setAttributeId(conf.attributeid);
    actor:init(conf);
	actor:setCamp(1);

	--print(tostringex(actor.attribute));

    self:initActorExtra(actor, actorData, conf);
	--self:initActorScript(actor)

	self:registActorWithID(actor, actorData.pid);

    return actor;
end

function ActorManager:getActor(id)
    return ActorManager.actors[id];
end

function ActorManager:getMonster(id)
    return ActorManager.monsters[id];
end

function ActorManager:createMonster(actorData)
	local attribute = ActorConf[actorData.style];
    local createFunc = loadstring("return "..attribute.sz_class..":new()")
    local monster = createFunc();
	monster.isNative = true;
	monster:setBaseData(actorData);
    monster:setName(attribute.name);
    monster:setSex(actorData.sex);
    monster:setType(actorData.style);
    monster:setLevel(actorData.level or 1);
	monster:setAlertArea(actorData.alertArea);
	monster:setAttributeId(attribute.attributeid);
    monster:init(attribute);
	monster:setCamp(actorData.camp or 2);

	--print(tostringex(monster.attribute));
	self:initActorExtra(monster, actorData, attribute);
	self:initActorScript(monster);

	--monster:addScript("ai", MonsterBaseAI:new());

	self:registActorWithID(monster, actorData.pid);
    return monster;
end

function ActorManager:registMonster(monster)
    local id = #ActorManager.monsters + 1
    ActorManager.monsters[id] = monster;

    return id;
end

function ActorManager:release()
    for k,v in pairs(ActorManager.actors) do
        v:release();
    end
end

function ActorManager:registActorWithID(actor, id)
    ActorManager.actors[id] = actor;
    actor:setID(id);
end
