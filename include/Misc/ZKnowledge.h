#pragma once

#include "ZSharedPointerTarget.h"
#include "TMap.h"
#include "ZGameTime.h"
#include "TEntityRef.h"
#include "ZGridNodeRef.h"
#include "EHMAttentionType.h"
#include "EGameTension.h"
#include "SBehaviorTreeContext.h"
#include "ZKnownEntityContainer.h"
#include "EAIEventType.h"
#include "EAISharedEventType.h"
#include "EActorPerceptionSensitivity.h"
#include "TMaxArray.h"
#include "TRefCountPtr.h"
#include "TRefCountPtrArg.h"
#include "ZEntityRef.h"
#include "ZSharedKnowledgeRef.h"
#include "float4.h"

class ZActor;
class IHM5Outfit;
class ZActiveBehavior;
class ZCrowdActor;
class ZFiber;
class ZHM5BodyContainer;
class ZHM5CoverPlane;
class ZPF5Location;
class ZSequenceControllerEntity;
class ZSpatialEntity;
class ZWaypointEntity;
struct SBehaviorBase;
struct SBehavior_Waypoint;
struct SCondition_Cooldown;
struct SKnownEntity;
struct SMatrix;

class ZKnowledge : public ZSharedPointerTarget
{
public:
	TMap<SCondition_Cooldown const*, ZGameTime> m_cooldowns;
	char m_nHitmanVisibilityBoneIndex;
	char m_nHitmanVisibilityRayCount;
	TEntityRef<ZActor> m_pSelf;
	TRefCountPtr<SKnownEntity> m_pSelfKnown;
	ZSharedKnowledgeRef m_pSelfSharedKnowledge;
	ZGridNodeRef m_actorGridNode;
	TRefCountPtr<SKnownEntity> m_pHitmanKnown;
	TEntityRef<ZSequenceControllerEntity> m_pSequence;
	bool m_bAllowCutSequence;
	bool m_bInSequenceBehavior;
	SBehavior_Waypoint* m_pWaypointBehavior;
	int m_nWaypointIndex;
	TEntityRef<ZWaypointEntity> m_pLastReachedWaypoint;
	TEntityRef<ZSpatialEntity> m_pHelpPoint;
	ZHM5CoverPlane* m_pCurrentCover;
	bool m_bHasWeapon : 1;
	bool m_bIsControlled : 1;
	bool m_bAllowRagdollHitReactions : 1;
	bool bHMAttentionOutOfSight : 1;
	float m_fHMSoundDistance;
	float m_fHMAttention;
	EHMAttentionType m_eAttentionType;
	EGameTension m_eGameTension;
	ZGameTime m_tAmbientStartTime;
	EActorPerceptionSensitivity m_ePerceptionSensitivityAct;
	EActorPerceptionSensitivity m_ePerceptionSensitivitySequence;
	ZEntityRef m_pBloodPoolEntity;
	ZSharedKnowledgeRef m_pBloodPoolKnownEntity;
	TEntityRef<ZHM5BodyContainer> m_pBodyContainer;
	bool m_bInBehaviorSequence : 1;
	float m_fForceMinHP;
	float m_fCurrentHitPoints;
	unsigned short m_nCrowdActorReleaseTimer;
	TEntityRef<ZCrowdActor> m_pCrowdActor;
	float m_fAimingStartTime;
	float m_fShootTime;
	float m_fBodyHitTimer;
	unsigned char m_nKnownDeadBodies;
	TMaxArray<SBehaviorBase*, 2> m_pendingBehaviors;
	SBehaviorBase* m_pPendingBehavior;
	TMaxArray<SBehaviorBase*, 2> m_currentBehaviors;
	bool m_bAbortCurrentBehavior;
	SBehaviorBase* m_pCurrentBehavior;
	SBehaviorTreeContext m_savedBehaviorContext;
	SBehaviorBase* m_pLastSelected;
	ZActiveBehavior* m_pCurrentActiveBehavior;
	ZFiber* m_pCurrentBehaviorFiber;
	float4 m_vCameFromPosition;

	~ZKnowledge() override = default;

