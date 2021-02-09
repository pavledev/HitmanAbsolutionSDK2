#pragma once

#include "ZHM5BaseController.h"
#include "ZHitmanMorphemePostProcessor.h"
#include "ZHM5MovementToss.h"
#include "EThrowType.h"
#include "STossParameters.h"
#include "STrajectoryPoint.h"
#include "SReleasedItem.h"
#include "ZHM5CCEffects.h"

class ZHM5TossController : public ZHM5BaseController
{
public:
    TEntityRef<ZHitman5> m_pHitman;
    TEntityRef<IMorphemeEntity> m_MorphemeEntity;
    ZMorphemeNetworkInstance* m_pMrNetwork;
    ZHitmanMorphemePostProcessor* m_pPostProcessor;
    ZHM5MovementToss* m_pTossMovement;
    ZMapPoly m_Mapper;
    bool m_bInitialized;
    bool m_bIsAiming;
    bool m_bThrowReady;
    EThrowType m_eThrowType;
    EThrowType m_ePrevThrowType;
    STossParameters m_sTossParams;
    TArray<STrajectoryPoint> m_aTrajectoryPoints;
    float m_fMaxLength;
    float m_fTossVelocity;
    float m_fPrevTossVelocity;
    TEntityRef<ZActor> m_pDeadlyThrowTarget;
    TEntityRef<ZActor> m_pPrevDeadlyThrowTarget;
    TArray<SReleasedItem> m_aReleasedItems;
    TArray<float4> m_ArcPositions;
    bool m_bTossArchDirty;
    TEntityRef<ZHM5CCEffects> m_rEffects;
    float4 m_vIntersectionNormal;
    bool m_bNewDeadlyThrowTarget;
    float m_fCameraBlendInTime;
    float m_fDeadlyThrowLockTime;
    float m_fHintWeight;
};
