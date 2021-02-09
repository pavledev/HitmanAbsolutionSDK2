#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "ZGameWideUIScaleformHandler.h"
#include "TMaxArray.h"
#include "SDialogData.h"
#include "EControllerButton.h"

class alignas(8) ZGameWideUI : public IComponentInterface
{
public:
    TEntityRef<ZGameWideUIScaleformHandler> m_rGameWideUI;
    TMaxArray<SDialogData, 10> m_DialogStack;
    bool m_bLoadSaveIndicatorRequested;
    bool m_bLoadSaveIndicatorShownLastFrame;
    int m_iTopDialog;
    bool m_bRequestedPause;
    int m_nTransitionCoolDown;
    __int64 m_tMinSaveIconShowTime;
    ZString m_sCachedBuildID;
    EControllerButton m_eClickedButton;
    bool m_bInGame;
    int m_nCursorFlag;
    bool mSelectedPositive;
    bool m_bPcNewFeatures;
    bool m_bIsFaded;
};
