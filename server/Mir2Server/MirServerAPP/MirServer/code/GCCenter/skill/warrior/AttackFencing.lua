ThurstFencing = class("AttackFencing", function() 
    return BaseSkill.new()
end)

--技能基本属性
function ThurstFencing:initAttribute(parameter)
    getmetatable(self):initAttribute(parameter);

    --预留给子类的特效
    self.effect = engine.readActionSpriteFromIndex(parameter.sz_effect)
end