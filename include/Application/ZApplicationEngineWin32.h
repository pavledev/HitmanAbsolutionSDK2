#pragma once

#include "ZWin32ApplicationBase.h"
#include "SteamInitResult.h"
#include "ZEngineAppCommon.h"
#include "WindowCreationParameters.h"
#include "CCallback.h"
#include "GameOverlayActivated_t.h"

class alignas(8) ZApplicationEngineWin32 : public ZWin32ApplicationBase
{
public:
    bool m_bUseSteam;
    SteamInitResult m_nSteamInitResult;
    bool m_bGSMBusy;
    ZEngineAppCommon m_common;
    WindowCreationParameters m_WindowCreationParameters;
    ZThread m_messageLoopThread;
    ZThreadEvent m_messageLoopThreadEvent;
    CCallback<ZApplicationEngineWin32, GameOverlayActivated_t, 0> m_overlayActivated;
    ZThreadEvent m_mainLoopDoneEvent;
    HWND__* m_hWnd;
    bool m_bTerminateApplication;
    bool m_bShowingCursor;
    bool m_bTempWindowed;
    bool m_bPauseGameLoop;
    bool m_bGameLoopPaused;
    int m_PreviousMasterVolume;
    bool m_bChangeMasterVolume;
    int m_TargetMasterVolume;
    bool m_bActive;
    HICON__* m_hDefaultCursor;
};
