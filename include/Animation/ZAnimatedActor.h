#pragma once

#include "SEventNotifyFlags.h"
#include "ZPF5Location.h"
#include "EOrderCompletionStatus.h"
#include "SReactOrderParams.h"
#include "SMoveOrderParams.h"
#include "EControlledStates.h"
#include "TSharedPointer.h"
#include "EActorEmotionState.h"
#include "EMoveSpeed.h"
#include "SActOrderParams.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "TMaxArray.h"
#include "ZPositionTarget.h"
#include "ZString.h"
#include "float4.h"

class ZNPCMorphemeNetworkController;
class ZAnimProgramBase;
class ZCCLeeLocomotion;
class ZCarryCivilianLocomotion;
class ZHumanShieldLocomotion;
class ZControlledAnimLocomotion;
class IAnimatedActorListener;
class IAsyncRayHandle;
class IHM5ItemWeapon;
class IMorphemeEntity;
class ZActor;
class ZActorAnimationState;
class ZActorInstanceEntity;
class ZMorphemeNetworkInstance;
struct SControlledOrderParams;
struct SMoveToCoverParams;
struct SOrderParamsBase;
struct SPeekFromCoverParams;
struct SShootFromCoverParams;
struct SStandOrderParams;

class ZAnimatedActor
{
public:
	ZNPCMorphemeNetworkController* m_pController;
	ZActorAnimationState* m_pActorAnimationState;
	ZAnimProgramBase* m_pCurrentProgram;
	TEntityRef<IMorphemeEntity> m_pMorphemeEntity;
	ZMorphemeNetworkInstance* m_pNetwork;
	SOrderParamsBase* m_pCurrentOrder;
	bool m_bPendingOrder;
	TMaxArray<SOrderParamsBase*, 3> m_pendingOrdersQueue;
	TEntityRef<ZActor> m_pActor;
	EOrderCompletionStatus m_eLastOrderCompletionStatus;
	bool m_bControlled : 1;
	bool m_bShootIntoGround : 1;
	bool m_bShootIntoGroundInSequences : 1;
	bool m_bShootRequested : 1;
	bool m_bBlindfireRequested : 1;
	bool m_bIgnoreLOF : 1;
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
	ZPF5Location m_closestLocationOnNavmesh;
	bool m_bConstrainedToNavMesh : 1;
	bool m_bIsOnNavMesh : 1;
	SMatrix m_mFrom;
	SMatrix m_mTo;
	SMatrix m_mNext;

	virtual ~ZAnimatedActor() = default;