	ZKnowledge() = default;
	void SetSelfEntity(const TEntityRef<ZActor>& pSelf);
	TEntityRef<ZActor>& Self();
	const SMatrix& GetTransform() const;
	ZGridNodeRef GetActorGridNode() const;
	void SetTransform(const SMatrix& mTransform, const ZPF5Location& location);
	void SetSequenceController(TEntityRef<ZSequenceControllerEntity> pSequenceCtrl);
	TEntityRef<ZSequenceControllerEntity> GetSequenceController() const;
	void SetAllowCutSequence(bool bAllow);
	bool GetAllowCutSequence() const;
	void SetPerceptionSensitivityAct(EActorPerceptionSensitivity sensitivity);
	void SetPerceptionSensitivitySequence(EActorPerceptionSensitivity sensitivity);
	EActorPerceptionSensitivity GetPerceptionSensitivity() const;
	void SetAllowRagdollDamageReactions(bool bAllow);
	bool GetAllowRagdollDamageReactions();
	TEntityRef<ZSpatialEntity> GetHelpPoint() const;
	void SetHelpPoint(const TEntityRef<ZSpatialEntity>& pHelpPoint);
	float DistanceTo(const float4& pos) const;
	bool HasWeapon() const;
	void SetHasWeapon(bool bHasWeapon);
	void SetWaypointBehavior(SBehavior_Waypoint* pWaypointBehavior);
	SBehavior_Waypoint* GetWaypointBehavior() const;
	void SetWaypointIndex(int nWaypointIndex);
	int GetWaypointIndex() const;
	void SetLastReachedWaypoint(TEntityRef<ZWaypointEntity> pWaypoint);
	TEntityRef<ZWaypointEntity> GetLastReachedWaypoint();
	void RemoveReferencesToEntity(const ZEntityRef& ref);
	TRefCountPtrArg<SKnownEntity> GetSelf() const;
	TRefCountPtrArg<SKnownEntity> GetHitman();
	TRefCountPtrArg<SKnownEntity> GetKnownEntity(const ZSharedKnowledgeRef& pShared) const;
	TRefCountPtrArg<SKnownEntity> GetKnownEntity(const ZEntityRef& ref) const;
	TRefCountPtrArg<SKnownEntity> AddKnownEntity(const ZEntityRef& ref);
	TRefCountPtrArg<SKnownEntity> AddKnownEntity(const ZSharedKnowledgeRef& pShared);
	TRefCountPtrArg<SKnownEntity> FindOrAddKnownEntity(const ZSharedKnowledgeRef pShared);
	TRefCountPtrArg<SKnownEntity> FindOrAddKnownEntity(const ZEntityRef& ref);
	TRefCountPtrArg<SKnownEntity> GetKnownLocation(const float4& vPosition, unsigned short room);
	TRefCountPtrArg<SKnownEntity> AddKnownLocation(const float4& vPosition, float fRadius, unsigned short room);
	TRefCountPtrArg<SKnownEntity> SetKnownLocation(EAIEventType nEvent, const float4& vPosition, float fRadius, unsigned short nRoom);
	ZKnownEntityContainer::ZActorKnownEntitiesEnumerator GetKnownEntityEnumerator() const;
	void RemoveKnownEntity(const TRefCountPtr<SKnownEntity>& knownEntity);
	void RemoveAllKnownEntities(bool bKeepSelf);
	bool HasUnhandledEvent(EAIEventType eEventType) const;
	unsigned int HasEvent(const EAIEventType eEventType) const;
	TRefCountPtr<SKnownEntity> FindEvent(EAIEventType type) const;
	TRefCountPtr<SKnownEntity> FindUnhandled(EAIEventType type) const;
	TRefCountPtr<SKnownEntity> FindCurrent(EAIEventType type, float maxAge) const;
	TRefCountPtr<SKnownEntity> FindCurrent(EAIEventType type) const;
	TRefCountPtr<SKnownEntity> FindCurrentSharedEvent(EAISharedEventType type) const;
	void MarkAllHandled(EAIEventType type);
	void ExpireAllEvents(EAIEventType type);
	static ZSharedKnowledgeRef FindSharedKnowledge(const ZEntityRef& pEntity);
	static ZSharedKnowledgeRef FindSharedKnowledgeWithOutfit(const ZEntityRef& rEntity, TEntityRef<IHM5Outfit> rOutfit);
	static int GetSharedKnowledgeCount();
	static ZSharedKnowledgeRef GetSharedKnowledgeByIndex(int nIndex);
	static ZSharedKnowledgeRef AddSharedKnowledge(const ZEntityRef& pEntity);
	static ZSharedKnowledgeRef FindOrAddSharedKnowledge(const ZEntityRef& pEntity);
	ZHM5CoverPlane* GetCurrentCover() const;
	void SetCurrentCover(ZHM5CoverPlane* pCover);
	float GetHMAttention() const;
	void SetHMAttention(float fAttention);
	void SetHMAttentionType(EHMAttentionType eType);
	void SetHMAttentionGainOutOfSight(bool bVal);
	bool GetHMAttentionGainOutOfSight();
	float GetHMSoundDistance() const;
	void SetHMSoundDistance(float fWalkDistance);
	EGameTension GetGameTension() const;
	void SetGameTension(EGameTension tension);
	float GetAmbientTime();
	const ZSharedKnowledgeRef& GetShared() const;
	void DeleteBloodPool();
	void PlaceBloodPool();
	bool IsBloodPoolPlaced();
	ZSharedKnowledgeRef GetBloodPool();
	void SetBodyContainer(TEntityRef<ZHM5BodyContainer> pContainer);
	TEntityRef<ZHM5BodyContainer> GetBodyContainer() const;
	void AdjustHitpoint(float fDeltaHitpoints);
	float GetHitPoints() const;
	void SetForceMinHP(float fForceMinHP);
	void SetCurrentHitpoints(float fHitpoints);
	void SetCrowdActorReleaseTimer(unsigned short nFrames);
	unsigned short GetCrowdActorReleaseTimer();
	TEntityRef<ZCrowdActor> GetCrowdActor() const;
	void SetCrowdActor(TEntityRef<ZCrowdActor> pCrowdActor);
	bool UpdateCrowdReleaseTimer();
	void SetBodyHitTimer(float time);
	float GetBodyHitTimer() const;
	void UpdateBehaviorSelection();
	void SelectCompiledBehavior();
	void EnterControlled();
	void ReleaseControlled();
	bool IsControlled() const;
	void AbortCurrentBehavior();
	ZActiveBehavior* GetCurrentActiveBehavior() const;
	SBehaviorBase* GetCurrentCompiledBehavior() const;
	void TerminateBehavior();
	void OnBehaviorTreeChanged();
	unsigned char GetNumKnownDeadBodies() const;
	void IncreaseKnownDeadBodies();
	void SetCameFromPosition(const float4& v);
	float4 GetCameFromPosition() const;
	bool HasCameFromPosition() const;
	void ResetCameFromPosition();
	void TerminateCurrentBehavior();
	void CleanupCurrentBehavior();
	bool ProcessSuggestedBehavior(SBehaviorBase*& pSelected, const SBehaviorTreeContext& context, SBehaviorBase* pLastSelected);
	void InitializeCurrentBehavior(SBehaviorBase* pBehavior);
};
