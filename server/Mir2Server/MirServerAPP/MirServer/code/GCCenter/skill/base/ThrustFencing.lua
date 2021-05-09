ThrustFencing = class("ThrustFencing", function()
    return SlashSpell:new();
end)

function ThrustFencing:ctor()
end

--打包战斗信息
function ThrustFencing:packageAttackInfo(object, dir)
    local info = {}
    info.fromid = object:getID();
	info.atkValue = {};

	local baseAttack = object:getRandomAttack(self.attackType);
    local totalAttack = baseAttack*self.growDamage + self.baseDamage;

	local map = MapManager:getMap(object:getMap());
    local objPos = object:getPosition();
    local tarPos1 = FuncPack:nextPositionWithDir(objPos,dir,1)
	local tarPos2 = FuncPack:nextPositionWithDir(objPos,dir,2)
	local target1 = map:getObjectFromMap(tarPos1);
	local target2 = map:getObjectFromMap(tarPos2);

	if target1 then
		for k,v in pairs(target1) do
			table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack,toid=v:getID()});
		end

		--table.insert(info.attackInfos, #info.attackInfos+1, {value={type=self.attackType,attack=totalAttack, power=self.power},target=target1});
	end

	if target2 then
		for k,v in pairs(target2) do
			table.insert(info.atkValue, #info.atkValue+1, {aty=self.attackType,atk=totalAttack,toid=v:getID()});
		end
		--table.insert(info.attackInfos, #info.attackInfos+1, {value={type=self.attackType,attack=totalAttack, power=self.power},target=target2});
	end

    return info;
end
