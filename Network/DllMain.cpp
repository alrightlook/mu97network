#include "Library.h"

HMODULE _MODULE;

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH)
	{
		_MODULE = hModule;

		if(!Network::Project::initComponents())
		{
			MessageBox(NULL, "Falha na inicialização do aplicativo.", "Erro", MB_OK | MB_ICONERROR);
			ExitProcess(1);
		}
	}

	return TRUE;
}