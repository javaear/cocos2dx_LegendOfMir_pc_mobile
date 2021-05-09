--region NewFile_1.lua
--Author : legend
--Date   : 2015/4/21
--此文件由[BabeLua]插件自动生成



--endregion
currChoose = nil;
currChooseItem = nil;

Bag = class("Bag", function()
    return cc.Layer:create();
end)

function Bag:ctor()
    self:setSize(8,5);
end

function Bag:setSize(row, col)
    self.itemGroup = {};
    self.itemBackGroup = {};
    self.row = row;
    self.col = col;
    self.useItemClock = Clock:new();
    self.useItemClock:setRingTimeDelta(2);

    self:initUI();
	self:registListener();
end

function Bag:setItemData(items)
    for k,v in pairs(items) do
        self:addItemWithIndex(v, k);
    end
end

function Bag:initUI()
    local back = engine.initSprite("ui/000336.png");
    back:setAnchorPoint(0,0);
    back:setTag(0);
    self:addChild(back);

    local len = self.row * self.col;

    for i=0, len-1 do
        local itemCol = math.modf(i/self.row);
        local itemRow = math.fmod(i, self.row);

        local itemBack = cc.Node:create();
        itemBack:setTag(i);
        itemBack:setPosition(26 + (itemRow)*37.5, 216 - (itemCol)*37.5);
        self.itemBackGroup[i+1] = itemBack;
        self:addChild(itemBack);
    end

    --gold label
    self.goldLabel = engine.initLabel();
    self.goldLabel:setPosition(100, 40);
    self.goldLabel:enableOutline(cc.c3b(100,100,255), 2);
    self.goldLabel:enableShadow(cc.c4b(100,100,255,0));
    self:addChild(self.goldLabel);

    --close button
    local function closeWindow()
        self:hide();
    end

    local item = cc.MenuItemImage:create("ui_common/000003.png","ui_common/000005.png");
    item:registerScriptTapHandler(closeWindow)
    local menu = cc.Menu:create(item);
    menu:setPosition(345, 267);
    self:addChild(menu);
end

function Bag:showGold(num)
    self.goldLabel:setString(num);
end

function Bag:addItem(item)
    local len = self.row * self.col;

    for i=1, len do
        if not self.itemGroup[i] then
            self:addItemWithIndex(item,i);
            return true;
        end
    end

    return false;
end

function Bag:addItemWithIndex(item, index)
	if index == nil then
		print(debug.traceback());
	end

    if index > self.row * self.col then
        return false;
    end

    self.itemGroup[index] = item;

    self:addToUI(item, index);
end

function Bag:addToUI(item, i)
    item:setBagSpritePosition(0, 0);

    --ui
    item:addToBag(self.itemBackGroup[i], 0);
end

function Bag:clearItem()
    for k,v in pairs(self.itemGroup) do
        self:removeItem(k);
    end
end

function Bag:removeItem(i)
    local item = self.itemGroup[i];

    --ui
    if item then
        item:removeFromBag();
        self.itemGroup[i] = nil;
    end

    return item;
end

function Bag:addItemUI(item, i)
    item:addToBag(self.itemBackGroup[i], 0);
end

function Bag:removeItemUI(i)
    local item = self.itemGroup[i];

    --ui
    item:removeFromBag();

    return item;
end

function Bag:show()
    self:setVisible(true);
end

function Bag:hide()
    self:setVisible(false);
end

function Bag:getChooseItem()

end

function Bag:getCurrChooseIndex()
    return currChoose;
end

function Bag:isTouchTitle(point)
    local bagX,bagY = self:getPosition();

    if point.x >= 24 + bagX and point.x <= bagX + 324 and
        point.y >= bagY + 254 and point.y <= bagY + 284 then
        return true;
    end

    return false;
end

function Bag:getTouchItemIndex(point)
    for i=1, #self.itemBackGroup do
        local itemBack = self.itemBackGroup[i];
        local location = itemBack:convertToNodeSpace(point)
        local rect = cc.rect(0,0,37.5, 37.5)

        if cc.rectContainsPoint(rect,location) then
            return i;
        end
    end

    return nil;
