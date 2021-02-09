#pragma once

#include "ZEvent2.h"
#include "ENetworkControlParam.h"
#include "ZMapEaseToState.h"
#include "ZMapPoly.h"

class ZHM5LocomotionInput
{
public:
    ZEvent2<ENetworkControlParam, ZVariantRef const&> SetControlParameterEvent;
    float m_fSampleTime;
    float m_fMoveDirX;
    float m_fMoveDirY;
    float m_fStickAngle;
    float m_fMoveSpeed;
    float m_fDeltaSpeedStick;
    float m_fCamAngle;
    float m_fTargetFastWalkSpeedFraction;
    float m_fFastWalkSpeedFraction;
    float m_fMoveSpeedLocked;
    float m_fMoveAngleLocked;
    float m_fMoveAngle;
    float m_fWalkRunBlendWeight;
    float m_fWalkRunInput;
    float m_fLockMoveAngle;
    float m_fLockMoveAngleRange;
    bool m_bLockMoveAngle;
    bool m_bRunActivated;
    bool m_bRun;
    bool m_bSneaking;
    bool m_bStrafing;
    float m_fCapX;
    float m_fCapY;
    float m_flpX;
    float m_flpY;
    float m_fPrevRawInputX;
    float m_fPrevRawInputY;
    float m_fFlickTimer;
    bool m_bFirstUpdate;
    ZMapEaseToState m_RunMap;
    ZMapPoly m_RunMapFunction;
};
