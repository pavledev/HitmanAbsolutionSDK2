#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "IRoomEntity.h"
#include "ZStreamingStateEntity.h"
#include "ZHM5ForwardSpawnEntity.h"
#include "ZActivatableRootEntity.h"
#include "EContractCheckpointId.h"
#include "ZObjectiveEntity.h"

class ZCheckPointEntity : public ZEntityImpl
{
public:
    TArray<TEntityRef<IRoomEntity>> m_rooms;
    TEntityRef<ZStreamingStateEntity> m_pRequiredStreamingState;
    TArray<TEntityRef<ZHM5ForwardSpawnEntity>> m_aForwardSpawn;
    TArray<TEntityRef<ZSpatialEntity>> m_aJumpPoints;
    TArray<TEntityRef<ZActivatableRootEntity>> m_aActivatableRoots;
    TEntityRef<ISoundAmbienceElement> m_pInitialSoundAmbience;
    TEntityRef<IMusicComposition> m_pInitialComposition;
    EContractCheckpointId m_eContractsCheckpointId;
    TArray<TEntityRef<ZObjectiveEntity>> m_aCurrentObjectives;
    TResourcePtr<ZEntityRef> m_TokenResource;
    bool m_bUseNextCheckpointStramingStateOnRestore;
    TArray<TEntityRef<ZActivatableRootEntity>> m_aEnabledActivatableRoots;
    int m_nCPNumber;
};
