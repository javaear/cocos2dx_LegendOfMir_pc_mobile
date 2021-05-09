// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include "API.h"
//#include "LogSystem.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		//instance will be deleted automatically
		break;
	}
	return TRUE;
}
/*
int main()
{
	Initialize();
	Start();

	while (true)
	{
		MainLoop();

		string str = LogSystem::getInstance()->getLog(1);
		if (str != "")
			printf("%s", str.c_str());
	}

	return 0;
}*/