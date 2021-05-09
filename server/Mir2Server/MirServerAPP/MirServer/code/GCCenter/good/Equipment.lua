Equipment = class("Equipment", function()
    return Item:new();
end)

function Equipment:create()
    local equip = {}
    setmetatable(equip,Equipment)
    equip:ctor();
    return equip;
end

function Equipment:ctor()
    --Attribute
    self.attribute = Attribute:create();

    --需要的条件
    self.needLevel = 0;
    self.needStrength = 0;
    self.needMagic = 0;

    --精灵
    --[[
    self.mapSprite = nil
    self.bagIconSprite = nil
    self.mapIconSprite = nil;
    self.bigIconSprite = nil;]]
end

--是否满足穿戴条件
function Equipment:justice(actor_attribute)
    if actor_attribute.level < self.needLevel then
        return false;
    end

    if actor_attribute.needStrength < self.needStrength then
        return false;
    end

    if actor_attribute.magic < self.needMagic then
        return false;
    end

    return true;
end

function Equipment:use(actor, extraContent)
	--justice is succeed


	--use
	local itemIndex = actor:getItemGridIndex(self.id);
	local pid = actor:getID();
	local item = Game.delItem(pid, itemIndex);

	if self.type >= 11 then
		return false,{id="BC_ACTOR_USE_EQUIP", ret=0, itemid=self.id,error="item type is not equip"};
	end

	local gridIndex = actor:getNextFreeItemSpace();
	local lastEquip = Game.useEquip(pid, item, extraContent);
	if lastEquip then
		if lastEquip ~= 1 then
			Game.addItem(pid, lastEquip, gridIndex);
		end

		local equipData = item:getBaseData();

		return true, {id="BC_ACTOR_USE_EQUIP", pid=pid, equipData=equipData,ret=1,gridIndex=gridIndex,itemIndex=itemIndex, extraContent=extraContent};
	else
		return false, {id="BC_ACTOR_USE_EQUIP", pid=pid, itemid=self.id,ret=0, error="use equip failed for database"};
	end
end

function Equipment:initAttribute(param)
    self.attribute:init(param);

    --装备特有属性 特殊效果,名称,限制条件,描述,类型,id
    self.type = param.type;
    self.name = param.sz_name;
    --self:initSprite(param);
end

function Equipment:getType()
    return self.type;
end

function Equipment:levelUp()

end
