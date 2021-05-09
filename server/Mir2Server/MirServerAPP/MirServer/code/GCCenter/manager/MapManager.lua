--region NewFile_1.lua
--Author : legend
--Date   : 2015/5/21
--此文件由[BabeLua]插件自动生成



--endregion
MapManager = {}
MapManager.waitLoadingMaps = {};
MapManager.maps = {};

function MapManager:getMap(id, callfunc)
	if MapManager.waitLoadingMaps[id] then
        --print("already exist loading map"..id);
        return MapManager.waitLoadingMaps[id].map;
    end

	if MapManager.maps[id] then
		--FuncPack:print("already exist loaded map"..id);
		return MapManager.maps[id];
	end

	local conf = MapConf[id];
    if not conf then
		--FuncPack:print("loading map"..id.." failed");
        return nil;
    else
        return MapManager:loadingMap(conf, callfunc);
    end
end

function MapManager:loadingMap(conf, callfunc)
	local map = Map:create();
	map:initAll(conf);
	map:retain();

	--print("add load map"..conf.id.."   ip:"..tostring(map));
    MapManager.waitLoadingMaps[conf.id] = {map=map, callfunc=callfunc};

    return map;
end

function MapManager:launch()
    if not MapManager.loadingMapScheduler then
        local function loadingMapFunc()
            MapManager:loadingMapFunc();
        end

        local scheduler = cc.Director:getInstance():getScheduler();
        self.loadingMapScheduler = scheduler:scheduleScriptFunc(loadingMapFunc, 1, false);
    end
end

function MapManager:loadingMapFunc()
    for k,v in pairs(MapManager.waitLoadingMaps) do
        if v.map:getLoadingDataComplete() == 1 then
            v.map:updateMapSize();
			v.map:initConf();
            --v.map:initMonster();

			if v.callfunc then
				v.callfunc(v.map);
			end

			--标记
            MapManager.maps[k] = v.map;
            MapManager.waitLoadingMaps[k] = nil;
        end
    end
end
