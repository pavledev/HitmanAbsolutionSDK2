#pragma once

#include "ZEntityImpl.h"
#include "IHM5BaseCharacter.h"
#include "IBaseCharacter.h"
#include "IMorphemeCutSequenceAnimatable.h"
#include "IBoneCollidable.h"
#include "IPhysicsSystem.h"
#include "IHM5Animator.h"
#include "IMorphemeEntity.h"
#include "ZRenderableEntity.h"
#include "IEventConsumerCollection.h"
#include "IHM5Outfit.h"
#include "SFreeBone.h"
#include "sHand.h"
#include "SBoneAttachment.h"
#include "ZCrowdActorCore.h"
#include "TMaxArray.h"
#include "SChildNetworkInfo.h"
#include "ZVolumeTriggerListenerEntity.h"
#include "SAnimSample.h"
#include "sBack.h"
#include "IChildNetworkEntity.h"
#include "SGameUpdateEvent.h"
#include "IHM5ItemWeapon.h"
#include "ZCrowdEntity.h"
#include "ZComponentCreateInfo.h"

class alignas(16) ZHM5BaseCharacter : public ZEntityImpl, public IHM5BaseCharacter, public IBaseCharacter, public IMorphemeCutSequenceAnimatable, public IBoneCollidable
{
public:
    IPhysicsSystem* m_pBodyColi;
    float m_fNPCCollisionRadiusScale;
    float m_fNPCCollisionFrontOffset;
    ZEntityRef m_MorphemeEntityID;
    ZEntityRef m_OutfitEntity;
    ZEntityRef m_Animator;
    ZEntityRef m_EventConsumerCollection;
    TEntityRef<IHM5Animator> m_pAnimator;
    TEntityRef<IMorphemeEntity> m_pMorphemeEntity;
    TEntityRef<ZGeomEntity> m_rGeomEntity;
    TEntityRef<ZRenderableEntity> m_pRenderableEntity;
    TEntityRef<ZLinkedEntity> m_pGeomLinkedEntityInterface;
    TEntityRef<IEventConsumerCollection> m_pEventConsumerCollectionInterface;
    TEntityRef<IHM5Outfit> m_OutfitWorn;
    __int8 m_bBodyColiEnabled : 1;
    __int8 m_bBodyColiInitialized : 1;
    __int8 m_bIgnoreOnePositionChange : 1;
    __int8 m_bBaseCharInitialized : 1;
    __int8 m_bShootColiPrimitiveActive : 1;
    __int8 m_bShootColiSystemActive : 1;
    __int8 m_bInitialized : 1;
    __int8 m_bInitializingBaseCharacter : 1;
    __int8 m_bIsInCrowd : 1;
    __int8 m_bIsInLimitVisionAreaZone : 1;
    __int8 m_bIsInsideLimitVisionArea : 1;
    __int8 m_bIsBlockedByLimitVisionArea : 1;
    SFreeBone* m_pFreeBone;
    sHand* m_pRightHand;
    sHand* m_pLeftHand;
    ZHM5Ragdoll* m_pRagdoll;
    IPhysicsObject* m_pGrabDummy;
    SVector3 m_vGrabDummyLastPos;
    float m_fGrabDummyLastGameTime;
    unsigned int m_nGrabPart;
    TArray<SBoneAttachment> m_aAttachments;
    IPhysicsObject* m_pShootColiPrimitive;
    IPhysicsSystem* m_pShootColiSystem;
    TArray<TEntityRef<ZLinkedEntity>> m_SecondaryColisionEntities;
    float m_fRagdollSpeedMultiplier;
    float m_SequenceBlendDuration;
    ZMorphemeEventConsumerList m_EventConsumers;
    ISequenceEntity* m_pBoneAnimatedSequenceEntity;
    ZCrowdActorCore* m_pCrowdCore;
    unsigned __int16 m_CrowdObstacleType;
    float m_nCurAvoidParam;
    float m_nTargetAvoidParam;
    float m_nAvoidBlendInPerSec;
    float m_nAvoidBlendOutPerSec;
    float m_nAvoidDelayTimer;
    float m_nAvoidBlendSpeedFactor;
    ZEvent<TEntityRef<IHM5Outfit>, TEntityRef<IHM5Outfit>, ZEventNull, ZEventNull, ZEventNull> m_OutfitChangedEvent;
    float m_fOverallHeight;
    float m_fHeight;
    float m_fRadius;
    float m_fDisruptionRadius;
    float m_fSphereRadius;
    ZMorphemeNetworkInstance* m_pMorphemeNetwork;
    ZEvent0 m_animatableChangedEvent;
    alignas(16) float4 m_vPrevPosition;
    float4 m_vVelocity;
    ZGameTime m_TimeOfRagdollGrab;
    TMaxArray<SChildNetworkInfo, 8> m_childNetworkInfo;
    TEntityRef<ZVolumeTriggerListenerEntity> m_pActiveVolumeTriggerListener;
    unsigned int m_fullbodyParamID;
    unsigned int m_upperbodyParamID;

