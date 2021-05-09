SpeedUpSpell = class("SpeedUpSpell",  function()
    return BuffSpell:new();
end)

function SpeedUpSpell:ctor()
end

function SpeedUpSpell:calculate(object)
	if not self.isRun then
		object:slashSpeedUp(self.baseDamage);
	end
end

function SpeedUpSpell:getDamage(object, num)
	return num;
end

function SpeedUpSpell:close(object)
	if self.isRun then
		object:slashSpeedUp(-self.baseDamage);
	end

	self.isRun = nil;
end
