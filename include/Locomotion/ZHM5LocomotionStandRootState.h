#pragma once

#include "ZHM5LocomotionState.h"
#include "HM5Utils.h"

class alignas(16) ZHM5LocomotionStandRootState : public ZHM5LocomotionState
{
public:
    bool m_bTurnPlayed;
    float m_fTurnAngleBlend;
    float m_fTurnAngleBlendTarget;
    float m_fTurnDir;
    float m_fPrevTurnDir;
    float m_fAnimSpeed;
    bool m_bAnimBlendInitialized;
    HM5Utils::SAnimBlend m_TurnBlendLeft90;
    HM5Utils::SAnimBlend m_TurnBlendLeft180;
    HM5Utils::SAnimBlend m_TurnBlendRight90;
    HM5Utils::SAnimBlend m_TurnBlendRight180;
    SMatrix m_BlendStartMtx;
    SMatrix m_BlendEndMtx;
    SMatrix m_BlendPrevMtx;
    HM5Utils::SAnimBlend* m_pCurrentBlend;
};
