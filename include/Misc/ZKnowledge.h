#pragma once

#include "ZSharedPointerTarget.h"
#include "TMap.h"
#include "SCondition_Cooldown.h"
#include "ZGameTime.h"
#include "TEntityRef.h"
#include "SKnownEntity.h"
#include "ZGridNodeRef.h"
#include "ZSequenceControllerEntity.h"
#include "SBehavior_Waypoint.h"
#include "ZHM5CoverPlane.h"
#include "EHMAttentionType.h"
#include "EGameTension.h"
#include "ZHM5BodyContainer.h"
#include "ZCrowdActor.h"
#include "SBehaviorTreeContext.h"
#include "ZActiveBehavior.h"
#include "ZFiber.h"
#include "ZActorKnownEntitiesEnumerator.h"
#include "EAIEventType.h"
#include "ZPF5Location.h"

class ZActor;

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
    __int8 m_bHasWeapon : 1;
    __int8 m_bIsControlled : 1;
    __int8 m_bAllowRagdollHitReactions : 1;
    __int8 bHMAttentionOutOfSight : 1;
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
    __int8 m_bInBehaviorSequence : 1;
    float m_fForceMinHP;
    float m_fCurrentHitPoints;
    unsigned __int16 m_nCrowdActorReleaseTimer;
    TEntityRef<ZCrowdActor> m_pCrowdActor;
    float m_fAimingStartTime;
    float m_fShootTime;
    float m_fBodyHitTimer;
    unsigned __int8 m_nKnownDeadBodies;
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

    virtual ~ZKnowledge();
    ZActiveBehavior* GetCurrentActiveBehavior();
    TRefCountPtrArg<SKnownEntity>* GetSelf(TRefCountPtrArg<SKnownEntity>* result);
    EGameTension GetGameTension();
    const ZSharedKnowledgeRef* GetShared();
    float GetHMAttention();
    ZGridNodeRef* GetActorGridNode(ZGridNodeRef* result);
    unsigned __int8 GetNumKnownDeadBodies();
    void IncreaseKnownDeadBodies();
    TEntityRef<ZActor>* Self();
    ZSharedKnowledgeRef* GetBloodPool(ZSharedKnowledgeRef* result);
    EActorPerceptionSensitivity GetPerceptionSensitivity();
    TEntityRef<ZCrowdActor>* GetCrowdActor(TEntityRef<ZCrowdActor>* result);
    float DistanceTo(float4* pos);
    ZActorKnownEntitiesEnumerator GetKnownEntityEnumerator();
    float4* GetCameFromPosition(float4* result);
    bool HasCameFromPosition();
    float GetHitPoints();
    void SetCrowdActorReleaseTimer(unsigned __int16 nFrames);
    unsigned __int16 GetCrowdActorReleaseTimer();
    TEntityRef<ZHM5BodyContainer>* GetBodyContainer(TEntityRef<ZHM5BodyContainer>* result);
    void SetBodyHitTimer(float time);
    void SetForceMinHP(float fForceMinHP);
    void SetBodyContainer(TEntityRef<ZHM5BodyContainer> pContainer);
    bool IsControlled();
    float GetBodyHitTimer();
    ZHM5CoverPlane* GetCurrentCover();
    void SetCurrentCover(ZHM5CoverPlane* pCover);
    bool IsBloodPoolPlaced();
    bool GetAllowRagdollDamageReactions();
    void SetCurrentHitpoints(float fHitpoints);
    const SMatrix* GetTransform();
    void ReleaseControlled();
    void AdjustHitpoint(float fDeltaHitpoints);
    void SetHMAttention(float fAttention);
    void SetHMAttentionType(EHMAttentionType eType);
    void SetHMAttentionGainOutOfSight(bool bVal);
    bool GetHMAttentionGainOutOfSight();
    float GetAmbientTime();
    static int GetSharedKnowledgeCount();
    static ZSharedKnowledgeRef* GetSharedKnowledgeByIndex(ZSharedKnowledgeRef* result, int nIndex);
    void SetHelpPoint(TEntityRef<ZSpatialEntity>* pHelpPoint);
    TEntityRef<ZSpatialEntity>* GetHelpPoint(TEntityRef<ZSpatialEntity>* result);
    void DeleteBloodPool();
    void RemoveKnownEntity(TRefCountPtr<SKnownEntity>* knownEntity);
    TRefCountPtrArg<SKnownEntity>* AddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef* pShared);
    TRefCountPtrArg<SKnownEntity>* GetKnownLocation(TRefCountPtrArg<SKnownEntity>* result, float4* vPosition, unsigned __int16 room);
    TRefCountPtr<SKnownEntity>* FindUnhandled(TRefCountPtr<SKnownEntity>* result, EAIEventType type);
    TRefCountPtr<SKnownEntity>* FindCurrent(TRefCountPtr<SKnownEntity>* result, EAIEventType type);
    TRefCountPtr<SKnownEntity>* FindCurrent(TRefCountPtr<SKnownEntity>* result, EAIEventType type, float maxAge);
    void MarkAllHandled(EAIEventType type);
    bool HasUnhandledEvent(EAIEventType eEventType);
    unsigned int HasEvent(EAIEventType eEventType);
    TRefCountPtrArg<SKnownEntity>* GetKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef* pShared);
    void SetHasWeapon(bool bHasWeapon);
    bool UpdateCrowdReleaseTimer();
    void SetGameTension(EGameTension tension);
    void SetTransform(SMatrix* mTransform, ZPF5Location* location);
    void RemoveAllKnownEntities(bool bKeepSelf);
    static ZSharedKnowledgeRef* FindSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity);
    static ZSharedKnowledgeRef* FindSharedKnowledgeWithOutfit(ZSharedKnowledgeRef* result, ZEntityRef* rEntity, TEntityRef<IHM5Outfit> rOutfit);
    TRefCountPtrArg<SKnownEntity>* FindOrAddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef pShared);
    TRefCountPtr<SKnownEntity>* FindEvent(TRefCountPtr<SKnownEntity>* result, EAIEventType type);
    void ExpireAllEvents(EAIEventType type);
    TRefCountPtrArg<SKnownEntity>* GetKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref);
    TRefCountPtrArg<SKnownEntity>* GetHitman(TRefCountPtrArg<SKnownEntity>* result);
    void CleanupCurrentBehavior();
    void TerminateCurrentBehavior();
    void OnBehaviorTreeChanged();
    void TerminateBehavior();
    bool ProcessSuggestedBehavior(SBehaviorBase** pSelected, SBehaviorTreeContext* context, SBehaviorBase* pLastSelected);
    void InitializeCurrentBehavior(SBehaviorBase* pBehavior);
    void EnterControlled();
    void RemoveReferencesToEntity(ZEntityRef* ref);
    TRefCountPtr<SKnownEntity>* FindCurrentSharedEvent(TRefCountPtr<SKnownEntity>* result, EAISharedEventType type);
    void UpdateBehaviorSelection();
    void SelectCompiledBehavior();
    ZKnowledge();
    static ZSharedKnowledgeRef* AddSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity);
    static ZSharedKnowledgeRef* FindOrAddSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity);
    TRefCountPtrArg<SKnownEntity>* AddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref);
    TRefCountPtrArg<SKnownEntity>* FindOrAddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref);
    TRefCountPtrArg<SKnownEntity>* AddKnownLocation(TRefCountPtrArg<SKnownEntity>* result, float4* vPosition, float fRadius, unsigned __int16 room);
    TRefCountPtrArg<SKnownEntity>* SetKnownLocation(TRefCountPtrArg<SKnownEntity>* result, EAIEventType nEvent, float4* vPosition, float fRadius, unsigned __int16 nRoom);
    void PlaceBloodPool();
    void SetSelfEntity(TEntityRef<ZActor>* pSelf);
    void SetAllowCutSequence(bool bAllow);
    void SetWaypointBehavior(SBehavior_Waypoint* pWaypointBehavior);
    SBehavior_Waypoint* GetWaypointBehavior();
    void SetWaypointIndex(int nWaypointIndex);
    int GetWaypointIndex();
    TEntityRef<ZSequenceControllerEntity>* GetSequenceController(TEntityRef<ZSequenceControllerEntity>* result);
    void SetLastReachedWaypoint(TEntityRef<ZWaypointEntity> pWaypoint);
    TEntityRef<ZWaypointEntity>* GetLastReachedWaypoint(TEntityRef<ZWaypointEntity>* result);
    void SetPerceptionSensitivitySequence(EActorPerceptionSensitivity sensitivity);
    float GetHMSoundDistance();
    void SetHMSoundDistance(float fWalkDistance);
    void ResetCameFromPosition();
    bool HasWeapon();
    void SetCameFromPosition(float4* v);
    void SetPerceptionSensitivityAct(EActorPerceptionSensitivity sensitivity);
    void SetAllowRagdollDamageReactions(bool bAllow);
    SBehaviorBase* GetCurrentCompiledBehavior();
    bool GetAllowCutSequence();
    void SetSequenceController(TEntityRef<ZSequenceControllerEntity> pSequenceCtrl);
    void SetCrowdActor(TEntityRef<ZCrowdActor> pCrowdActor);
    void AbortCurrentBehavior();
};