	ZAnimatedActor() = default;
	ZAnimatedActor(ZActor* pActor);
	void UpdateAimTarget(const ZPositionTarget& rTarget, bool bAlwaysSet);
	void ClearAimTarget();
	bool HasAimTarget();
	void Stand(const SStandOrderParams& params);
	void React(const SReactOrderParams& params);
	void Act(const SActOrderParams& params);
	void MoveToAct(const SMoveOrderParams& moveParams, const SActOrderParams& actParams);
	void MoveToCover(const SMoveToCoverParams& moveToCoverParams);
	void PeekFromCover(const SPeekFromCoverParams& peekFromCoverParams);
	void ShootFromCover(const SShootFromCoverParams& shootFromCoverParams);
	void StopShootFromCover(bool bForceFastStop);
	void Move(const SMoveOrderParams& params);
	void Die(bool bWaitForSequenceToEnd);
	void NotifyStumble(bool bFront, bool bRight);
	void NotifyImpact(TEntityRef<IHM5ItemWeapon> pWeapon, const float4& wsPosition, const float4& wsImpactVector, unsigned int nMeshBoneIndex, unsigned int nGlobalBoneID);
	void Reload();
	void Recoil();
	bool HasController() const;
	TSharedPointer<ZCarryCivilianLocomotion> CarryCivilian(const SControlledOrderParams& params);
	TSharedPointer<ZHumanShieldLocomotion> HumanShield(const SControlledOrderParams& params);
	TSharedPointer<ZControlledAnimLocomotion> ControlledAnim(const SControlledOrderParams& params);
	TSharedPointer<ZCCLeeLocomotion> CloseCombat(const SControlledOrderParams& params);
	void StartShooting(const ZPositionTarget& rTarget, bool bIgnoreLOF, bool bBlindfire);
	void StopShooting();
	void SetControlled(EControlledStates controlledState);
	void ClearControlled();
	void ClearListeners();
	void ControlTransform(const SMatrix& wsTargetTransform);
	void SetCurrentPosition(const float4& wsPosition);
	void SetCurrentTransform(const SMatrix& wsTransform);
	void SetNextTransform(const SMatrix& wsTransform);
	const TEntityRef<ZActor>& GetActor();
	unsigned int GetAvoidanceUID();
	void EnableImpactAndDeathAnimations(bool bEnable);
	void TeleportTo(const SMatrix& wsTargetTransform);
	void ResetState();
	bool OrderHasCompleted() const;
	bool OrderIsBeingExecuted() const;
	bool OrderIsPending() const;
	bool OrderHasSucceeded() const;
	EOrderCompletionStatus GetOrderCompletionStatus() const;
	ZString GetOrderCompletionStatusString() const;
	ZPF5Location GetClosestLocationOnNavMesh() const;
	bool IsOnNavMesh() const;
	bool IsOnStairs() const;
	bool IsCloseToStairs(float distance) const;
	void SnapBackToNavMesh();
	SMatrix GetCurrentTransform() const;
	SMatrix GetLastTransform() const;
	float4 GetCurrentPosition() const;
	float4 GetCurrentFacingDirection() const;
	EActorEmotionState GetEmotionState() const;
	SMatrix GetNeckToWorldTransform() const;
	bool IsLeaningAtWindow() const;
	bool IsControlled() const;
	bool IsWithinAimingCone(const float4& wsAimPosition) const;
	bool IsAimTargetWithinLimit(const ZPositionTarget& aimTarget, float fAngleThreshold) const;
	bool IsAimTargetWithinLimit(float fAngleThreshold) const;
	bool IsReloading() const;
	bool IsAiming() const;
	bool IsStanding() const;
	bool IsMoving() const;
	bool IsActing() const;
	bool IsBlendingOutOfAct() const;
	bool IsFullbodyActing() const;
	bool IsInActLoop() const;
	unsigned int GetActLoopCount() const;
	bool IsCrouching() const;
	bool CanShoot(bool bIgnoreAimCheck) const;
	bool InArmedState() const;
	EMoveSpeed GetTargetMoveSpeed() const;
	void SetAnimatedActorListener(IAnimatedActorListener* pListener);
	bool HasAnimatedActorListener() const;
	bool CanPlaySequence() const;
	bool IsNPCHitmanCollisionEnabled() const;
	bool CanQueryDistance() const;
	float RemainingPathDistanceToTarget() const;
	float CurrentPathLength() const;
	bool HasPath() const;
	float GetNormalizedDistanceOnPath(const float4& wsPoint) const;
	float GetNormalizedDistanceTravelledOnPath() const;
	void UpdateOffHandIK();
	bool IsConstrainedToNavMesh() const;
	void SetConstrainedToNavMesh(bool bConstrained);
	void SetShootIntoGround(bool bShootIntoGround);
	bool GetShootIntoGround() const;
	void SetShootIntoGroundInSequence(bool bShootIntoGround);
	bool GetShootIntoGroundInSequence() const;
	void SetSequenceWeight(float weight, unsigned int track);
	void SetSequenceFeatherWeight(float weight, unsigned int track);
	float GetSequenceWeight(unsigned int track) const;
	float GetSequenceFeatherWeight(unsigned int track) const;
	void BlendOutSequenceWeights();
	void RequestTerminationOfCurrentOrder();
	bool SetDynamicActControlParameter(const ZString& paramName, float value);
	void OnActivation();
	void OnDisable();
	void Update(float timeDelta);
	void LowFrequencyUpdate();
	bool HasFaceFxActorInstance() const;
	void PointEyesTo(const float4& wsEyeTarget);
	void PointEyesToDefaultPosition();
	ZActorAnimationState* GetActorAnimationState() const;
	ZMorphemeNetworkInstance* GetMorphemeNetworkInstance() const;
	void SetControlledWeight(float weight);
	float GetControlledWeight() const;
	static void CacheHitmanNeckAndHeadBones();
	static void ClearHitmanNeckAndHeadBonesCache();
	static const SMatrix& GetHitmanNeckBone();
	static const SMatrix& GetHitmanHeadBone();
	static void SetNavMeshChangedCostMask(unsigned short navMeshChangedCostMask);
	static bool NavMeshCostHasJustChanged();
	static bool NavMeshRegionsHaveChanged(unsigned short regions);
	SOrderParamsBase* QueueOrder(SOrderParamsBase* pOrder);
	SOrderParamsBase* DequeueOrder();
	void ClearPendingQueue();
	void StopCurrentOrder();
	void SwitchToNextOrder();
	void OnNewOrder();
	void TrySwitchingOrder();
	void FailOrder();
	void NotifyStand();
	void NotifyMove();
	void NotifyMoveStart();
	void NotifyMoveStopping();
	void NotifyActStart();
	void NotifyActStopping();
	void NotifyActEnteredLoop();
	void NotifyActInFullbody();
	void NotifyReactionStart();
	void NotifyReactionStopping();
	void UpdateShooting();
	void SendEyeValuesToFaceFXIfNeeded(float yaw, float pitch);
	void Init(ZActor* pActor);
	void Release();
	bool UpdateAnimationNetwork(bool bDrivenBySequence);
	void UpdateAnimProgram(float timeDelta);
	void UpdateNavMeshMappingAndConstraining(bool bDrivenBySequence);
	void UpdateZCorrection(bool noGroundTranslation);
	void ApplyZCorrection(float timeDelta);
	void DiscardRaycastQuery();
	void ForceZCorrection();
	void OnNavMeshLocationInvalidated();
};
