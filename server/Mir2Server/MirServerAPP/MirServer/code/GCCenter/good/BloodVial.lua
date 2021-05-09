BloodVial = class("BloodVial", function()
    return Item:new();
end)

function BloodVial:ctor()
end

function BloodVial:initAttribute(parameter)
	self.name = parameter.name
	self.addBlood = parameter.maxHp or 0;
	self.addMagic = parameter.maxMp or 0;
end

function BloodVial:use(actor)
	local itemIndex = actor:getItemGridIndex(self.id);
	local pid = actor:getID();
	local item = Game.delItem(pid, itemIndex);
	local ret,sql = DBServer:doSql("delete from data_item where itemid="..self.id);

	if item and ret then
		actor:addHp(self.addBlood);
		actor:addMp(self.addMagic);

		GCCenter.sendSingleActor(actor, {id="REMOVE_ITEM", pid=pid, itemId=self.id});

		return true, {id="BC_ACTOR_HEAL", pid=pid, blood=self.addBlood, magic=self.addMagic, curHp=actor:getHp(), curMp=actor:getMp(),ret=1};
	else
		return false, {id="BC_ACTOR_HEAL", pid=pid, error="use item failed",ret=0};
	end
end
