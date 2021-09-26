#pragma once

#include <iostream>
#include "MinHook.h"
#include "BaseAddresses.h"
#include "ZDebugConsole.h"
#include "Menu.h"

//using namespace std;

namespace ZDebugConsoleHooks
{
    void CreateAndEnableHooks();

    typedef void(__cdecl* AddLine)(void* pThis, const char* Format, ...);
    void __cdecl AddLineHook(void* pThis, const char* Format, ...);
}
