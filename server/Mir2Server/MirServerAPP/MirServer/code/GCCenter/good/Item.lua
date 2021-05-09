Item = class("Item", function()
    return cc.Node:create();
end)

function Item:create()
    local object = {}
    setmetatable(object,Item)
    object:ctor();
    return object;
end

function Item:ctor()
    self.name = ""
    self.limitLevel = 0
    self.description = ""
    self.type = 0

    --物品功能
    self.func = nil
	self.position = {x=0, y=0}
end

function Item:setBaseData(data)
	self.baseData = data;
end

function Item:getBaseData()
	return self.baseData;
end

function Item:use(actor)

end

function Item:initAttribute(parameter)
    self.name = parameter.name
    self.description = parameter.description
    self.type = parameter.type
	self.param = parameter;
end

function Item:setPosition(x, y)
	self.position = {x=x, y=y}
end

function Item:getPosition()
	return self.position;
end

function Item:getID()
	return self.id;
end
