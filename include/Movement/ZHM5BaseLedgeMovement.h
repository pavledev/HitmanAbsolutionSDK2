#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHM5GuideJump.h"
#include "eEdgeEnd.h"
#include "eMoveDir.h"
#include "eOnLedgeMoveType.h"

class ZHM5BaseLedgeMovement : public ZHM5BaseMovement
{
public:
    ZHM5GuideJump* m_pCurrentGuide;
    eEdgeEnd m_eEdgeEndStatus;
    eMoveDir m_MoveDir;
    eOnLedgeMoveType m_eMoveType;
    unsigned int m_nActiveAnimNode;
    float m_fLateralSpeed;
    bool m_bLimitMove;
    ZHM5GuideJump* m_pJumpNextGuide;
    bool m_bShootIntoGround;
    bool m_bLedgeOTSMode;
    bool m_bPullVictimPossible;
    float m_fFeedBackPoseWeight;
    float m_fFeedBackLookUpDown;
    float m_fFeedbackLookLeftRight;
    float4 m_vForcedPos;
    float m_fForcedLookLeftRight;
    float m_fForcedTargetWeight;
    bool m_bForcedKeepPosOnLedge;
    ECameraOffset m_eCameraOffset;
    bool m_bAutoDismountFromTop;
    SVector2 m_vMove;
    float m_fRawInputX;
    float m_fRawInputY;
    float m_fInputVelocity;
    float m_fAbsolutAngleInput;
    int m_nQuadrantInput;
    bool m_bOverridePlayerCollision;
    float4 m_vPlayerCollisionPos;

    virtual void SetCurrentGuide(ZHM5BaseGuide*);
    virtual bool EnterLedgeOTSMode();
    virtual void ExitLedgeOTSMode();
    virtual ZHM5BaseGuide* GetClosestNeightbourGuide(float, unsigned int, unsigned __int8);
};
