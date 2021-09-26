#pragma once

#include "IComponentInterface.h"
#include "TArrayFixedHeap.h"
#include "SAIEvent.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "ZBackupHelper.h"
#include "ZCombatManager.h"
#include "ZActorDialogManager.h"
#include "ZCombatDialogManager.h"
#include "ZSituationManager.h"
#include "ERegionMask.h"
#include "EAIActorRelationshipType.h"
#include "EAIEventType.h"
#include "EAISharedEventType.h"
#include "EGameTension.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TSet.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZVariantRef.h"
#include "SActorEventEmitterState.h"

class ZActor;
class ZActorEventEmitter;
class ZActorRelationshipEntity;
class ZCharacterTemplateAspect;
class ZCloseCombatDef;
class ZCollisionSensor;
class ZDangerSensor;
class ZEventNull;
class ZGameStatsManager;
class ZHitman5;
class ZPointOfInterestEntity;
class ZSharedCoverSensor;
class ZSharedDeadBodySensor;
class ZSharedHitmanSensor;
class ZSharedKnowledgeRef;
class ZSharedSensorDef;
class ZSharedSoundSensor;
class ZSharedVisibilitySensor;
class ZShootTargetSensor;
class ZSocialSensor;
class ZSpatialEntity;
class ZTossGeometry;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct STypeID;
struct float4;
template <class T> class alignas(8) ZDelegate;

class ZActorManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

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
	bool m_bEnabledActorListLocked : 1;
	unsigned int m_indexActorOfTheFrame;
	unsigned short m_navMeshChangedCostMask;

	static const int MAX_POI;
	static const unsigned int MAX_EVENTS;

	~ZActorManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZActorManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Activate();
	void Deactivate();
	void SceneReset();
	void OnCheckpointDeactivated();
	void OnCheckpointActivated();
	void RegisterSceneActor(TEntityRef<ZActor>& pActor);
	void UnregisterSceneActor(TEntityRef<ZActor>& pActor);
	void RegisterInitializedActor(TEntityRef<ZActor>& pActor);
	void UnregisterInitializedActor(TEntityRef<ZActor>& pActor);
	void RegisterEnabledActor(TEntityRef<ZActor>& pActor);
	void UnregisterEnabledActor(TEntityRef<ZActor>& pActor);
	void RegisterAliveActor(TEntityRef<ZActor>& pActor);
	void UnregisterAliveActor(TEntityRef<ZActor>& pActor);
	void RegisterActorEventEmitter(ZActorEventEmitter* pActorEventEmitter);
	void UnregisterActorEventEmitter(ZActorEventEmitter* pActorEventEmitter);
	TEntityRef<ZActorRelationshipEntity> GetRelatioship(TEntityRef<ZActor> pActor, EAIActorRelationshipType eType, bool bCheckActorB);
	void RegisterRelationship(TEntityRef<ZActorRelationshipEntity> pRelatioshipEntity);
	void UnregisterRelationship(TEntityRef<ZActorRelationshipEntity> pRelatioshipEntity);
	void RegisterGlowItem(ZEntityRef pItem);
	void UnregisterGlowItem(ZEntityRef pItem);
	void RegisterPOI(const TEntityRef<ZPointOfInterestEntity>& rPointOfInterest);
	void UnregisterPOI(const TEntityRef<ZPointOfInterestEntity>& rPointOfInterest);
	void RegisterSpawnedActor(const TEntityRef<ZActor>& pActor);
	unsigned int ForceUpdate(TEntityRef<ZActor>& pActor);
	ZSharedVisibilitySensor& GetVisionSensor();
	ZSharedSoundSensor& GetSoundSensor();
	ZSharedHitmanSensor& GetHitmanSensor();
	ZSharedDeadBodySensor& GetDeadBodySensor();
	ZSocialSensor& GetSocialSensor();
	ZDangerSensor& GetDangerSensor();
	ZCollisionSensor& GetCollisionSensor();
	ZCombatManager& GetCombatManager();
	TArrayRef<TEntityRef<ZActor>> GetInitializedActors();
	TArrayRef<TEntityRef<ZActor>> GetActors();
	TArrayRef<TEntityRef<ZActor>> GetAliveActors();
	TArray<TEntityRef<ZActor>>& GetTargetList();
	TArray<TEntityRef<ZActor>>& GetCollateralTargetList();
	TArray<TEntityRef<ZCharacterTemplateAspect>>& GetFakeTargetList();
	int GetFreeAliveSlotCount();
	TArrayRef<TEntityRef<ZActor>> GetSceneActors();
	const TMaxArray<TEntityRef<ZPointOfInterestEntity>, 64>& GetRegisteredPOI() const;
	void SoundEvent(EAIEventType eType, ZEntityRef pSender, const float4& vPos, float fRange);
	void SoundEvent(EAIEventType eType, ZEntityRef pSender, const float4& vPos);
	void SoundEvent(EAIEventType eType, const float4& vPos);
	void AddSoundEventPulse(EAIEventType eType, ZEntityRef pSender, TEntityRef<ZSpatialEntity> pSpatial, const float4& vPos);
	void RemoveSoundEventPulse(EAIEventType eType, ZEntityRef pSender);
	ZActorDialogManager& GetActorDialogManager();
	ZCombatDialogManager& GetCombatDialogManager();
	ZSituationManager& GetSituationManager();
	ZTossGeometry& GetTossGeometry();
	void SetHitmanSharedEvent(EAISharedEventType eventType, bool bCurrent, float fDuration);
	bool IsHitmanSharedEventCurrent(EAISharedEventType eventType) const;
	const ZSharedKnowledgeRef& GetCurrentHitman();
	void FlagActorsDamaged();
	void RegisterSharedSensorDef(TEntityRef<ZSharedSensorDef> pSensorDef);
	TEntityRef<ZSharedSensorDef> GetSharedSensorDef();
	void RegisterCloseCombatDef(TEntityRef<ZCloseCombatDef> pSensorDef);
	void RequestEnable(TEntityRef<ZActor> pActor);
	void RequestDisable(TEntityRef<ZActor> pActor);
	EGameTension GetActorGameTension(const TEntityRef<ZActor>& pActor);
	bool CheckSetupErrors();
	void OnActorDeath(TEntityRef<ZActor> pActor);
	void ClearRenderModes(TEntityRef<ZActor> pActor);
	void RegisterForActorDeathEvents(const ZDelegate<void __cdecl(TEntityRef<ZActor>)>& Callback);
	void UnregisterForActorDeathEvents(const ZDelegate<void __cdecl(TEntityRef<ZActor>)>& Callback);
	void ResetAllActorsGreetedHitman();
	void SetLoadScreenActive(bool bActive);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void AnimationPostProcessFrameUpdate(const SGameUpdateEvent& updateEvent);
	void GameStopped();
	void GameStarted();
	void UpdateActorEventEmitters(const SGameUpdateEvent& updateEvent);
	void UpdateSensors(const SGameUpdateEvent& updateEvent, const TArrayRef<TEntityRef<ZActor>>& actors);
	void SelectBehaviors(const SGameUpdateEvent& updateEvent);
	void OnHitmanChanged(TEntityRef<ZHitman5> pOld, TEntityRef<ZHitman5> pNew);
	void UpdateItemPositions();
	void UpdateStats();
	void UpdateEnemiezGlow();
	void UpdateItemsGlow();
	void UpdateEnabledAnimatedActors(const SGameUpdateEvent& updateEvent);
	void ClearAnimatedActorsCaches();
	void OnNavMeshCostChanged(ERegionMask mask, float oldCost, float newCost);
	void UpdateActorRenderModes(const TEntityRef<ZHitman5>& rHitman);
};
