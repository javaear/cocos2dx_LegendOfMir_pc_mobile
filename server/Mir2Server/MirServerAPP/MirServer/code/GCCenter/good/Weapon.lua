Weapon = {}
Weapon.__index = Weapon

function Weapon:create()
    local object = {}
    setmetatable(object,Weapon)
    object:ctor();
    return object;
end

function Weapon:ctor()
    --Attribute
    self.minAttack = 10
    self.maxAttack = 20
    self.addStrength = 0
    self.addMagic = 0
    self.addAligity = 0
    self.addLucky = 0
    self.addMISS = 0
    self.addDefense = 0
    self.name = ""
    self.limitLevel = 0
    self.description = ""
    self.type = 0
    self.specialEffect = {}
    
    --精灵
    self.mapSprite = nil
    self.iconSprite = nil
end

function Weapon:initAttribute(parameter)
    self.minAttack = parameter.minAttack
    self.maxAttack = parameter.maxAttack
    self.strength = parameter.strength
    self.magic = parameter.magic
    self.aligity = parameter.aligity
    self.lucky = parameter.lucky
    self.miss = parameter.miss
    self.defense = parameter.defense
    self.specialEffect = parameter.specialEffect
    self.name = parameter.name
    self.limitLevel = parameter.limitLevel
    self.description = parameter.description
    self.type = parameter.type
end

function Weapon:levelUp()

end