#pragma once

#include "SOrderParamsBase.h"
#include "IAnimatedActorListener.h"
#include "SEventNotifyFlags.h"
#include "ZPF5Location.h"
#include "ZActorAnimationState.h"
#include "EOrderCompletionStatus.h"

class ZNPCMorphemeNetworkController;
class ZAnimProgramBase;

class ZAnimatedActor
{
public:
    alignas(16) ZNPCMorphemeNetworkController* m_pController;
    ZActorAnimationState* m_pActorAnimationState;
    ZAnimProgramBase* m_pCurrentProgram;
    TEntityRef<IMorphemeEntity> m_pMorphemeEntity;
    ZMorphemeNetworkInstance* m_pNetwork;
    SOrderParamsBase* m_pCurrentOrder;
    bool m_bPendingOrder;
    TMaxArray<SOrderParamsBase*, 3> m_pendingOrdersQueue;
    TEntityRef<ZActor> m_pActor;
    EOrderCompletionStatus m_eLastOrderCompletionStatus;
    __int8 m_bControlled : 1;
    __int8 m_bShootIntoGround : 1;
    __int8 m_bShootIntoGroundInSequences : 1;
    __int8 m_bShootRequested : 1;
    __int8 m_bBlindfireRequested : 1;
    __int8 m_bIgnoreLOF : 1;
    ZPositionTarget m_rShootTarget;
    IAnimatedActorListener* m_pAnimatedActorListener;
    SEventNotifyFlags m_eventBits;
    unsigned int m_facefxEyeYawNode;
    unsigned int m_facefxEyePitchNode;
    float m_facefxEyeYawNodeLastValue;
    float m_facefxEyePitchNodeLastValue;
    TEntityRef<ZActorInstanceEntity> m_facefxActorInstance;
    float m_ZError;
    IAsyncRayHandle* m_raycastZOffset;
    float m_ZatRaycastPosition;
    alignas(16) ZPF5Location m_closestLocationOnNavmesh;
    __int8 m_bConstrainedToNavMesh : 1;
    __int8 m_bIsOnNavMesh : 1;
    SMatrix m_mFrom;
    SMatrix m_mTo;
    SMatrix m_mNext;

    virtual ~ZAnimatedActor();
};
