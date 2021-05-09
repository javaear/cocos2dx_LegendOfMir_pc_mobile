Trace = function(msg)
	print(os.date("%Y-%m-%d %X ", os.time())..msg);
end
TraceError = Trace;

check_file_exist = function(file)
	local exist = false;
	local tag_file = io.open(file);
	if tag_file ~= nil then
		exist = true;
		io.close(tag_file);
	end
	return exist;
end

toutf8 = function(tag_file)
	OS_EXEC("mv "..tag_file.." "..tag_file..".cv");
	OS_EXEC("iconv --from-code=CP936 --to-code=UTF-8 "..tag_file..".cv".." -o "..tag_file);
	--OS_EXEC("rm "..tag_file..".cv");
end

--lua时锟斤拷转锟斤拷为锟斤拷锟捷匡拷时锟斤拷锟绞?
function lua_to_db_time(lua_time)
	if type(lua_time) ~= "number" then
		error("lua_to_db_time锟斤拷锟斤拷锟剿达拷锟斤拷锟绞憋拷锟斤拷式")
		return "1970-1-1 0:0:0"
	end
    return os.date("%Y-%m-%d %X", lua_time)
end

--锟斤拷锟捷匡拷时锟斤拷转锟斤拷为lua时锟斤拷锟绞?
function db_to_lua_time(db_time)
	local time = {}
	for i in string.gmatch(db_time, "%d+") do
		table.insert(time, i)
	end
	if #time == 0 then
		return 0
	end
	local lua_time = os.time{year = time[1], month = time[2], day = time[3], hour = time[4], min = time[5], sec = time[6]}
	return lua_time
end

function getdayfromto(daytime)
	local std = db_to_lua_time("2013-01-01 00:00:00");
	local day_start = daytime - math.mod(daytime - std, 24*3600);
	local day_end = day_start + 24*3600;
	return day_start, day_end
end

function is_endmonth(timeparam)
	local timenext = timeparam + 24*3600;
	if os.date("%Y-%m", timeparam) ~= os.date("%Y-%m", timenext) then
		return true;
	end
	return false;
end

function split(s, delim)
	if s == nil or delim == nil then
		TraceError(debug.traceback());
	end

	assert (type (delim) == "string" and string.len (delim) > 0,"bad delimiter")
	local start = 1  local t = {}
	while true do
		local pos = string.find (s, delim, start, true) -- plain find
		if not pos then
			break
		end
		table.insert (t, string.sub (s, start, pos - 1))
		start = pos + string.len (delim)
	end
	table.insert (t, string.sub (s, start))
	return t
end

function tostringex(v, len, strsize)
	if len == nil then len = 0 end
    if strsize == nil then strsize = 0 end
	local pre = string.rep('\t', len)
	local ret = ""

	if type(v) == "table" then
		if len > 10 then return "\t{ ... }" end
		local t = ""
		local keys = {}
		for k, v1 in pairs(v) do
			table.insert(keys, k)
		end
		--table.sort(keys)
        --锟斤拷小锟斤拷锟斤拷锟斤拷锟斤拷锟捷归，3k锟斤拷小锟斤拷为锟斤拷锟斤拷
		for k, v1 in pairs(keys) do
			k = v1
			v1 = v[k]
			t = t .. "\n\t" .. pre .. tostring(k) .. ":"
			t = t .. tostringex(v1, len + 1, strsize + string.len(t));
		end
		if t == "" then
			ret = ret .. pre .. "{ }\t(" .. tostring(v) .. ")"
		else
			if len > 0 then
				ret = ret .. "\t(" .. tostring(v) .. ")\n"
			end
			ret = ret .. pre .. "{" .. t .. "\n" .. pre .. "}"
		end
	else
		ret = ret .. pre .. tostring(v) .. "\t(" .. type(v) .. ")"
	end
	return ret
end

