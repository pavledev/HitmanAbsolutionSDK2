#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHM5GuideLadder.h"
#include "eMoveDir.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"

class alignas(16) ZHM5MovementLadder : public ZHM5BaseMovement
{
public:
    ZHM5GuideLadder* m_pCurrentLadder;
    unsigned int m_nActiveAnimNodeID;
    eMoveDir m_eMoveDir;
    eMoveDir m_eMoveType;
    float m_fAnimFraction;
    float m_fEarlyExitFraction;
    float m_fVerticalSpeed;
    float m_fUpFastSpeed;
    float m_fUpSlowSpeed;
    float m_fDownFastSpeed;
    float m_fDownSlowSpeed;
    float m_fSlideDownSpeed;
    bool m_bStopping;
    int m_nNumOfRungs;
    float m_fNumCycles;
    float m_fCurrentCycleNum;
    float m_fTargetAnimPrct;
    float m_fTargetCycleNum;
    bool m_bStopSet;
    SMatrix m_mStart;
    SMatrix m_mEnd;
    HM5Utils::SAnimBlend m_sAnimBlend;
    bool m_bOddLadder;
    bool m_bDismountDown;
    bool m_bDismountTop;
    float4 m_vForcedPos;
    bool m_bForceResetCamera;
    bool m_bRequestControl;
    ZMapPoly m_MapPoly;

    virtual eMoveDir GetMoveDir();
    virtual bool IsDismountingLadder();
};
