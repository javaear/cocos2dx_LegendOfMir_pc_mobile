CallPet = class("CallPet",  function()
    return RangeSpell:new();
end)

function CallPet:ctor()
end

function CallPet:run(object, value)
	self:markCastTime(object);

	GCCenter.sendSameScreenBroadcast(object, {id="BC_ACTOR_ATTACK", fromid=object:getID(), skillName=self.name, values=values,srcPos=object:getPosition()});

    self:calculate(object, values);

	self.isRun = true;
end

function CallPet:update(object)
end

function CallPet:calculate(object)
	self.calcDamageTimer:scheduleOnce(object:getCastSpeed(), function(param)
		--callPet
		local map = MapManager:getMap(object:getMap());
		local freeId = map:getNextFreeId();
		local masterPos = object:getPosition();
		local nearPos = map:getEmptyObjectPosition(masterPos);

		if not nearPos then
			nearPos = masterPos;
		end

		Game.addMonForPet(object:getID(), {pid=freeId,style=self.petId, x=nearPos.x, y=nearPos.y, skill={{skillid=9,level=0,exc=0}}});
	end)
end
