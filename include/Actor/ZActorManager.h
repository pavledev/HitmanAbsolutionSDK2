#pragma once

#include "IComponentInterface.h"
#include "TArrayFixedHeap.h"
#include "SAIEvent.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "ZBackupHelper.h"
#include "ZSharedVisibilitySensor.h"
#include "ZSharedSoundSensor.h"
#include "ZSharedHitmanSensor.h"
#include "ZSharedDeadBodySensor.h"
#include "ZSharedCoverSensor.h"
#include "ZCollisionSensor.h"
#include "ZSocialSensor.h"
#include "ZDangerSensor.h"
#include "ZShootTargetSensor.h"
#include "ZCombatManager.h"
#include "ZGameStatsManager.h"
#include "ZSharedSensorDef.h"
#include "ZCloseCombatDef.h"
#include "ZActorDialogManager.h"
#include "ZCombatDialogManager.h"
#include "ZTossGeometry.h"
#include "SActorEventEmitterState.h"
#include "ZSituationManager.h"

class alignas(16) ZActorManager : public IComponentInterface
{
public:
    TArrayFixedHeap<SAIEvent, 8192> m_Events;
    TMaxArray<TEntityRef<ZActor>, 512> m_sceneActors;
    TMaxArray<TEntityRef<ZActor>, 100> m_initializedActors;
    TMaxArray<TEntityRef<ZActor>, 100> m_enabledActors;
    TMaxArray<TEntityRef<ZActor>, 50> m_aliveActors;
    TMaxArray<TEntityRef<ZActor>, 16> m_ForceUpdateActors;
    TArray<TEntityRef<ZActor>> m_PendingEnableActors;
    TArray<TEntityRef<ZActor>> m_PendingDisableActors;
    TArray<TEntityRef<ZActor>> m_SpawnedActors;
    ZBackupHelper m_backupHelper;
    int m_nNextActor;
    int m_nNextSensor;
    ZSharedVisibilitySensor* m_pVisibilitySensor;
    ZSharedSoundSensor* m_pSoundSensor;
    ZSharedHitmanSensor* m_pHitmanSensor;
    ZSharedDeadBodySensor* m_pDeadBodySensor;
    ZSharedCoverSensor* m_pCoverSensor;
    ZCollisionSensor* m_pCollisionSensor;
    ZSocialSensor* m_pSocialSensor;
    ZDangerSensor* m_pDangerSensor;
    ZShootTargetSensor* m_pShootTargetSensor;
    ZCombatManager m_CombatManager;
    ZGameStatsManager* m_pGameStats;
    TEntityRef<ZSharedSensorDef> m_pSharedSensorDef;
    TEntityRef<ZCloseCombatDef> m_pCloseCombatDef;
    int m_nTrespassingState;
    ZSituationManager m_situationManager;
    ZActorDialogManager m_actorDialogManager;
    ZCombatDialogManager m_combatDialogManager;
    ZTossGeometry* m_tossGeometry;
    TMaxArray<SActorEventEmitterState, 128> m_actorEventEmitters;
    TArray<TEntityRef<ZActorRelationshipEntity>> m_aActorRelationships;
    bool m_bActorDamaged;
    TMaxArray<TEntityRef<ZPointOfInterestEntity>, 64> m_RegisteredPOI;
    TSet<TEntityRef<ZActor>> m_GuardsSneakedBy;
    TArray<ZEntityRef> m_RegisteredLinkedItems;
    ZEvent<TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ActorDeathEvents;
    TArray<TEntityRef<ZActor>> m_aTargetList;
    TArray<TEntityRef<ZActor>> m_aCollateralTargetList;
    TArray<TEntityRef<ZCharacterTemplateAspect>> m_aFakeTargetList;
    int m_iSessionMaxSharedEntityCount;
    int m_iSessionMaxSharedEventCount;
    int m_iSessionMaxNonSharedEntityCount;
    int m_iSessionMaxNonSharedEventCount;
    __int8 m_bEnabledActorListLocked : 1;
    unsigned int m_indexActorOfTheFrame;
    unsigned __int16 m_navMeshChangedCostMask;
};
