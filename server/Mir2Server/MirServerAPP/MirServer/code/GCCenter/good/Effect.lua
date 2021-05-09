Effect = {}
Effect.__index = Effect

function Effect:create()
    local effect = {};
    setmetatable(effect,Effect)
    effect:ctor();
    return effect
end

function Effect:ctor()
    self.time = 20
end