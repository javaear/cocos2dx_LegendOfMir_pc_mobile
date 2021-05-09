HalfMoonSlash = class("HalfMoonSlash", function()
    return SlashSpell:new();
end)

function HalfMoonSlash:ctor()

end


--打包战斗信息
function HalfMoonSlash:packageAttackInfo(object, atkDir)
    local info = {}
    info.fromid = object:getID();
	info.atkValue = {};

	--attack info
	local baseAttack = object:getRandomAttack(self.attackType);
    local totalAttack = baseAttack*self.growDamage + self.baseDamage;
	local attackValue = {type=self.attackType,attack=totalAttack, power=self.power};

	--target info
	local objPos = object:getPosition();
	local attackRange = {atkDir+7, atkDir+1, atkDir+2}
	local map = MapManager:getMap(object:getMap());

	for k,dir in pairs(attackRange) do
		if dir > 8 then
			dir = dir%8;
		end

		local tarPosBySide = FuncPack:nextPositionWithDir(objPos,dir,1);
		local targetBySide = map:getObjectFromMap(tarPosBySide);

		if targetBySide then
			for k,v in pairs(targetBySide) do
				table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack*0.5, toid=v:getID()});
			end

			--local attackInfo = {value={type=self.attackType,attack=totalAttack*0.5, power=self.power}, target = targetBySide}
			--table.insert(info.atkValue, #info.atkValue+1, attackInfo);
		end
	end

	--table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack, toid=v:getID()});

    local tarPos = FuncPack:nextPositionWithDir(objPos,atkDir,1)
	local faceTargets = map:getObjectFromMap(tarPos);
	if faceTargets then
		for k,v in pairs(faceTargets) do
			table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack, toid=v:getID()});
		end
	end

	--table.insert(info.attackInfos, #info.attackInfos+1, attackInfo);

	return info;
end
