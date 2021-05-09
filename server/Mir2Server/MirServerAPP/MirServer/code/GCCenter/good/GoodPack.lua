GoodPack = class("GoodPack", function()
    return Item:new();
end)

function GoodPack:ctor()
end

function GoodPack:initAttribute(parameter)
	self.name = parameter.name
	self.itemTypeId = parameter.maxHp;
	self.itemCount = parameter.maxMp;
end

function GoodPack:use(actor)
	local restCount = actor:getItemMaxCount() - actor:getItemCurCount();

	if restCount < self.itemCount then
		return nil, {id="Good_Pack", pid=actor:getID(), error="no enough space",ret=0};
	end

	local ret = Game.netDelItem(actor:getID(), self.id);
	if ret then
		Game.addItemWithTypeId(actor:getID(), self.itemTypeId, self.itemCount);
	end

	return false, nil;
end
