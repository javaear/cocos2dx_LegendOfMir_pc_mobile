#include "LogSystem.h"

LogSystem* LogSystem::m_pInstance = 0;

LogSystem::LogSystem(void)
{
}


LogSystem::~LogSystem(void)
{
}

LogSystem* LogSystem::getInstance()
{
	if (m_pInstance == 0)
		m_pInstance = new LogSystem();

	return m_pInstance;
}

void LogSystem::print(int type, const char* str)
{
	if (type == 1)
		m_logStrVec.push_back(str);
	else if (type == 2)
		m_debugStrVec.push_back(str);
}

string LogSystem::getLog(int type)
{
	string logStr = "";

	if (type == 1)
	{
		if (m_logStrVec.size() == 0)
			return "";

		logStr = m_logStrVec[0];
		m_logStrVec.erase(m_logStrVec.begin());

		return logStr;
	}
	else if (type == 2)
	{
		if (m_debugStrVec.size() == 0)
			return "";

		logStr = m_debugStrVec[0];
		m_debugStrVec.erase(m_debugStrVec.begin());

		return logStr;
	}
}