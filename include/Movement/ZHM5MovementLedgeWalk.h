#pragma once

#include "ZHM5BaseLedgeMovement.h"
#include "ZHitmanMorphemePostProcessorLedgeHangCallback.h"
#include "eMorphemeRequests.h"
#include "EWindowStatus.h"
#include "ZHM5GuideWindow.h"
#include "HM5Utils.h"
#include "ZHM5ReloadController.h"

class alignas(16) ZHM5MovementLedgeWalk : public ZHM5BaseLedgeMovement, public ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
    unsigned int m_nActiveSM;
    bool m_bDestSet;
    eMorphemeRequests m_nMountReq;
    bool m_bTurningCorner;
    EWindowStatus m_WindowStatus;
    float m_fWindow;
    ZHM5GuideWindow* m_pCurrentWindow;
    bool m_bPullVictimActivated;
    float m_fLookLeftRight;
    float m_fLookLeftRightTarget;
    bool m_bLocomotionStartRight;
    ZGameTime m_timeInLedgeWalkPullUpDown;
    ZGameTime m_timeInLedgeWalkPullLeftRight;
    float m_fOldAimHorLimitAngle;
    float m_fOldAimVerLimitAngle;
    bool m_bSneakPastWindowParamsUpdated;
    bool m_bSneakPastWindowPrompt;
    SMatrix m_aBlendMats[3];
    HM5Utils::SAnimBlend m_aAnimBlends[3];
    ZHM5ReloadController* m_pReloadController;
    float m_fAimWeight;
    float m_afHandAimTime[2];
    SLedgeAimInfo m_AimLedgeInfo;
    ZPolarAnimBlend m_PolarAnimBlendRight;
    ZPolarAnimBlend m_PolarAnimBlendLeft;
    float m_afWindowAimTime[2];
    ZMapPoly m_MapPoly;
    __int8 m_bWindowAiming : 1;
    __int8 m_bAllowAiming : 1;
    __int8 m_bAimWithRightArm : 1;
    __int8 m_bWantsControl : 1;
};
