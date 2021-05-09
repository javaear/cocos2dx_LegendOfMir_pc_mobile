MainCityManager = {}
MainCityManager.citys = {}

function MainCityManager:createCity()
	local city = MainCity:new();
	MainCityManager.citys[#MainCityManager.citys+1] = city;

	return city;
end

function MainCityManager:getCity(id)
	return MainCityManager.citys[id]
end

function MainCityManager:release()
	for k,v in pairs(MainCityManager.citys) do
		v:release();
	end

	MainCityManager.citys = {};
end
