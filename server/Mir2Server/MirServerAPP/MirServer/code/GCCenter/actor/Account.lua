
Account = {}
Account.actorGroups = {}

function Account:init(data)
	Account.data = data;
	--[[
	for k,v in pairs(data.actorsInfo) do
		local actor = ActorManager:createActor(v);
		table.insert(Account.actorGroups, #Account.actorGroups+1, actor);
	end]]
end

function Account:addActorFromData(data, index)
	local actor = ActorManager:createActor(data);

	Account.actorGroups[index] = actor;
    --table.insert(Account.actorGroups, #Account.actorGroups+1, actor);

	return actor;
end

function Account:addActor(actor)
    table.insert(Account.actorGroups, #Account.actorGroups+1, actor);
end

function Account:selActor(actor)
    self.currActorIndex = index;
end

function Account:getCurrActor()
    return Account.actorGroups[currActorIndex];
end

function Account:getActor(id)
    return Account.actorGroups[id];
end

function Account:getActorsData()
	return Account.data.actorsInfo;
end
