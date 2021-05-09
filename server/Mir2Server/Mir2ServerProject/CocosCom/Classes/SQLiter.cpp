#include "SQLiter.h"
#include "../external/sqlite3/include/sqlite3.h"
#include <iostream>  
using namespace std;

#pragma comment (lib,"sqlite3.lib")

SQLiter::SQLiter(void)
{
}


SQLiter::~SQLiter(void)
{
}

bool SQLiter::init()
{
	return true;
}

bool SQLiter::initSql(const char* sqlName)
{
	sqlite3* pSqlite;

	auto sqlPath = FileUtils::getInstance()->fullPathForFilename(sqlName);

	if (sqlPath == "")
		return false;

	//打开sqlite数据库
	int ret = sqlite3_open(sqlPath.c_str(), &pSqlite);

	//当sqllite数据库打开失败时
	if (ret != SQLITE_OK)
	{
		//获得sqltite数据库打开错误的信息
		const char* errmsg = sqlite3_errmsg(pSqlite);

		//打印数据库打开失败的信息
		log("sqlite open error: %s", errmsg);

		return false;
	}

	m_pSqlite = pSqlite;

	return true;
}

bool SQLiter::open(const char* dbname)
{
	sqlite3* pSqlite = (sqlite3*)m_pSqlite;
	int ret = sqlite3_open(dbname, &pSqlite);

	//失败时
	if (ret != SQLITE_OK)
	{
		//得到向表中插入数据失败的信息
		const char* errmsg = sqlite3_errmsg(pSqlite);

		return false;
	}

	return true;
}

bool SQLiter::exec(const char* execStr)
{
	sqlite3* pSqlite = (sqlite3*)m_pSqlite;
	char* errmsg;

	sqlite3_exec(pSqlite, "BEGIN;", 0, 0, NULL);
	int ret = sqlite3_exec(pSqlite, execStr, NULL, NULL, &errmsg);
	sqlite3_exec(pSqlite, "COMMIT;", 0, 0, NULL);

	//update data_item set gridIndex = 0, isEquip = 1 where itemid = 196;

	//当向表中插入数据失败时
	if (ret != SQLITE_OK)
	{
		//得到向表中插入数据失败的信息
		const char* errmsg = sqlite3_errmsg(pSqlite);

		return false;
	}

	return true;
}

bool SQLiter::insert(const char* execStr)
{
	string str = execStr;
	auto pos = str.find("values");
	auto valueSr = str.substr(pos + 8, str.size() - pos - 9);
	auto prefix = str.substr(0, pos + 6);
	prefix += " (";

	vector<string> values = split(valueSr, ",");
	for (int i = 0; i < values.size(); ++i)
	{
		if (i == 0)
			prefix += "?";
		else
			prefix += ",?";
	}
	prefix += ")";

	sqlite3* db = (sqlite3*)m_pSqlite;
	sqlite3_exec(db, "BEGIN;", 0, 0, 0);
	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, prefix.c_str(), strlen(prefix.c_str()), &stmt, 0);

	sqlite3_reset(stmt);
	for (int i = 0; i < values.size(); ++i)
	{
		string value = values[i];
		if (value.find("'") != string::npos)
		{
			auto len = value.size() - 2;
			auto newValue = values[i].substr(1, len);
			sqlite3_bind_text(stmt, i + 1, newValue.c_str(), -1, SQLITE_STATIC);
		}
		else
		{
			double num = atof(values[i].c_str());
			sqlite3_bind_double(stmt, i + 1, num);
		}
	}

	sqlite3_finalize(stmt);
	int ret = sqlite3_exec(db, "commit;", 0, 0, 0);

	if (ret != SQLITE_OK)
	{
		//得到向表中插入数据失败的信息
		const char* errmsg = sqlite3_errmsg(db);

		return false;
	}

	return true;
}

string SQLiter::getTable(const char* sqlStr)
{
	sqlite3* pSqlite = (sqlite3*)m_pSqlite;

	char** pResult;
	int nRow;
	int nCol;

	sqlite3_exec(pSqlite, "BEGIN", 0, 0, NULL);
	int ret = sqlite3_get_table(pSqlite, sqlStr, &pResult, &nRow, &nCol, 0);
	sqlite3_exec(pSqlite, "COMMIT", 0, 0, NULL);
	//std::string codes = sqlStr;
	//codes = codes + "\n";
	//LogSystem::getInstance()->print(1, codes.c_str());

	string strOut;
	int nIndex = nCol;
	for (int i = 0; i<nRow; i++)
	{
		strOut += "{";

		for (int j = 0; j<nCol; j++)
		{
			strOut += pResult[j];
			strOut += "='";
			strOut += pResult[nIndex];
			strOut += "',";
			++nIndex;
		}

		strOut += "},";
	}

	sqlite3_free_table(pResult);

	string result = "{" + strOut + "}";
	return result;
}

void SQLiter::close()
{
	sqlite3* pSqlite = (sqlite3*)m_pSqlite;
	//关闭数据库
	sqlite3_close(pSqlite);
}

vector< string> split(string str, string pattern)
{
	vector<string> ret;
	if (pattern.empty()) return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos)
	{
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
	return ret;
}