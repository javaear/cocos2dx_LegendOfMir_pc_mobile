#pragma once

#include <string>
#define DLLEXPORT __declspec(dllexport)

extern "C"
{
	DLLEXPORT void Debug();
	DLLEXPORT bool Initialize();
	DLLEXPORT bool Start();
	DLLEXPORT void MainLoop();
	DLLEXPORT void Destory();
	DLLEXPORT void ExcStr(char* str);
	DLLEXPORT const char* getLogMessage(int type);
	DLLEXPORT const char* getLuaVariable(char* str);
	DLLEXPORT const char* getLuaTable(char* table, char* field);
	DLLEXPORT const char* getLuaFunction(char* func, char* param);
};