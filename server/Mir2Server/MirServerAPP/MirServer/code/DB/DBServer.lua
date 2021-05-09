DBServer = {}
DBServer.accountInfoGroup = {}
DBServer.majorIDCache = {}
DBServer.sqlCache = {}
local DBServerCache = {}


function DBServer:init(dbname)
    local sqliter = et.SQLiter:new();

    local ret = sqliter:initSql(dbname);

	if ret == true then
		sqliter:retain();
		self.sqliter = sqliter;
	end

	return ret;
end

function DBServer:doSql(sqlStr, isExcRighNow)
	if isExcRighNow then
		local ret = self.sqliter:exec(sqlStr);
		return ret, sqlStr;
	else
		if #DBServer.sqlCache < 10 then
			table.insert(DBServer.sqlCache, #DBServer.sqlCache + 1, sqlStr);
			return true,sqlStr;
		end

		local sql = "";
		for k, v in pairs(DBServer.sqlCache) do
			sql = sql..v..";";
		end
		sql = sql..sqlStr..";";

		local ret = self.sqliter:exec(sql);
		if not ret then
			TraceError("do sql "..sql.." failed");
		end

		DBServer.sqlCache = {};
		return ret, sql;
	end
end

function DBServer:select(tablename, selectKeys, condition)
    local keyStr = "";
    local conditionStr = "";
	local index = TableToString(condition);

	local keyStr = self:tableToSqlFormat(selectKeys, ",");
	local conditionStr = self:tableToSqlFormatEx(condition, "and");

    local sql = "select "..keyStr.." from "..tablename;

    if conditionStr ~= "" then
       sql = sql.." where "..conditionStr;
    end

	----print("select sql:"..sql);
    local ret = self.sqliter:getTable(sql);

	return self:retToData(ret, index, tablename);
end

function DBServer:retToData(ret, index, tablename)
	if ret == "" then
		return nil;
	else
		if not DBServerCache.tablename then
			DBServerCache.tablename = {};
		end

		if not DBServerCache.tablename[index] then
			DBServerCache.tablename[index] = {};
		end

		local retTable = stringToTable(ret);
		DBServerCache.tablename[index] = retTable;

		for key,rowValue in pairs(retTable) do
			for k, v in pairs(rowValue) do
				local atype = tableDef[tablename][k];

				if atype == "number" then
					DBServerCache.tablename[index][key][k] = tonumber(v);
				elseif atype == "string" then
					DBServerCache.tablename[index][key][k] = tostring(v);
				elseif atype == "table" then
					DBServerCache.tablename[index][key][k] = stringToTable(v);
				end
			end
		end

		----print("DBServerCache.tablename[index]:"..tostringex(DBServerCache.tablename[index]));
		return DBServerCache.tablename[index];
	end
end

function DBServer:tableToSqlFormat(values, conStr, isParseStr)
	local str = "";

	for k,v in pairs(values) do
		local tableStr = nil;
		if type(v) == "table" then
			tableStr = TableToString(v);
		else
			tableStr = v;
		end

		if isParseStr and type(v) ~= "number" then
			tableStr = "'"..tableStr.."'";
		end

       if str == "" then
           str = str..tableStr;
       else
           str = str.." "..conStr.." "..tableStr;
       end
    end

	return str;
end

function DBServer:tableToSqlFormatEx(values, conStr)
	local str = "";

	for k,v in pairs(values) do
       if str == "" then
			local value = TableToString(v);
			if type(v) == "string" or type(v) == "table" then
				value = "'"..value.."'";
			end
			str = str..k.."="..value;
       else
			local value = TableToString(v);
			if type(v) == "string" or type(v) == "table" then
				value = "'"..value.."'";
			end
			str = str.." "..conStr.." "..k.."="..value;
       end
    end

	return str;
end

function DBServer:update(tablename, updateTB, condition)
	local sql = "update "..tablename.." set";
	local updateStr = self:tableToSqlFormatEx(updateTB, ",");
	local conditionStr = self:tableToSqlFormatEx(condition, "and");

	--DBServer:update("data_actor", {worldid=2, worldpos={x=100,y=200}}, {pid=3});

	sql = sql.." "..updateStr.." where "..conditionStr;
	local ret = self:doSql(sql);

	return ret,sql;
end

function DBServer:formatSqlForInsert(tablename, keys, values)
	local keyStr = "(";
	keyStr = keyStr..self:tableToSqlFormat(keys, ",");
	keyStr = keyStr..")"

	local valueStr = "(";
	valueStr = valueStr..self:tableToSqlFormat(values, ",", true);
	valueStr = valueStr..")"

	local sql = "insert into "..tablename;
    sql = sql..keyStr.." values "..valueStr..";";

	return sql;
end

function DBServer:insert(tablename, keys, values)
	local keyStr = "(";
	keyStr = keyStr..self:tableToSqlFormat(keys, ",");
	keyStr = keyStr..")"

	local valueStr = "(";
	valueStr = valueStr..self:tableToSqlFormat(values, ",", true);
	valueStr = valueStr..")"

	local sql = "insert into "..tablename;
    sql = sql..keyStr.." values "..valueStr..";";
    local ret = self:doSql(sql, true);

	--return insert data
	if ret then
		local data = self:getLastInsertRow(tablename);
		return ret, sql, data;
	end

    return ret, sql;
end

function DBServer:getLastInsertRowForCount(tablename, count)
	local mid = self:getTableMajorID(tablename);
	local sql = "select * from "..tablename.." order by "..mid.." DESC limit "..count;
	local ret = self.sqliter:getTable(sql);
	local retTable = self:retToData(ret, 1, tablename);

	return retTable;
end

function DBServer:getLastInsertRow(tablename)
	--"select * from data_item where rowid=last_insert_rowid()"
	local sql = "select * from "..tablename.." where rowid=last_insert_rowid()";
	local ret = self.sqliter:getTable(sql);
	local retTable = self:retToData(ret, 1, tablename);

	return retTable[1];
end

function DBServer:getTableMajorID(tablename)
	--[[
	if DBServer.majorIDCache[tablename] then
		return DBServer.majorIDCache[tablename];
	end

	local sql = "select * from "..tablename.." limit 1";
	local ret = self.sqliter:getTable(sql);

	local retTable = stringToTable(ret);
	TraceError("get major id:"..tostringex(retTable));
	for k,v in pairs(retTable[1]) do
		local majorID = k;
		DBServer.majorIDCache[tablename] = majorID;

		TraceError("majorID "..majorID.." from table "..tablename);

		return majorID;
    end]]

	return tableDef[tablename].primary_key;
end

--[[
function DBServer:getAccountInfo(account, password)
    for k,v in pairs(DBServer.accountInfoGroup) do
        if v.account==account and v.password==password then
            return v;
        end
    end

    return createAccount(account, password);
end

function DBServer:createAccount(account, password)
    local sqliter = et.SQLiter:create();
    sqliter:initSql("Mir2");

    local accountInfo = {id=#DBServer.accountInfoGroup+1,account=account, password=passwrod, actors={}}
    DBServer.accountInfoGroup[#DBServer.accountInfoGroup+1] = accountInfo;

    return accountInfo;
end

function DBServer:createActor(id, name, sex, profession)
    local playerData =
    {
        name=name,
        style=profession,
        sex=sex,
        level=1,
        skills={},
        items={},
        equips={}
    }

    playerData.gold = 0;
    playerData.money = 0;
    table.insert(DBServer.clientInfoGroup[id].actors, #DBServer.clientInfoGroup[id].actors+1, playerData);

    return playerData;
end
]]
