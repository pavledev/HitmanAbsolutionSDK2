#include "ZDebugConsoleHooks.h"
#include "HM5DebugConsole.h"

namespace ZDebugConsoleHooks
{
    AddLine pOriginalAddLine;

    void __cdecl AddLineHook(void* pThis, const char* Format, ...)
    {
        va_list args;
        char Message[256];

        va_start(args, Format);
        vsprintf_s(Message, Format, args);

        Menu::console.AddLog(Message);

        pOriginalAddLine(pThis, Format, args);

        va_end(args);
    }

    void CreateAndEnableHooks()
    {
        AddLine pAddLine = reinterpret_cast<AddLine>(BaseAddresses::hitman5Dll + 0x629CD0);

        if (MH_CreateHook(reinterpret_cast<LPVOID>(pAddLine), reinterpret_cast<LPVOID>(AddLineHook),
            reinterpret_cast<LPVOID*>(&pOriginalAddLine)) != MH_OK)
        {
            HM5_LOG("Failed to create AddLine hook.\n");
        }

        if (MH_EnableHook(reinterpret_cast<LPVOID>(pAddLine)) != MH_OK)
        {
            HM5_LOG("Failed to enable AddLine hook.\n");
        }
    }
}
