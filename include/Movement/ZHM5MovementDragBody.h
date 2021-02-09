#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"

class ZHM5MovementDragBody : public ZHM5BaseMovement
{
public:
    bool m_bWantsControl;
    TEntityRef<ZActor> m_pActor;
    float m_fToStandIdleAnimTime;
    float m_fToStandIdleAnimDuration;
    float m_fGrabVictimTime;
    float m_fGrabVictimTimeLimit;
    unsigned int m_nGrabBoneID;
    bool m_bGrabRagDollDirect;
    bool m_bPlayEnterAnimation;
    unsigned int m_aDragStateIDs[5];
    unsigned int m_nTurnAnlgeControlParamID;
    unsigned int m_nMoveRequestID;
    unsigned int m_nStopRequestID;
    SMatrix m_StartDragBodyMatPos;
    float m_fAlignToTargetFraction;
    SInputRestriction m_InputRestriction;
    float1 m_vDragDist;
    float4 m_vPrevHitmanPos;
};
