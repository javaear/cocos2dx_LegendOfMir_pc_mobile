--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/22
--此文件由[BabeLua]插件自动生成



--endregion
StatueWindow = class("StatueWindow", function()
    return cc.Layer:create();
end)

function StatueWindow:clear()
	for k,v in pairs(self.equipGroup) do
		StatueWindow:removeEquip(k);
	end
end

function StatueWindow:setNewEquips(equips)
	StatueWindow:clear();

	for k,v in pairs(equips) do
		StatueWindow:addEquip(v);
	end
end

function StatueWindow:showPanel(index)
    local panel1 = self.back:getChildByName("AttributePanel")
    local panel2 = self.back:getChildByName("Panel2")
    local panel3 = self.back:getChildByName("Panel3")

    if index == 1 then
        panel1:setVisible(true);
        panel2:setVisible(false);
        panel3:setVisible(false);
    elseif index == 2 then
        panel1:setVisible(false);
        panel2:setVisible(true);
        panel3:setVisible(false);
    elseif index == 3 then
        panel1:setVisible(false);
        panel2:setVisible(false);
        panel3:setVisible(true);
    end
end

function StatueWindow:showAttributePanel(index)
    local panel1 = self.back:getChildByName("AttributePanel")
    local equip = panel1:getChildByName("equip");
    local attri = panel1:getChildByName("attribute");
    local pPanel3 = panel1:getChildByName("Sprite_7");
    local pPanel4 = panel1:getChildByName("Sprite_8");

    if index == 1 then
        equip:setVisible(true);
        attri:setVisible(false);
        pPanel3:setVisible(false);
        pPanel4:setVisible(false);
    elseif index == 2 then
        equip:setVisible(false);
        attri:setVisible(true);
        pPanel3:setVisible(false);
        pPanel4:setVisible(false);
    elseif index == 3 then
        equip:setVisible(false);
        attri:setVisible(false);
        pPanel3:setVisible(true);
        pPanel4:setVisible(false);
    elseif index == 4 then
        equip:setVisible(false);
        attri:setVisible(false);
        pPanel3:setVisible(false);
        pPanel4:setVisible(true);
    end
end

function StatueWindow:ctor()
    local rootNode = cc.CSLoader:createNode("StatueWindow.csb");
    local back = rootNode:getChildByName("back");
    back:getParent():removeChild(back);
    self:addChild(back);

    local Panel1Label = back:getChildByName("Panel1Label")
    local Panel2Label = back:getChildByName("Panel2Label")
    local Panel3Label = back:getChildByName("Panel3Label")

    local panel1 = back:getChildByName("AttributePanel")
    local panel2 = back:getChildByName("Panel2")
    local panel3 = back:getChildByName("Panel3")

    Panel1Label:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            panel1:setVisible(true);
            panel2:setVisible(false);
            panel3:setVisible(false);
        end
    end);

    Panel2Label:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            panel1:setVisible(false);
            panel2:setVisible(true);
            panel3:setVisible(false);
        end
    end);

    Panel3Label:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            panel1:setVisible(false);
            panel2:setVisible(false);
            panel3:setVisible(true);
        end
    end);

    local equipLabel = panel1:getChildByName("equipLabel");
    local attriLabel = panel1:getChildByName("attributeLabel");
    local pLabel3 = panel1:getChildByName("pLabel3");
    local pLabel4 = panel1:getChildByName("pLabel4");

    local equip = panel1:getChildByName("equip");
    local attri = panel1:getChildByName("attribute");
    local pPanel3 = panel1:getChildByName("Sprite_7");
    local pPanel4 = panel1:getChildByName("Sprite_8");

    equipLabel:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            equip:setVisible(true);
            attri:setVisible(false);
            pPanel3:setVisible(false);
            pPanel4:setVisible(false);
        end
    end);

    attriLabel:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            equip:setVisible(false);
            attri:setVisible(true);
            pPanel3:setVisible(false);
            pPanel4:setVisible(false);
        end
    end);

    pLabel3:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            equip:setVisible(false);
            attri:setVisible(false);
            pPanel3:setVisible(true);
            pPanel4:setVisible(false);
        end
    end);

    pLabel4:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            equip:setVisible(false);
            attri:setVisible(false);
            pPanel3:setVisible(false);
            pPanel4:setVisible(true);
        end
    end);

    local nameLabel = back:getChildByName("nameLabel")
    nameLabel:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.began then
            self.beganPoint = nameLabel:getTouchBeganPosition();
            local x, y = self:getPosition();
            self.lastWindowPoint = {x=x, y=y};
        elseif eventTouchType == ccui.TouchEventType.moved then
            if self.beganPoint then
                local mousePoint = nameLabel:getTouchMovePosition();
                local movePoint = {x=mousePoint.x-self.beganPoint.x,
                    y=mousePoint.y-self.beganPoint.y};
                self:setPosition({x=self.lastWindowPoint.x+movePoint.x,
                    y=self.lastWindowPoint.y+movePoint.y});
            end
        elseif eventTouchType == ccui.TouchEventType.ended then
            self.beganPoint = nil;
        end
    end);

    local closeButton = back:getChildByName("closeButton")
    closeButton:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
            self:setVisible(false);
        end
    end);

	--equipBack
	local equipBack = panel1:getChildByName("equipBack");
	local clothesBack = equipBack:getChildByName("clothesBack");
	local weaponBack = equipBack:getChildByName("weaponBack");
	local helmetBack = equipBack:getChildByName("helmetBack");
	local necklaceBack = equipBack:getChildByName("necklaceBack");
	local ring1Back = equipBack:getChildByName("ring1Back");
	local ring2Back = equipBack:getChildByName("ring2Back");
	local bangle1Back = equipBack:getChildByName("bangle1Back");
	local bangle2Back = equipBack:getChildByName("bangle2Back");
	local helpBack = equipBack:getChildByName("helpBack");

	self:registBackButtonListener(clothesBack, 1);
	self:registBackButtonListener(weaponBack, 2);
	self:registBackButtonListener(helmetBack, 3);
	self:registBackButtonListener(necklaceBack, 4);
	self:registBackButtonListener(ring1Back, 5);
	self:registBackButtonListener(ring2Back, 6);
	self:registBackButtonListener(bangle1Back, 7);
	self:registBackButtonListener(bangle2Back, 8);
	self:registBackButtonListener(helpBack, 9);


    self.equipPanel = equip;
	self.equipBack = equipBack;
    self.back = back;
    self.equipGroup = {};
