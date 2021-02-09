#pragma once

#include "ZHM5BaseMovement.h"
#include "EThrowType.h"
#include "SThrowAnimInfo.h"
#include "IHM5Item.h"
#include "ZActor.h"
#include "ZHM5CoverPlane.h"
#include "HM5Utils.h"

class ZHM5MovementToss : public ZHM5BaseMovement
{
public:
    SMatrix m_mvLastRightAttMatPos;
    bool m_bWantControl;
    EThrowType m_eThrowType;
    SThrowAnimInfo m_aThrowAnimInfo[40];
    float m_fAnimFraction;
    float4 m_vThrowDir;
    unsigned int m_nThrowFractionParamID;
    unsigned int m_nHeavyThrowWeightID;
    bool m_bReleasedItem;
    TEntityRef<IHM5Item> m_rItem;
    TEntityRef<ZActor> m_pDeadlyThrowTarget;
    bool m_bReturnToCover;
    ZHM5CoverPlane* m_pLastCover;
    SMatrix m_mvStartMatPos;
    SMatrix m_mvThrowDestMatPos;
    SMatrix m_mvCoverDestMatPos;
    HM5Utils::SAnimBlend m_sAnimBlend;
    ECameraState m_eCameraState;
    SMatrix m_CoverCameraGround;
    bool m_bApplyBoneLock;
    SMatrix m_mvLockBoneStart;
    SMatrix m_mvLockBoneDest;
    HM5Utils::SPelvisSimpleRotationCorrection m_sPelvisCorrection;
};
