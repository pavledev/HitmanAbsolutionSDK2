#pragma once

#include "ZHM5BaseController.h"
#include "ZMapPoly.h"
#include "eItemType.h"

class ZHM5AimController : public ZHM5BaseController
{
public:
    TEntityRef<ZHitman5> m_pHitman;
    SHM5AimInfo m_AimInfo;
    SHM5LookAtInfo m_LookAtInfo;
    ZMapPoly m_MapPoly;
    ZMapPoly m_MapPolyLag;
    eItemType m_aeItems[2];
    EBaseMovementType m_eMovementType;
    float m_fGripPoseBlendTime;
    float m_fPreviousMovementAimWeight;
    float m_fPreviousMovementHandLayerWeight;
    float m_fPreviousMovementArmLayerWeight;
    float m_fPoseBlendTime;
    float m_afGripBlendInTime[2];
    float m_afItemChangedTime[2];
    float m_fPreviousMmovementLookAtWeight;
    float m_fLookAtPoseTime;
    SVector2 m_vAimLag;
    SVector2 m_vHeadLead;
    float m_LeadTimer;
    float m_fFireTimer;
};
