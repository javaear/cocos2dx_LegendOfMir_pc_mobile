MainCity = class("MainCity")

function MainCity:ctor()
	self.map = nil;
end

function MainCity:initMap(mapid)
	self.map = MapManager:getMap(id, function()
		LogPrint("loading map id:"..id)
		loadMapCount = loadMapCount + 1;

		if loadMapCount == #MapConf then
			LogPrint("all map load completed");
		end
	end)
end

function MainCity:update(dt)

end
