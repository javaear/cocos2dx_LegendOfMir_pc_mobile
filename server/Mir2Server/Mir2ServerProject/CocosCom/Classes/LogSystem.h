#pragma once

#include "cocos2d.h"
#include <vector>
#include <string>

using namespace std;

class LogSystem : public cocos2d::Ref
{
private:
	LogSystem(void);
	~LogSystem(void);

	static LogSystem* m_pInstance;

	vector<string> m_logStrVec;
	vector<string> m_debugStrVec;

public:
	static LogSystem* getInstance();

	void print(int type, const char* str);
	string getLog(int type);
};

