#pragma once

#include "cocos2d.h"
#include <string>

using namespace std;
USING_NS_CC;

class SQLiter: public Node
{
public:
	SQLiter(void);
	~SQLiter(void);

	bool		init();


	bool		initSql(const char* sqlName);


	bool		open(const char* dbname);


	bool		exec(const char* execStr);


	string		getTable(const char* execStr);

	bool        insert(const char* execStr);


	void		close();


	CREATE_FUNC(SQLiter);

private:
	void* m_pSqlite;
};

vector< string> split(string str, string pattern);