end


function Bag:useItem(touch)
    local point = touch:getLocation();
    local itemIndex = self:getTouchItemIndex(point);

    if itemIndex then
        local item = self.itemGroup[itemIndex];

        if item then
            if self.pressItem and item == self.pressItem and self.useItemClock:ring()==false then
                engine.dispachEvent("removeItem", itemIndex);
                engine.dispachEvent("useItem", item);

                self.pressItem = nil;

                return true;
            else
                self.pressItem = item;
                self.useItemClock:markRingTime();
            end
        end
    end

    return false;
end

function Bag:touchItem(touch)
    if currChooseItem then
        return;
    end

    local point = touch:getLocation();
    --点击标题
    if self:isTouchTitle(point) then
        self.pressTitlePoint = point;
        self.oldBagX,self.oldBagY = self:getPosition();
		return;
    end

    local itemIndex = self:getTouchItemIndex(point);
    if itemIndex then
        currChooseItem = self:removeItem(itemIndex);
        if currChooseItem then
            local parent = self:getParent();
            currChoose = itemIndex;
            currChooseItem:addToBag(parent, 0);

            self:movingItem(point);
        end
    end

    return true;
end


function Bag:movingItem(point)
    if currChooseItem then
        currChooseItem:setBagSpritePosition(point.x-19, point.y-19);
    end
end

function Bag:interChangeItem(index1, index2)
    local item1 = self:removeItem(index1);
    local item2 = self:removeItem(index2);

    if item1 then
        item1:setBagSpritePosition(0,0);
        self:addItemWithIndex(item1, index2);
    end

    if item2 then
        item2:setBagSpritePosition(0,0);
        self:addItemWithIndex(item2, index1);
    end

    engine.dispachEvent("changeItem", {index1=index1, index2=index2})
end

function Bag:endMoveItem()
    if not currChooseItem then
        return;
    end

    local i = currChoose;
    local currTouchItemIndex = self:getTouchItemIndex(self.mousePoint);

    currChooseItem:removeFromBag();
    self:addItemWithIndex(currChooseItem, i);

    if currTouchItemIndex and i ~= currTouchItemIndex then
        self:interChangeItem(currTouchItemIndex, i);
    end

    currChoose = nil;
	currChooseItem = nil;
end



function Bag:moveingTitle(point)
    if self.pressTitlePoint then
        self:setPosition({x=self.oldBagX+point.x-self.pressTitlePoint.x,
            y=self.oldBagY+point.y-self.pressTitlePoint.y});
    end
end

function Bag:endMoveTitle(point)
    self.pressTitlePoint = nil;
end

function Bag:pointIsInBackground(point)
    local background = self:getChildByTag(0);
    local location = background:convertToNodeSpace(point)
    local size = background:getContentSize();
    local rect = cc.rect(0,0, size.width, size.height)

    if cc.rectContainsPoint(rect,location) then
        return true;
    end

    return false;
end

---------------------
---
---onTouchFunction
---
---------------------
function Bag:onTouchesBegan(touch, events)
    self.mousePoint = touch:getLocation();
    if self:useItem(touch) == false then
        self:touchItem(touch);
    end
end

function Bag:onTouchesMoved(touch, events)
    local point = touch:getLocation();
    self.mousePoint = point;

    self:movingItem(point);
    self:moveingTitle(point);
end

function Bag:onTouchesEnded(touches, events)
    self:endMoveItem();
    self:endMoveTitle()
end


function Bag:registListener()
    local function onTouchEnded(touch, event)
        --print("end");
        self:onTouchesEnded(touch, event);
    end

    local function onTouchBegan(touch, event)
        --print("began");
        if self:isVisible() == false then
            return false;
        end

        self:onTouchesBegan(touch, event);

        return self:pointIsInBackground(touch:getLocation());
    end

    local function onTouchMoved(touch, event)
        self:onTouchesMoved(touch, event);
    end

    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true);
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN)
    listener:registerScriptHandler(onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED)
    listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED)

    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self);
end
