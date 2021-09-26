#pragma once

#include <iostream>
#include "MinHook.h"
#include "BaseAddresses.h"
#include "ZApplicationEngineWin32.h"

//using namespace std;

namespace ApplicationHooks
{
	extern HWND hwnd;

	void CreateAndEnableHooks();

	typedef void(__thiscall* CreateMainWindow)(ZApplicationEngineWin32* pThis, HINSTANCE__* hInstance, HWND__* hParent, const ZString* sSceneFile, int nX, int nY, unsigned int nWidth, unsigned int nHeight, bool bFullScreen, int nShowWindowCmd);
	void __fastcall CreateMainWindowHook(ZApplicationEngineWin32* pThis, int padding, HINSTANCE__* hInstance, HWND__* hParent, const ZString* sSceneFile, int nX, int nY, unsigned int nWidth, unsigned int nHeight, bool bFullScreen, int nShowWindowCmd);
}
