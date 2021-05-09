ThurstFencing = class("ThurstFencing", function() 
    return BaseSkill:new();
end)

function ThurstFencing:ctor()
    getmetatable(self):ctor();
end

function ThurstFencing:satifyCastPremise(object, values)
    if values.name ~= "slash" and values.name ~= self.name then
        return false;
    end

    if self.triggerRate then
        local rate = FuncPack:getRandomNumber(1, 100)

        if rate > self.triggerRate * 100 then
            return false
        end
    end
    
    if object:checkSlashClockRing() == false then
        return false;
    end

    return true;
end

function ThurstFencing:remove()
    if self.effect then
        self.effect:remove();
    end
end