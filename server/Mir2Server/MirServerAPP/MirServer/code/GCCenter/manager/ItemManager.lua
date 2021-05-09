ItemManager = {}
ItemManager.items = {}

function ItemManager:getItem(info)
	if ItemManager.items[info.itemid] then
		return ItemManager.items[info.itemid];
	end

    return nil;
end

function ItemManager:isEquip(itype)
	if itype <= 10 then
		return true;
	end

	return nil;
end

function ItemManager:registItem(data)
	if ItemManager.items[data.itemid] then
		TraceError("exist same id:"..data.itemid);
		return --ItemManager.items[info.itemid];
	end

	local equipConf = EquipmentConf[data.typeid];
	if equipConf then
		local createFunc = loadstring("return "..equipConf.sz_class..":new()")
		local item = createFunc();
		item.pid = data.pid;
		item:retain();
		item:initAttribute(equipConf);
		item:setBaseData({typeid=data.typeid, itemid=data.itemid});
		item.id = data.itemid;
		--ItemManager:registItem(equip);
		ItemManager.items[data.itemid] = item;

		return item;
	else
		TraceError("have no item typeid:"..data.typeid);
	end

    return nil;
end

function ItemManager:createItems(typeid, pid, gridIndex, count)
	local equipConf = EquipmentConf[typeid];
	if not equipConf then
		TraceError("no found this type equip:"..typeid);
		return nil;
	end

	local sql = DBServer:formatSqlForInsert("data_item", {"pid", "typeid", "isEquip", "count", "gridIndex"},
		{pid,typeid,0,1,gridIndex});

	local sqlList = "";
	for i=1, count do
		sqlList = sqlList..sql;
	end

	local items = {};

	local ret = DBServer:doSql(sqlList, true);

	if ret then
		local datas = DBServer:getLastInsertRowForCount("data_item", count);
		for k,v in pairs(datas) do
			local item = ItemManager:registItem(v);

			table.insert(items, #items + 1, item);
		end
	end

	return items;
end

function ItemManager:createItem(typeid, pid, gridIndex)
	local equipConf = EquipmentConf[typeid];
	if not equipConf then
		TraceError("no found this type equip:"..typeid);
		return nil;
	end

	local ret,sql, data = DBServer:insert("data_item", {"pid", "typeid", "isEquip", "count", "gridIndex"},
		{pid,typeid,0,1,gridIndex});

	if not ret then
		print("add item type:"..typeid.." failed for "..pid);
		return nil;
	end

	data.pid = pid;

	ret = ItemManager:registItem(data);
	return ret;
end

--function ItemManager:updateItem(typeid, pid)

function ItemManager:clear()
	for k,v in pairs(ItemManager.items) do
		v.release();
	end

	ItemManager.items = {};
end
