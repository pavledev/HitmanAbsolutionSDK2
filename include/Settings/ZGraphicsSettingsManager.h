#pragma once

#include "IComponentInterface.h"
#include <Windows.h>
#include "TArray.h"
#include "ZMutex.h"
#include "TPair.h"
#include "Resolution.h"
#include "Aspectratio.h"

class alignas(4) ZGraphicsSettingsManager : public IComponentInterface
{
public:
    HWND__* m_hWnd;
    TArray<Resolution> m_Resolutions;
    TArray<unsigned int> m_RefreshRates;
    TArray<Aspectratio> m_AspectRatios;
    unsigned int m_nNumMonitors;
    tagRECT m_DesktopRect;
    ZMutex m_MessageThreadMutex;
    TArray<TPair<unsigned int, int> > m_MessageThreadSettings;
    TArray<TPair<unsigned int, float> > m_MessageThreadSettingsFloat;
    bool m_bScheduleApply;
    bool m_bScheduleSave;
    int m_nWindowWidthMessageThread;
    int m_nWindowHeightMessageThread;
    bool m_bDisableApplyAPIStereoValues;
    bool m_bWaitingForApply;
    bool m_bInitialized;
    bool m_bPCNewFeatures;
    bool m_bSupportsDX11;
    bool m_bSupportsDX10_1;
    bool m_bInitialWindowPlacement;
};