    virtual ~ZHM5BaseCharacter();
    virtual ZVariantRef* GetVariantRef(ZVariantRef * result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID * iid);
    virtual void Activate(ZString * sSubset);
    virtual void Deactivate(ZString * sSubset);
    virtual void Init();
    virtual bool PickupItem(TEntityRef<IHM5Item> * rItem);
    virtual bool SwapItem(TEntityRef<IHM5Item> * rNewItem, TEntityRef<IHM5Item> * rDisposedItem);
    virtual bool AddItemToInventory(TEntityRef<IHM5Item> * rItem);
    virtual void RemoveItemFromInventory(TEntityRef<IHM5Item> * rItem);
    virtual bool IsHandsEmpty();
    virtual bool IsHoldingWeapon();
    virtual void AttachItemToRHand(TEntityRef<IHM5Item> * rItem);
    virtual void AttachItemToLHand(TEntityRef<IHM5Item> * rItem);
    virtual void AttachItemToFreeBone(TEntityRef<IHM5Item> * rItem);
    virtual TEntityRef<IHM5Item>* DetachItemFromRHand(TEntityRef<IHM5Item> * result, bool bAddToPhysicWorld);
    virtual TEntityRef<IHM5Item>* DetachItemFromLHand(TEntityRef<IHM5Item> * result, bool bAddToPhysicWorld);
    virtual TEntityRef<IHM5Item>* DetachItemFromFreeBone(TEntityRef<IHM5Item> * result, bool bAddToPhysicWorld);
    virtual void ItemDestoyed(TEntityRef<IHM5Item> pItem);
    virtual void SetRagdollSpeedMultiplier(float f);
    virtual bool IsArmed();
    virtual void AimCallBack(bool bRightHand);
    virtual TEntityRef<ZGeomEntity>* GetGeomEntity(TEntityRef<ZGeomEntity> * result);
    virtual ZGeomEntity* GetGeomEntityPtr();
    virtual ZSpatialEntity* GetSpatialEntityPtr();
    virtual TEntityRef<ZSpatialEntity>* GetSpatialEntity(TEntityRef<ZSpatialEntity> * result);
    virtual ZLinkedEntity* GetLinkedEntityPtr();
    virtual TEntityRef<ZLinkedEntity>* GetLinkedEntity(TEntityRef<ZLinkedEntity> * result);
    virtual bool DeactivateLocoMotion();
    virtual void ShowCharacter(bool bShow);
    virtual bool IsCharacterHidden();
    virtual bool IsPoweredRagdoll();
    virtual bool IsPoweredRagdollStopping();
    virtual bool IsRagdollGrabbed();
    virtual bool IsRagdollControlled();
    virtual IPhysicsObject* GetGrabAttacher();
    virtual bool InValidGrabRagdollState();
    virtual bool CanGrabRagdoll(unsigned int* nPartId, float4 * vPos, float fThreshold);
    virtual bool GrabRagdoll(unsigned int nPartId, float4 * vPos);
    virtual void UpdateGrabPosition(SMatrix * mTrans);
    virtual void ReleaseGrabbedRagdoll(ICharacterController * pGrabber);
    virtual void ActivateRagdoll();
    virtual void ActivatePoweredRagdoll(bool bImpactPower, bool bHeadshot);
    virtual void DeactivatePoweredRagdoll(float fBlendOutTime, bool bToAnimation);
    virtual void ReleaseRagdoll();
    virtual void WakeUpRagdoll(float fTime);
    virtual void SetUpdateRagdollOnce();
    virtual void ActivateRagdollInMotion();
    virtual bool IsPoweredRagdollActive();
    virtual bool RequestAnimationDriven();
    virtual bool IsWearingOutfit();
    virtual const TEntityRef<IHM5Outfit>* GetOutfit(TEntityRef<IHM5Outfit> * result);
    virtual void SetOriginalOutfit(TEntityRef<IHM5Outfit> pOutfit);
    virtual const TEntityRef<IHM5Outfit>* GetOriginalOutfit(TEntityRef<IHM5Outfit> * result);
    virtual void SetOutfit(TEntityRef<IHM5Outfit> * outfit);
    virtual bool WillRequestBeReceived(unsigned int nRequestID);
    virtual bool WillRequestBeReceived(ZString * sRequest);
    virtual bool IsDead();
    virtual bool CanBeDragged();
    virtual TEntityRef<IMorphemeEntity>* GetMorphemeEntity(TEntityRef<IMorphemeEntity> * result);
    virtual bool CanPlayAnim(SMatrix * mStart, unsigned int iAnimNode);
    virtual bool CanPlayAnim(SMatrix * mStart, unsigned int iAnimNode, unsigned int* apBoneList, unsigned int iNumBones, float* apFractions, unsigned int iNumFractions, float* pfFractionFailed);
    virtual bool IsOnPathFinder(unsigned int* apBoneList, unsigned int iNumBones, float fHeightOffset);
    virtual void SampleAnim(unsigned int iAnimNode, unsigned int* apBoneList, unsigned int iNumBones, float* apFractions, unsigned int iNumFractions, SAnimSample * AnimSample);
    virtual void ResetCharacter();
    virtual SMatrix* GetObjectToWorldMatrix(SMatrix * result);
    virtual const SMatrix* GetObjectToParentMatrix(SMatrix * result);
    virtual float4* GetWorldPosition(float4 * result);
    virtual float4* GetWorldForward(float4 * result);
    virtual const float4* GetLocalPosition(float4 * result);
    virtual void GetCharacterOBB(SMatrix * m0, float4 * vSize);
    virtual ZEvent<TEntityRef<IHM5Outfit>, TEntityRef<IHM5Outfit>, ZEventNull, ZEventNull, ZEventNull>* GetOutfitChangedEvent();
    virtual void SetInstantiateNetwork(bool bInstantiate);
    virtual void ReinitializeMorphemeData();
    virtual void AddEventConsumer(TEntityRef<IEventConsumerCollection> pConsumer);
    virtual void RemoveEventConsumer(TEntityRef<IEventConsumerCollection> pConsumer);
    virtual void GetOBB(SMatrix * mvCen, float4 * vHalfSize);
    virtual float4* GetOBBRadius(float4 * result);
    virtual SMatrix* GetCenterMatPos(SMatrix * result);
    virtual bool IsInitializationDone();
    virtual bool CreateBodyCollision();
    virtual void UpdateBodyCollisionPoses(bool bMoveTransform);
    virtual void OnAnimatorChanged();
    virtual bool ShouldDoHardCrowdPushes();
    virtual void SetSequenceWeight(float weight, unsigned int track);
    virtual void SetSequenceFeatherWeight(float weight, unsigned int track);
    virtual void BlendOutSequenceWeights();
    virtual void OnOutfitEntityChanged();
    virtual void HandleMorphemeEntityIDChanged();
    virtual ZHM5Ragdoll* AcquireRagdollInstance(float4 * vSearchPos);
    virtual bool EnsureBaseCharacterInit();
    virtual void YouGotHit(SHitInfo * HitInfo);
    virtual bool CanProjectileHitCharacter(SHitInfo * HitInfo);
    virtual unsigned __int16 GetCollisionLayer();
    virtual bool RegisterAttachment(unsigned int nBoneID, TEntityRef<ZSpatialEntity> Attachment);
    virtual void UnregisterAttachment(unsigned int nBoneID, TEntityRef<ZSpatialEntity> Attachment);
    virtual bool IsRagdoll();
    virtual ZEntityRef* GetLinkedEntityBase(ZEntityRef * result);
    virtual void CutSequenceStarted(ISequenceEntity * pSequence, ZString * sSlotName, float fBodyPartSelector);
    virtual void CutSequenceUpdate(ISequenceEntity * pSequence, ZString sSlotName, float fWeight);
    virtual SMatrix43* CutSequenceGetWorldTransform(SMatrix43 * result);
    virtual void CutSequenceSetWorldTransform(SMatrix43 * mNewWorldTransform);
    virtual SMatrix43* CutSequenceGetParentTransform(SMatrix43 * result);
    virtual void CutSequenceSetParentTransform(SMatrix43 * mNewParentTransform);
    virtual void CutSequenceEnded(ISequenceEntity * pSequence, ZString sSlotName);
    virtual ZEvent0* GetAnimatableChangedEvent();
    virtual void AbortCutSequence();
    virtual bool SetCutSequenceData(ISequenceEntity * pSequence, SCutSequenceData * cutSequenceData, ZString * sSlotName, float fBodyPartSelector);
    virtual bool CheckLineCollision(ZRayQueryInput * sInput, ZRayQueryOutput * pOutput);
    virtual ICharacterController* GetCharacterController();