end

function StatueWindow:registBackButtonListener(backButton, btype)
	backButton:setVisible(true);
	backButton:addTouchEventListener(function(event, eventTouchType)
        if eventTouchType == ccui.TouchEventType.ended then
        end

		if eventTouchType == ccui.TouchEventType.began then
			local equip = self.equipGroup[btype]

			if equip == nil then
				return;
			end

			engine.dispachEvent("removeEquip", equip);
			engine.dispachEvent("addItem", equip);
		end
    end);
end

function StatueWindow:setName(name)
    local nameLabel = self.back:getChildByName("nameLabel")
    nameLabel:setString(name);
end

function StatueWindow:updateAttribute(attribute)
    local panel1 = self.back:getChildByName("AttributePanel")
    local attributePanel = panel1:getChildByName("attribute");
    local physicalAtkLabel = attributePanel:getChildByName("physicalAtk");
    local physicalDfsLabel = attributePanel:getChildByName("physicalDefense");
    local magicAtkLabel = attributePanel:getChildByName("magicAtk");
    local magicDfsLabel = attributePanel:getChildByName("magicDefense");

    physicalAtkLabel:setString(attribute.atk[1][1].."-"..attribute.atk[1][2]);
    physicalDfsLabel:setString(attribute.dfs[1]);

    magicAtkLabel:setString(attribute.atk[2][1].."-"..attribute.atk[2][2]);
    magicDfsLabel:setString(attribute.dfs[2]);
end

function StatueWindow:setSex(sex)
    local man_back = self.equipPanel:getChildByName("man_back")
    local woman_back = self.equipPanel:getChildByName("woman_back")

    if sex == 0 then
        man_back:setVisible(true);
        woman_back:setVisible(false);
    else
        man_back:setVisible(false);
        woman_back:setVisible(true);
    end
end

function StatueWindow:removeEquip(etype)
    local equip = self.equipGroup[etype];

    if equip then
        local equipIcon = equip:getStateIcon();
        self.equipPanel:removeChild(equipIcon);
        self.equipGroup[etype] = nil
    else
        --print("equip type:"..etype);
        --print("equip:"..tostringex(self.equipGroup));
    end

    return equip;
end

function StatueWindow:addEquip(equip)
    if equip:getType() > 10 then
        return;
    end

    local etype = equip:getType();
    local equipIcon = equip:getStateIcon();
    local node = nil;

    if etype == 1 then
        node = self.equipPanel:getChildByName("clothes")
    elseif etype == 2 then
        node = self.equipPanel:getChildByName("weapon")
    elseif etype == 3 then
        node = self.equipPanel:getChildByName("helmet")
    elseif etype == 4 then
        node = self.equipPanel:getChildByName("necklace")
    elseif etype == 5 then
        node = self.equipPanel:getChildByName("bangle1")
    elseif etype == 6 then
        node = self.equipPanel:getChildByName("bangle2")
    elseif etype == 7 then
        node = self.equipPanel:getChildByName("ring1")
    elseif etype == 8 then
        node = self.equipPanel:getChildByName("ring2")
    elseif etype == 9 then
    elseif etype == 10 then
    end

    local x,y = node:getPosition();
	print(x.."---"..y);
    equipIcon:setPosition(x, y);
    self.equipPanel:addChild(equipIcon);
    self.equipGroup[etype] = equip;
    --[[
    self.parts =
    {
        [1] = nil,   --衣服
        [2] = nil,   --武器
        [3] = nil,   --头盔
        [4] = nil,   --项链
        [5] = nil,   --手镯
        [6] = nil,   --手镯
        [7] = nil,   --戒指
        [8] = nil,   --戒指
        [9] = nil,   --头发
        [10] = nil,  --待定
    }]]
end
