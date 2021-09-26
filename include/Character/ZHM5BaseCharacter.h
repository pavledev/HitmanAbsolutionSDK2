#pragma once

#include "ZEntityImpl.h"
#include "IHM5BaseCharacter.h"
#include "IBaseCharacter.h"
#include "IMorphemeCutSequenceAnimatable.h"
#include "IBoneCollidable.h"
#include "TMaxArray.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SMatrix43.h"
#include "SVector3.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZEvent0.h"
#include "ZGameTime.h"
#include "ZLinkedEntity.h"
#include "ZMorphemeEventConsumerList.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"
#include "float4.h"

class ICharacterController;
class IChildNetworkEntity;
class IEventConsumerCollection;
class IHM5Animator;
class IHM5Item;
class IHM5ItemWeapon;
class IHM5Outfit;
class IMorphemeEntity;
class IPhysicsObject;
class IPhysicsSystem;
class ISequenceEntity;
class ZAnimationRig;
class ZComponentCreateInfo;
class ZCrowdActorCore;
class ZCrowdEntity;
class ZEventNull;
class ZGeomEntity;
class ZHM5Ragdoll;
class ZMorphemeNetworkInstance;
class ZRayQueryInput;
class ZRayQueryOutput;
class ZRenderableEntity;
class ZSpatialEntity;
class ZString;
class ZVolumeTriggerListenerEntity;
struct SAnimSample;
struct SBoneAttachment;
struct SCutSequenceData;
struct SExplodeInfo;
struct SFreeBone;
struct SGameUpdateEvent;
struct SHitInfo;
struct STypeID;
struct sBack;
struct sHand;