_readTabFile = function(fileName)
	--assert(fileName)
    local fileIsExit = cc.FileUtils:getInstance():isFileExist(fileName)
    if fileIsExit == false then
		--TraceError("缺少文件" .. tostring(fileName))
		return
	end

    local fileData = cc.FileUtils:getInstance():getStringFromFile(fileName);

    if fileData == "" then
        TraceError(fileName.." empty file,please check out");
    end

	if (string.byte(fileData, 1, 1) == 0xEF) then
		fileData = string.sub(fileData, 4);
	else
		--TraceError("非UTF-8带BOM头的文件:"..fileName);
	end

	--print("rows:"..fileData);
	local rows = split(fileData, "\r\n")
	local ret = {}
	local colNames = nil
	local cltCol = nil
	for i = 1, #rows do
		local row = rows[i]
		if row and row ~= "" then
			if string.sub(row, 1, 1) ~= "#" then
				local col = split(row, "\t");
				if not colNames then
					colNames = col
				else
					local item = {}
					local itemId = tonumber(col[1])
					if itemId == nil then
						TraceError("\n\tread "..fileName.." wrongly error code row:"..i);
					end

					assert(itemId);
					for i = 1, #col do
						if colNames[i] ~= "" and (cltCol == nil or tonumber(cltCol[i]) ~= 1 ) then
							local value = col[i]
							if string.char(1) == '"' and string.char() == '"' then
								-- 支锟斤拷双锟斤拷锟脚碉拷锟斤拷锟捷ｏ拷锟斤拷锟斤拷Excel
								value = string.sub(value, 2, string.len() - 1);
							end

							if string.sub(colNames[i], 1, 2) == "sz" then
								if col[i] == "" then
									value = nil;
								else
									value = col[i];
								end
								--assert(col[i] == "" or value, colNames[i])
							elseif string.sub(colNames[i], 1, 2) == "b_" then
								if tonumber(col[i]) == 1 then
									value = true;
								else
									value = false;
								end
							elseif string.sub(colNames[i], 1, 2) == "tb" then
								value = StringToTable(col[i]);
							else
								--value = _U(col[i]);
								value = tonumber(col[i]) or 0
							end

							--if value and string.find(value, "\"") then
								--assert(false, fileName .. " 锟斤拷锟杰帮拷锟斤拷双锟斤拷锟斤拷" .. value)
							--end
							item[colNames[i]] = value
						end
					end
					if ret[itemId] then
						assert(false, fileName .. " 锟斤拷锟截革拷 id:" .. itemId .. tostringex(colNames))
					end
					--TraceError(itemId);
					ret[itemId] = item
				end
			elseif string.sub(row, 1, 7) == "#CLIENT" then
				--cltCol = split(row, "\t");
			end
		end
    end
	return ret
end

local g_tabConf = {};
readTabFile = function(fileName)
	if not fileName then
		return;
	end

	if not g_tabConf[fileName] then
		g_tabConf[fileName] = _readTabFile(fileName);
	end

	return g_tabConf[fileName];
end

OS_EXEC = function(cmd)
	Trace(cmd);
	os.execute(cmd);
end

StringToTable = function(str)
	if not str then
		--print(debug.traceback());
		return;
	end

    local _str = "return "..str
    local func = loadstring(_str)

	if not func then
		print("StringToTable error str:"..str);
	end

    return func();
end

stringToTable = StringToTable;

TableToString = function(_t)
	if type(_t) ~= "table" then
		return _t;
	end

    local szRet = "{"
    function doT2S(_i, _v)
        if "number" == type(_i) then
            szRet = szRet .. "[" .. _i .. "]="
            if "number" == type(_v) then
                szRet = szRet .. _v .. ","
            elseif "string" == type(_v) then
                szRet = szRet .. '"' .. _v .. '"' .. ","
            elseif "table" == type(_v) then
                szRet = szRet .. TableToString(_v) .. ","
			elseif "boolean" == type(_v) then
                szRet = szRet .. tostring(_v) .. ","
            else
                szRet = szRet .. "nil,"
            end
        elseif "string" == type(_i) then
            szRet = szRet .. '["' .. _i .. '"]='
            if "number" == type(_v) then
                szRet = szRet .. _v .. ","
            elseif "string" == type(_v) then
                szRet = szRet .. '"' .. _v .. '"' .. ","
            elseif "table" == type(_v) then
                szRet = szRet .. TableToString(_v) .. ","
			elseif "boolean" == type(_v) then
				szRet = szRet .. tostring(_v) .. ","
            else
                szRet = szRet .. "nil,"
            end
        end
    end
    table.foreach(_t, doT2S)
    szRet = szRet .. "}"
    return szRet
end

function printTime(title, _time)
	_time = string.format("%.2f", _time)
	local int,digit = math.modf(_time);
	--print(title..lua_to_db_time(int).."."..(digit*100))
end

function getCurrDate(_time)
	local int,digit = math.modf(_time);
	digit = string.format("%.2f", digit);
	return lua_to_db_time(int).."."..(digit*100);
end



local char = string.char

local function tail(n, k)
  local u, r=''
  for i=1,k do
    n,r = math.floor(n/0x40), n%0x40
    u = char(r+0x80) .. u
  end
  return u, n
end

local function to_utf8(a)
  local n, r, u = tonumber(a)
  if n<0x80 then                        -- 1 byte
    return char(n)
  elseif n<0x800 then                   -- 2 byte
    u, n = tail(n, 1)
    return char(n+0xc0) .. u
  elseif n<0x10000 then                 -- 3 byte
    u, n = tail(n, 2)
    return char(n+0xe0) .. u
  elseif n<0x200000 then                -- 4 byte
    u, n = tail(n, 3)
    return char(n+0xf0) .. u
  elseif n<0x4000000 then               -- 5 byte
    u, n = tail(n, 4)
    return char(n+0xf8) .. u
  else                                  -- 6 byte
    u, n = tail(n, 5)
    return char(n+0xfc) .. u
  end
end

function String2UTF8(_str)
	local str = string.gsub(_str, '&#(%d+);', to_utf8);
	return str;
end




