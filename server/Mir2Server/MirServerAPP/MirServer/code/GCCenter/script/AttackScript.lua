AttackScript = {}
AttackScript.logSwitch = nil;

function AttackScript:exec(info, skillInfo)
	local fromObj = ActorManager:getActor(info.fromid);

	if not fromObj or fromObj:isDie() then
		LogPrint("玩家 "..info.fromid.." 已经死亡,无法在进行攻击,攻击无效化");
		return false;
	end

	local atkMsg = {fromid=info.fromid, atkInfo={}};

	for k,v in pairs(info.atkValue) do
		local toObj = ActorManager:getActor(v.toid);

		if toObj and not toObj:isDie() and toObj:getCamp() ~= 3 then
			local damage, isDodge, isCrit = self:calcDamage(fromObj, toObj, v);
			local atkInfo = {isDodge=isDodge,isCrit=isCrit, dg=damage,
				toid=v.toid,aty=info.atkValue.aty,curHp=toObj:getAttribute().hp};

			if AttackScript.logSwitch then
				print(info.fromid.."  attack:"..toObj:getID().." damage:"..damage.."  remaining hp:"..toObj:getAttribute().hp.." trace:");
			end

			table.insert(atkMsg.atkInfo, #atkMsg.atkInfo+1, atkInfo);
		else
			--LogPrint("no toObj:"..v.toid);
		end
	end

	if #atkMsg.atkInfo > 0 then
		atkMsg.id = "BC_SHOW_DAMAGE"--"BC_ACTOR_ATTACK"
		atkMsg.skillName = skillInfo.skillName;
		atkMsg.values = skillInfo.values;
		GCCenter.sendSameScreenBroadcastWithFromObj(fromObj, atkMsg);
	end
end

function AttackScript:calcDamage(fromObj, toObj, extraDetail)
	local attack  = extraDetail.atk;
	local defense = toObj:getRandomDefense(extraDetail.aty);
	local damage  = rmDecimal(attack - defense);

	if damage < 1 then
		damage = 1;
	end

	local isCrit = AttackScript:checkIsCrit(fromObj, toObj);
	local isDodge = AttackScript:checkIsDodge(fromObj, toObj);
	local realDamage = 0;

	if isCrit then
		damage = rmDecimal(1.5 * damage);
	end

	if not isDodge or isCrit then
		fromObj:setAtkTarget(toObj:getID());
		realDamage = toObj:getDamage(fromObj:getID(), damage);
	end

	if toObj:isDie() and fromObj:getClient() then
		local exc = toObj.conf.exc or 0;
		Game.addExc(fromObj:getID(), exc);
	end

	return realDamage, isDodge, isCrit;
end

function AttackScript:checkIsCrit(fromObj, toObj)
	local fromAttri = fromObj:getAttribute();
	local toAttri = toObj:getAttribute();
	local defCrit = toAttri.defenCrit;
	local critRate = fromAttri.critRate;

	local num = critRate - defCrit;
	local randNum = FuncPack:getRandomNumber(1, 100);

	if num >= randNum then
		return true;
	end

	return false;
end

function AttackScript:checkIsDodge(fromObj, toObj)
	local fromAttri = fromObj:getAttribute();
	local toAttri = toObj:getAttribute();
	local dodge = toAttri.dodge;
	local precise = fromAttri.precise + 100;
	local num = precise - dodge;

	local randNum = FuncPack:getRandomNumber(1, 100);

	if num >= randNum then
		return false;
	end

	return true;
end

function rmDecimal(number)
	local int,decimal = math.modf(number);
	return int;
end