    TEntityRef<ZRenderableEntity>* GetRenderableEntity(TEntityRef<ZRenderableEntity> * result);
    TEntityRef<IHM5Item>* GetRightHandItem(TEntityRef<IHM5Item> * result);
    ZHM5BaseCharacter* operator=(ZHM5BaseCharacter * __that);
    ZHM5BaseCharacter(ZHM5BaseCharacter * __that);
    void SetNPCCollisionWithHitmanParams(float fRadiusScale, float fFrontOffset);
    TEntityRef<IHM5ItemWeapon>* GetRightHandWeapon(TEntityRef<IHM5ItemWeapon> * result);
    ZHM5Ragdoll* GetHM5Ragdoll();
    TEntityRef<IHM5Item>* GetLeftHandItem(TEntityRef<IHM5Item> * result);
    TEntityRef<IHM5ItemWeapon>* GetLeftHandWeapon(TEntityRef<IHM5ItemWeapon> * result);
    ZCrowdActorCore* GetCrowdCore();
    bool IsInCrowd();
    float4* GetVelocity(float4 * result);
    bool IsShotColiAddded();
    void SetShootColiSystemActive(bool bAdd);
    void ReleaseShootColiSystem();
    bool ShootColiInitialized();
    void UpdateBodyCollision();
    void ReleaseBodyColi();
    void SetShootColiPrimitiveActive(bool bAdd);
    bool InBoneAnimatedSequence();
    void SendEventsToConsumers();
    void ApplyExplosionOnRagdoll(SExplodeInfo * explosionInfo, float4 * vOrigin);
    IPhysicsSystem* GetBodyColi();
    void OnAnimationRigChanged(ZAnimationRig * pRig, SMatrix * pTranslation);
    void RagdollEaseInAfterGrab(ZGameTime * Now);
    ZMorphemeNetworkInstance* GetAttachedChildNetworkInstanceFromInstanceId(int nInstanceId);
    void DestroyChildNetworkInstance(int nNetworkInstanceId);
    void SetBodyCollisionEnabled(bool bEnabled);
    void ReleaseShootColiPrimitive();
    void ReleaseShootColi();
    void HandleTriggeredEvents();
    TEntityRef<ZCrowdEntity>* GetCurrentCrowd(TEntityRef<ZCrowdEntity> * result);
    void UpdateAvoidParam(float nDt);
    TEntityRef<IHM5Item>* GetFreeBoneItem(TEntityRef<IHM5Item> * result);
    void ApplyImpulseOnRagdoll(float4 * vPosition, float4 * vImpulse, unsigned int nBoneIndex, bool bRandomize);
    void UpdateInCrowdFlag();
    bool IsInAmbientCrowd();
    void InitHand(sHand * pHand);
    void InitBack(sBack * pBack);
    void InitFreeBone(SFreeBone * pFreeBone);
    bool IsGrabPathClear(float4 * vGrabTargetPos);
    void SetupGeomAnimatorLink();
    void UpdateShootColiPrimitive(bool bMoveInsteadOfSet);
    bool IsOnScreen();
    ZMorphemeNetworkInstance* GetMorphemeNetwork();
    int CreateChildNetworkInstance(TEntityRef<IChildNetworkEntity> * rChildNetworkEntity, bool bUseVariation);
    void CreateShootColiPrimitive();
    void CreateShootColiSystem();
    void UpdateShootColiSystem(bool bMoveInsteadOfSet);
    void PushCrowdActors();
    void InitBaseChar();
    void OnEventConsumerCollectionChanged();
    void UpdateShootColi();
    void ApplyHitInfoOnRagdoll(SHitInfo * HitInfo);
    void DetachChildNetwork(unsigned int nNodeId);
    void RequestDetachChildNetwork(unsigned int nNodeId, float fTimeOut);
    void UpdateChildNetworkInfo(SGameUpdateEvent * updateEvent);
    void CleanupChildNetworkInfo();
    void GetRenderableEntities(TMaxArray<TEntityRef<ZRenderableEntity>, 4> * RenderableEntities);
    void SetDontDraw(bool bDontDraw);
    void CreateShootColi();
    void SetShootColiActive(bool bAdd);
    void BaseCharacterUpdate(SGameUpdateEvent * updateEvent);
    void BaseCharacterRagdollOnlyUpdate(SGameUpdateEvent * updateEvent);
    void AddSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked);
    void RemoveSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked);
    bool SetupRagdoll();
    void OnMorphemeEntityUninitialized();
    void OnMorphemeEntityInitialized();
    void RegisterForAnimationRigChangeListening();
    void UnregisterForAnimationRigChangeListening();
    static void InitShootColiSystemData();
    static void DestroyShootColiSystemData();
    ZMorphemeNetworkInstance* GetAttachedChildNetworkInstance(unsigned int nNodeId);
    bool InternalAttachChildNetwork(unsigned int nNodeId, int nInstanceId);
    void SetFPSDrawMode(bool bFPSDrawMode);
    static void AddBaseCharacter();
    static void RemoveBaseCharacter();
    bool AttachChildNetwork(unsigned int nNodeId, TEntityRef<IChildNetworkEntity> * rChildNetworkEntity, bool bUseVariation);
    bool AttachChildNetwork(unsigned int nNodeId, ZResourcePtr * networkResourcePtr);
    ZHM5BaseCharacter(ZComponentCreateInfo * pInfo);
    static void RegisterType();
    float GetNPCCollisionRadiusScale();
    float GetNPCCollisionFrontOffset();
    void SetForceBoneUpdate(bool bForce);
    bool IsInLimitVisionAreaZone();
    bool IsInsideLimitVisionArea();
    bool IsBlockedByLimitVisionArea();
    void SetCrowdObstacleType(unsigned __int16 type);
    const TEntityRef<ZVolumeTriggerListenerEntity>* GetActiveVolumeTriggerListener(TEntityRef<ZVolumeTriggerListenerEntity> * result);
    void SetActiveVolumeTriggerListener(TEntityRef<ZVolumeTriggerListenerEntity> * volumeTrigger);
    void SetInLimitVisionAreaZone(bool bIsInLimitVisionAreaZone);
    void SetInsideLimitVisionArea(bool bInsideLimitVisionArea);
    void SetIsBlockedByLimitVisionArea(bool bIsBlockedByLimitVisionArea);
    unsigned __int16 GetCrowdObstacleType();
};
