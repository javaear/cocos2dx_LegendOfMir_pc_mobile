BloodBar = class("BloodBar", function()
    return cc.Layer:create();
end)

function BloodBar:ctor()
    self.offset = 70;
    self.background = engine.initSprite("prguse/prguse_000000.png");

    local sp = engine.initSprite("prguse/prguse_000001.png");
    self.bloodBar = cc.ProgressTimer:create(sp)
    self.bloodBar:setType(cc.PROGRESS_TIMER_TYPE_BAR);
    self.bloodBar:setMidpoint({x=0, y=0.5})
    self.bloodBar:setBarChangeRate({x=1, y=0});
    
    self:addChild(self.background);
    self:addChild(self.bloodBar);
end

function BloodBar:setPercentage(num)
    self.bloodBar:setPercentage(num);
end

function BloodBar:setPosition(x, y)
    self.bloodBar:setPosition(x, y + self.offset)
    self.background:setPosition(x, y + self.offset)
end

function BloodBar:getOffset()
    return self.offset;
end