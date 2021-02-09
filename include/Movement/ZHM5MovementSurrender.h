#pragma once

#include "ZHM5BaseMovement.h"
#include "HM5Utils.h"
#include "ESurrenderState.h"

class alignas(16) ZHM5MovementSurrender : public ZHM5BaseMovement
{
public:
    SMatrix m_mvStartMatPos;
    SMatrix m_mvDestMatPos;
    SMatrix m_mvCameraGroundStart;
    bool m_bLerpCameraGround;
    HM5Utils::SAnimBlend m_sAnimBlend;
    unsigned int m_nRaiseArmsAnimID;
    unsigned int m_nIdleStateID;
    unsigned int m_nTurnStateID;
    unsigned int m_anAnimIDs[5];
    float m_fStartFraction;
    float m_fEndFraction;
    float m_fAnimFraction;
    float m_fAnimDuration;
    unsigned int m_nControlParam;
    bool m_bWantControl;
    bool m_bLookAtPoseChanged;
    bool m_bLookAtPosInitialized;
    float4 m_vLookAtPoint;
    float4 m_vLookAtDir;
    ESurrenderState m_eState;
};
