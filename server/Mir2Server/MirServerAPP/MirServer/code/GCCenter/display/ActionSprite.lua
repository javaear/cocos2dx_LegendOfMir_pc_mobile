ActionSprite = {}
ActionSprite.__index = ActionSprite

function ActionSprite:create()
    local sprite = {};
    setmetatable(sprite,ActionSprite)
    sprite:ctor();
    return sprite;
end

function ActionSprite:ctor()
    self.actionName = "";
    self.actionList = {};
    self.actionOffset = {};
    self.sprite = nil;
    self.lastAction = nil;
    self.actionCount = 0;
end

function ActionSprite:addActions(actions)
    for k,v in pairs(actions) do
        self:addAction(v, k);
    end
end

function ActionSprite:addActionOffset(actionName, offsetTable)
    if self.actionList[actionName] == nil then
        return -1;
    end
    
    self.actionOffset[actionName] = offsetTable;
end

function ActionSprite:initSpriteFromFrameCache(name)
    self.sprite = engine.initSpriteFromFrameCache(name);
    
    return self.sprite;
end

function ActionSprite:addAction(animate, actionName)
    if self.sprite == nil then
        self:interInitSprite(animate);
    end

    if self.actionList[actionName] ~= nil then
        return -1;
    end

    self.actionList[actionName] = animate;
    
    --retain,保持动画不被销毁
    animate:retain();

    self.actionCount = self.actionCount + 1;
    
    return 1;
end

function ActionSprite:interInitSprite(animate)
    local animation = animate:getAnimation();
    local animationframe = animation:getFrames()[1]
    local spriteFrame = animationframe:getSpriteFrame();
    self.sprite = engine.initSpriteFromSpriteFrame(spriteFrame);--et.SpriteX:createWithSpriteFrame(spriteFrame)
    self.sprite:setAnchorPoint(0, 0)
    self.sprite:retain();
end

--销毁所属动作集
function ActionSprite:release()
    for k,v in pairs(self.actionList) do
       v:release(); 
    end
    
    self.sprite:release();
end

function ActionSprite:retain()
    --self.sprite:retain();
end

function ActionSprite:runSameAction(actionName)
    if self.actionName ~= actionName then
        return nil;
    end
    
    return true;
end

function ActionSprite:runActions(actionArray)
    local sequence = cc.Sequence:create(actionArray);
    self.sprite:runAction(sequence);
end

function ActionSprite:runAction(actionName, actionArray)
    self.actionName = actionName;

    if self.actionList[actionName] == nil then
        return -1;
    end
    
    if actionArray == nil then
        self.sprite:runAction(self.actionList[actionName]);
        self.lastAction = self.actionList[actionName];
    else
        table.insert(actionArray, 1, self.actionList[actionName]);
        
        local sequence = cc.Sequence:create(actionArray);
        self.sprite:runAction(sequence);
        self.lastAction = sequence;
    end

    return 1;
end

function ActionSprite:getLastAction()
    return self.lastAction;
end

function ActionSprite:stopActionWithName(actionName)
    if self.actionList[actionName] == nil then
        return -1;
    end
    
    self.sprite:runAction(self.actionList[actionName]);
    
    return 1;
end

function ActionSprite:stopAction(action)
    self.sprite:stopAction(action);

    return 1;
end

function ActionSprite:stopAllActions()
    self.sprite:stopAllActions();
end

function ActionSprite:addTo(parent, zOrder)
    if not zOrder then
        zOrder = 0;
    end

    parent:addChild(self.sprite, zOrder)
end

function ActionSprite:remove()
    if self.sprite:getParent() then
        self.sprite:getParent():removeChild(self.sprite)
    end
end

function ActionSprite:setPosition(x, y)
    self.sprite:setPosition(x, y);
end

function ActionSprite:getPosition()
    local _x, _y = self.sprite:getPosition();
    return {x=_x, y=_y};
end

function ActionSprite:setEffect(effectid)
    self.sprite:setEffect(effectid);
end

function ActionSprite:setLocalZOrder(zOrder)
    self.sprite:setLocalZOrder(zOrder);
end

function ActionSprite:setVisible(visible)
    self.sprite:setVisible(visible);
end

function ActionSprite:setEdging(outlineSize, color)
    local contentSize = self.sprite:getContentSize();
    self.sprite:setEdging(outlineSize, color, contentSize);
end

function ActionSprite:getVisible()
    return self.sprite:getVisible();
end

function ActionSprite:getActionCount()
    return self.actionCount;
end

function ActionSprite:getParent()
    return self.sprite:getParent();
end

function ActionSprite:setActionsSpeed(names, duration)
    for k,name in pairs(names) do
        local action = self.actionList[name];

        if action then
            action:setDuration(duration);
        end
    end
end

function ActionSprite:setCurrFrameIndex(index)
    if self.actionList[self.actionName] == nil then
        return -1;
    end
    
    local animation = self.actionList[self.actionName]:getAnimation();
    local animationframe = animation:getFrames()[index]
    local spriteFrame = animationframe:getSpriteFrame();
    
    self.sprite:setSpriteFrame(spriteFrame);
end

function ActionSprite:isRunning()
    return self.sprite:isRunning();
end

function ActionSprite:setAllActionsSpeed(duration)
    for k,v in pairs(self.actionList) do
        v:setDuration(duration);
    end
end

function ActionSprite:release()
    self:stopAllActions();
    
    for k,v in pairs(self.actionList) do
        v:release();
    end
    
    self.sprite:release();
    self:remove();
end