class ZHM5BaseCharacter : public ZEntityImpl, public IHM5BaseCharacter, public IBaseCharacter, public IMorphemeCutSequenceAnimatable, public IBoneCollidable
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SChildNetworkInfo
	{
		struct SCompareNode
		{
			unsigned int m_nNodeId;

			SCompareNode(unsigned int nNodeId);
			bool operator()(const SChildNetworkInfo& element);
		};

		ZGameTime m_detachTime;
		unsigned int m_nNodeId;
		int m_nNetworkInstanceId;

		SChildNetworkInfo(const SChildNetworkInfo& __that);
		SChildNetworkInfo() = default;
		SChildNetworkInfo& operator=(const SChildNetworkInfo& __that);
	};

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
	bool m_bBodyColiEnabled : 1;
	bool m_bBodyColiInitialized : 1;
	bool m_bIgnoreOnePositionChange : 1;
	bool m_bBaseCharInitialized : 1;
	bool m_bShootColiPrimitiveActive : 1;
	bool m_bShootColiSystemActive : 1;
	bool m_bInitialized : 1;
	bool m_bInitializingBaseCharacter : 1;
	bool m_bIsInCrowd : 1;
	bool m_bIsInLimitVisionAreaZone : 1;
	bool m_bIsInsideLimitVisionArea : 1;
	bool m_bIsBlockedByLimitVisionArea : 1;
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
	unsigned short m_CrowdObstacleType;
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
	float4 m_vPrevPosition;
	float4 m_vVelocity;
	ZGameTime m_TimeOfRagdollGrab;
	TMaxArray<SChildNetworkInfo, 8> m_childNetworkInfo;
	TEntityRef<ZVolumeTriggerListenerEntity> m_pActiveVolumeTriggerListener;
	unsigned int m_fullbodyParamID;
	unsigned int m_upperbodyParamID;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snGotHit;
	static unsigned int m_snDeath;
	static TArray<ZLinkedEntity::ZCapsuleFit>* m_ShootColiSystemCapsules;
	static int ms_nBaseCharacterCount;
	static const int MAX_ATTACHED_CHILDNETWORKS;

	~ZHM5BaseCharacter() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	virtual bool PickupItem(const TEntityRef<IHM5Item>& rItem);
	virtual bool SwapItem(const TEntityRef<IHM5Item>& rNewItem, const TEntityRef<IHM5Item>& rDisposedItem);
	virtual bool AddItemToInventory(const TEntityRef<IHM5Item>& rItem);
	virtual void RemoveItemFromInventory(const TEntityRef<IHM5Item>& rItem);
	virtual bool IsHandsEmpty() const;
	virtual bool IsHoldingWeapon() const;
	virtual void AttachItemToRHand(const TEntityRef<IHM5Item>& rItem);
	virtual void AttachItemToLHand(const TEntityRef<IHM5Item>& rItem);
	virtual void AttachItemToFreeBone(const TEntityRef<IHM5Item>& rItem);
	virtual TEntityRef<IHM5Item> DetachItemFromRHand(bool bAddToPhysicWorld);
	virtual TEntityRef<IHM5Item> DetachItemFromLHand(bool bAddToPhysicWorld);
	virtual TEntityRef<IHM5Item> DetachItemFromFreeBone(bool bAddToPhysicWorld);
	virtual void ItemDestoyed(TEntityRef<IHM5Item> pItem);
	virtual void SetRagdollSpeedMultiplier(float f);
	virtual bool IsArmed();
	virtual void AimCallBack(bool bRightHand);
	virtual TEntityRef<ZGeomEntity> GetGeomEntity() const;
	virtual ZGeomEntity* GetGeomEntityPtr() const;
	virtual ZSpatialEntity* GetSpatialEntityPtr() const;
	virtual TEntityRef<ZSpatialEntity> GetSpatialEntity() const;
	virtual ZLinkedEntity* GetLinkedEntityPtr() const;
	virtual TEntityRef<ZLinkedEntity> GetLinkedEntity() const;
	virtual bool DeactivateLocoMotion();
	virtual void ShowCharacter(bool bShow);
	virtual bool IsCharacterHidden() const;
	virtual bool IsPoweredRagdoll() const;
	virtual bool IsPoweredRagdollStopping() const;
	virtual bool IsRagdollGrabbed() const;
	virtual bool IsRagdollControlled() const;
	virtual IPhysicsObject* GetGrabAttacher() const;
	virtual bool InValidGrabRagdollState() const;
	virtual bool CanGrabRagdoll(unsigned int& nPartId, const float4& vPos, float fThreshold) const;
	virtual bool GrabRagdoll(unsigned int nPartId, const float4& vPos);
	virtual void UpdateGrabPosition(const SMatrix& mTrans);
	virtual void ReleaseGrabbedRagdoll(ICharacterController* pGrabber);
	virtual void ActivateRagdoll();
	virtual void ActivatePoweredRagdoll(bool bImpactPower, bool bHeadshot);
	virtual void DeactivatePoweredRagdoll(float fBlendOutTime, bool bToAnimation);
	virtual void ReleaseRagdoll();
	virtual void WakeUpRagdoll(float fTime);
	virtual void SetUpdateRagdollOnce();
	virtual void ActivateRagdollInMotion();
	virtual bool IsPoweredRagdollActive() const;
	virtual bool RequestAnimationDriven();
	virtual bool IsWearingOutfit() const;
	virtual const TEntityRef<IHM5Outfit> GetOutfit() const;
	virtual void SetOriginalOutfit(TEntityRef<IHM5Outfit> pOutfit);
	virtual const TEntityRef<IHM5Outfit> GetOriginalOutfit() const;
	virtual void SetOutfit(const TEntityRef<IHM5Outfit>& outfit);
	virtual bool WillRequestBeReceived(const unsigned int nRequestID) const;
	virtual bool WillRequestBeReceived(const ZString& sRequest) const;
	virtual bool IsDead() const;
	virtual bool CanBeDragged() const;
	virtual TEntityRef<IMorphemeEntity> GetMorphemeEntity() const;
	virtual bool CanPlayAnim(const SMatrix& mStart, unsigned int iAnimNode);
	virtual bool CanPlayAnim(const SMatrix& mStart, unsigned int iAnimNode, unsigned int* apBoneList, unsigned int iNumBones, float* apFractions, unsigned int iNumFractions, float* pfFractionFailed);
	virtual bool IsOnPathFinder(unsigned int* apBoneList, unsigned int iNumBones, float fHeightOffset) const;
	virtual void SampleAnim(unsigned int iAnimNode, unsigned int* apBoneList, unsigned int iNumBones, float* apFractions, unsigned int iNumFractions, SAnimSample& AnimSample);
	virtual void ResetCharacter();
	virtual SMatrix GetObjectToWorldMatrix() const;
	virtual const SMatrix GetObjectToParentMatrix() const;
	virtual float4 GetWorldPosition() const;
	virtual float4 GetWorldForward() const;
	virtual const float4 GetLocalPosition() const;
	virtual void GetCharacterOBB(SMatrix& m0, float4& vSize) const;
	virtual ZEvent<TEntityRef<IHM5Outfit>, TEntityRef<IHM5Outfit>, ZEventNull, ZEventNull, ZEventNull>& GetOutfitChangedEvent();
	virtual void SetInstantiateNetwork(bool bInstantiate);
	virtual void ReinitializeMorphemeData();
	virtual void AddEventConsumer(TEntityRef<IEventConsumerCollection> pConsumer);
	virtual void RemoveEventConsumer(TEntityRef<IEventConsumerCollection> pConsumer);
	virtual void GetOBB(SMatrix& mvCen, float4& vHalfSize) const;
	virtual float4 GetOBBRadius() const;
	virtual SMatrix GetCenterMatPos() const;
	virtual bool IsInitializationDone() const;
	virtual bool CreateBodyCollision();
	virtual void UpdateBodyCollisionPoses(bool bMoveTransform);
	virtual void OnAnimatorChanged();
	virtual bool ShouldDoHardCrowdPushes() const;
	virtual void SetSequenceWeight(float weight, unsigned int track);
	virtual void SetSequenceFeatherWeight(float weight, unsigned int track);
	virtual void BlendOutSequenceWeights();
	virtual void OnOutfitEntityChanged();
	virtual void HandleMorphemeEntityIDChanged();
	virtual ZHM5Ragdoll* AcquireRagdollInstance(const float4& vSearchPos);
	virtual bool EnsureBaseCharacterInit();

	void YouGotHit(const SHitInfo& HitInfo) override;
	bool CanProjectileHitCharacter(const SHitInfo& HitInfo) override;
	unsigned short GetCollisionLayer() const override;
	bool RegisterAttachment(unsigned int nBoneID, TEntityRef<ZSpatialEntity> Attachment) override;
	void UnregisterAttachment(unsigned int nBoneID, TEntityRef<ZSpatialEntity> Attachment) override;
	bool IsRagdoll() const override;
	ZEntityRef GetLinkedEntityBase() const override;

	void CutSequenceStarted(ISequenceEntity* pSequence, const ZString& sSlotName, float fBodyPartSelector) override;
	void CutSequenceUpdate(ISequenceEntity* pSequence, ZString sSlotName, float fWeight) override;
	SMatrix43 CutSequenceGetWorldTransform() override;
	void CutSequenceSetWorldTransform(const SMatrix43& mNewWorldTransform) override;
	SMatrix43 CutSequenceGetParentTransform() override;
	void CutSequenceSetParentTransform(const SMatrix43& mNewParentTransform) override;
	void CutSequenceEnded(ISequenceEntity* pSequence, ZString sSlotName) override;
	ZEvent0& GetAnimatableChangedEvent() override;
	void AbortCutSequence() override;
	bool SetCutSequenceData(ISequenceEntity* pSequence, const SCutSequenceData& cutSequenceData, const ZString& sSlotName, float fBodyPartSelector) override;

	bool CheckLineCollision(const ZRayQueryInput& sInput, ZRayQueryOutput* pOutput) const override;
	ICharacterController* GetCharacterController() const override;

	ZHM5BaseCharacter() = default;
	static void RegisterType();
	ZHM5BaseCharacter(const ZHM5BaseCharacter& __that);
	ZHM5BaseCharacter(ZComponentCreateInfo& pInfo);
	TEntityRef<IHM5Item> GetRightHandItem() const;
	TEntityRef<IHM5Item> GetLeftHandItem() const;
	TEntityRef<IHM5ItemWeapon> GetRightHandWeapon() const;
	TEntityRef<IHM5ItemWeapon> GetLeftHandWeapon() const;
	TEntityRef<IHM5Item> GetFreeBoneItem() const;
	void AddSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked);
	void RemoveSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked);
	void BaseCharacterUpdate(const SGameUpdateEvent& updateEvent);
	void BaseCharacterRagdollOnlyUpdate(const SGameUpdateEvent& updateEvent);
	TEntityRef<ZRenderableEntity> GetRenderableEntity() const;
	bool InBoneAnimatedSequence() const;
	bool IsOnScreen();
	ZCrowdActorCore* GetCrowdCore() const;
	unsigned short GetCrowdObstacleType() const;
	bool IsInCrowd() const;
	bool IsInAmbientCrowd() const;
	TEntityRef<ZCrowdEntity> GetCurrentCrowd() const;
	void SetInLimitVisionAreaZone(bool bIsInLimitVisionAreaZone);
	bool IsInLimitVisionAreaZone() const;
	void SetInsideLimitVisionArea(bool bInsideLimitVisionArea);
	bool IsInsideLimitVisionArea() const;
	void SetIsBlockedByLimitVisionArea(bool bIsBlockedByLimitVisionArea);
	bool IsBlockedByLimitVisionArea() const;
	float4 GetVelocity() const;
	ZHM5Ragdoll* GetHM5Ragdoll();
	void SetForceBoneUpdate(bool bForce);
	IPhysicsSystem* GetBodyColi();
	void SetCrowdObstacleType(unsigned short type);
	void ApplyImpulseOnRagdoll(const float4& vPosition, const float4& vImpulse, unsigned int nBoneIndex, bool bRandomize);
	void ApplyExplosionOnRagdoll(const SExplodeInfo& explosionInfo, const float4& vOrigin);
	void SetNPCCollisionWithHitmanParams(float fRadiusScale, float fFrontOffset);
	float GetNPCCollisionRadiusScale() const;
	float GetNPCCollisionFrontOffset() const;
	void SetFPSDrawMode(const bool bFPSDrawMode);
	void SetDontDraw(const bool bDontDraw);
	void ApplyHitInfoOnRagdoll(const SHitInfo& HitInfo);
	void SetBodyCollisionEnabled(bool bEnabled);
	void SetShootColiActive(bool bAdd);
	bool IsShotColiAddded() const;
	bool ShootColiInitialized() const;
	void CreateShootColi();
	void HandleTriggeredEvents();
	void UpdateAvoidParam(float nDt);
	void UpdateInCrowdFlag();
	void PushCrowdActors();
	void InitHand(sHand* pHand);
	void InitBack(sBack* pBack);
	void InitFreeBone(SFreeBone* pFreeBone);
	ZMorphemeNetworkInstance* GetMorphemeNetwork() const;
	bool SetupRagdoll();
	void ReleaseShootColi();
	void ReleaseBodyColi();
	void InitBaseChar();
	void OnEventConsumerCollectionChanged();
	void OnMorphemeEntityInitialized();
	void OnMorphemeEntityUninitialized();
	void SetupGeomAnimatorLink();
	void SendEventsToConsumers();
	static void InitShootColiSystemData();
	static void DestroyShootColiSystemData();
	void CreateShootColiPrimitive();
	void CreateShootColiSystem();
	void SetShootColiPrimitiveActive(bool bAdd);
	void SetShootColiSystemActive(bool bAdd);
	void UpdateShootColi();
	void UpdateShootColiPrimitive(const bool bMoveInsteadOfSet);
	void UpdateShootColiSystem(const bool bMoveInsteadOfSet);
	void ReleaseShootColiPrimitive();
	void ReleaseShootColiSystem();
	void UpdateBodyCollision();
	void GetRenderableEntities(TMaxArray<TEntityRef<ZRenderableEntity>, 4>& RenderableEntities) const;
	void RagdollEaseInAfterGrab(const ZGameTime& Now);
	bool IsGrabPathClear(const float4& vGrabTargetPos) const;
	void OnAnimationRigChanged(const ZAnimationRig* pRig, const SMatrix* pTranslation);
	void RegisterForAnimationRigChangeListening();
	void UnregisterForAnimationRigChangeListening();
	static void AddBaseCharacter();
	static void RemoveBaseCharacter();
	ZMorphemeNetworkInstance* GetAttachedChildNetworkInstance(unsigned int nNodeId) const;
	bool AttachChildNetwork(unsigned int nNodeId, const ZResourcePtr& networkResourcePtr);
	bool AttachChildNetwork(unsigned int nNodeId, const TEntityRef<IChildNetworkEntity>& rChildNetworkEntity, bool bUseVariation);
	bool InternalAttachChildNetwork(unsigned int nNodeId, int nInstanceId);
	void RequestDetachChildNetwork(unsigned int nNodeId, float fTimeOut);
	void DetachChildNetwork(unsigned int nNodeId);
	int CreateChildNetworkInstance(const TEntityRef<IChildNetworkEntity>& rChildNetworkEntity, bool bUseVariation);
	void DestroyChildNetworkInstance(int nNetworkInstanceId);
	ZMorphemeNetworkInstance* GetAttachedChildNetworkInstanceFromInstanceId(int nInstanceId) const;
	void SetActiveVolumeTriggerListener(const TEntityRef<ZVolumeTriggerListenerEntity>& volumeTrigger);
	const TEntityRef<ZVolumeTriggerListenerEntity> GetActiveVolumeTriggerListener() const;
	void UpdateChildNetworkInfo(const SGameUpdateEvent& updateEvent);
	void CleanupChildNetworkInfo();
	ZHM5BaseCharacter& operator=(const ZHM5BaseCharacter& __that);
};
