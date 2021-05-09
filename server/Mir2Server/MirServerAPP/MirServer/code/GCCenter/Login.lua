Login = {}
Login.accounts = {}

local ACCOUNT_OFFLINE = 1;
local ACCOUNT_ONLINE = 2;
local ACCOUNT_NO_EXISTS = 3;
local ACCOUNT_STATE_NAME =
{
	[1] = "free",
	[2] = "already login",
	[3] = "no exists"
}

Login.checkAccount = function(id, data)
	--checke account
	local account = Login.getAccount(data);
	if not account then
		server:send(id, {id="LOGIN_CHECK", ret=0, _error="no found account"});
		server:closeClient(id);
		return;
	end

	--check login state
	local aid = account.aid;
	if Login.checkAccountLogining(aid) then
		server:send(id, {id="LOGIN_CHECK", ret=0, _error="account has already logined"});
		server:closeClient(id);
		return;
	end

	--alter client id
	server:alterClientId(id, tonumber(aid));

	--obtain actor data
	local actorsInfo = Login.getActors(aid);
	Login.accounts[aid].isLogin = true;

	--send msg
	server:send(aid, {id="LOGIN_CHECK", ret=1, actorsInfo=actorsInfo});

	LogPrint("account:"..account.aid.." login succeessfully");
end

Login.checkAccountLogining = function(aid)
	if not Login.accounts[aid] then
		return;
	end

	if not Login.accounts[aid].isLogin then
		return;
	end

	return true;
end

Login.getAccount = function(data)
	local accountTable = DBServer:select("data_account", {"*"}, {account=data.account, password=data.password});
	local account = accountTable[1];

	return account;
end

Login.getActors = function(aid)
	if not Login.accounts[aid] then
		Login.accounts[aid] = {};
	end

	if Login.accounts[aid].actorsInfo then
		for k,v in pairs(Login.accounts[aid].actorsInfo) do
			local pid = v.pid;
			local actor = ActorManager:getActor(pid);

			if actor then
				if actor:isDie() then
					actor:revive();

					local actorData = actor:getBaseData();
					local mainCityId = MapConf[actorData.worldid].masterCity;
					local pos = MapConf[mainCityId].tb_masterCityPos;

					actorData.worldid = mainCityId;
					actorData.worldpos = pos;

					actor:setPosition(pos.x, pos.y);
					actor:setBaseData(actorData);
				end

				Login.accounts[aid].actorsInfo[k]=actor:getBaseData();
			end
		end

		--return Login.accounts[aid].actorsInfo;
	else
		local actorsInfo = DBServer:select("data_actor", {"*"}, {aid=tonumber(aid)});

		for k,v in pairs(actorsInfo) do
			local actor = ActorManager:getActor(v.pid);

			if actor then
				if actor:isDie() then
					actor:revive();

					local actorData = actor:getBaseData();
					local mainCityId = MapConf[actorData.worldid].masterCity;
					local pos = MapConf[mainCityId].tb_masterCityPos;

					actorData.worldid = mainCityId;
					actorData.worldpos = pos;

					actor:setPosition(pos.x, pos.y);
					actor:setBaseData(actorData);
				end

				actorsInfo[k] = actor:getBaseData();
			else
				local item, equip,skill = Login.getActorData(v.pid);
				actorsInfo[k].item = item;
				actorsInfo[k].equip = equip;
				actorsInfo[k].skill = skill;
			end
		end

		for k,v in pairs(actorsInfo) do
			actorsInfo[k].camp = 1;
		end

		Login.accounts[aid].actorsInfo = actorsInfo;
		--return actorsInfo;
	end

	return Login.accounts[aid].actorsInfo
end

Login.createActor = function(id, data)
	local actors = Login.getActors(id);
	if #actors >= 2 then
		server:send(id, {id="CREATE_ACTOR", ret=0, _error="actors count over"});
		return;
	end

	local ret,sql,data = DBServer:insert("data_actor",
		{"aid","name", "level","style","sex","gold","money", "worldid", "worldpos"},
		{id, data.name, 1, data.style, data.sex, 0, 0, 1, "{x=214, y=212}"})

	data.item = {};
	data.equip = {};
	data.skill = {};
	--LogPrint("sql:  "..tostring(sql));

	if ret == false then
		LogPrint("error happened sql:  "..tostring(sql));
		server:send(id, {id="CREATE_ACTOR", ret=0, _error="unknown error"});
	else
		table.insert(Login.accounts[id].actorsInfo, #(Login.accounts[id].actorsInfo)+1, data);

		local actorLen = #(Login.accounts[id].actorsInfo);
		local newActor = Login.accounts[id].actorsInfo[actorLen];

		newActor.camp = 1;
		print("new actor info:"..tostringex(newActor));
		server:send(id, {id="CREATE_ACTOR", ret=1, data=newActor});
	end
end

Login.getActorData = function(pid)
	local item = DBServer:select("data_item", {"*"}, {pid=pid, isEquip=0});
	local equip = DBServer:select("data_item", {"*"}, {pid=pid, isEquip=1});
	local skill = DBServer:select("data_skill", {"*"}, {pid=pid});

	return item, equip,skill;
end

server:registDataCallFunc("LOGIN_CHECK", Login.checkAccount)
server:registDataCallFunc("CREATE_ACTOR", Login.createActor)
