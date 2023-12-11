// dllmain.cpp : Implementação do DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "AtlComServer_i.h"
#include "dllmain.h"

CAtlComServerModule _AtlModule;

// Ponto de Entrada DLL
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
