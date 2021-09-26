#include "ApplicationHooks.h"
#include "HM5DebugConsole.h"
#include "MinHookMessage.h"

namespace ApplicationHooks
{
    HWND hwnd;
    CreateMainWindow pOriginalCreateMainWindow;

    void __fastcall CreateMainWindowHook(ZApplicationEngineWin32* pThis, int padding, HINSTANCE__* hInstance, HWND__* hParent, const ZString* sSceneFile, int nX, int nY, unsigned int nWidth, unsigned int nHeight, bool bFullScreen, int nShowWindowCmd)
    {
        pOriginalCreateMainWindow(pThis, hInstance, hParent, sSceneFile, nX, nY, nWidth, nHeight, bFullScreen, nShowWindowCmd);

        hwnd = pThis->m_hWnd;
    }

    void CreateAndEnableHooks()
    {
        CreateMainWindow pCreateMainWindow = reinterpret_cast<CreateMainWindow>(BaseAddresses::engine + 0x3CB0);

        MH_STATUS createStatus = MH_CreateHook(reinterpret_cast<LPVOID>(pCreateMainWindow), reinterpret_cast<LPVOID>(CreateMainWindowHook),
            reinterpret_cast<LPVOID*>(&pOriginalCreateMainWindow));

        if (createStatus != MH_OK)
        {
            HM5_LOG("Failed to create CreateMainWindow hook. %s\n", MinHookMessage::GetMessageFromStatus(createStatus).c_str());
        }

        MH_STATUS enableStatus = MH_EnableHook(reinterpret_cast<LPVOID>(pCreateMainWindow));

        if (enableStatus != MH_OK)
        {
            HM5_LOG("Failed to enable CreateMainWindow hook. %s\n", MinHookMessage::GetMessageFromStatus(enableStatus).c_str());
        }
    }
}
