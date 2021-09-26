#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"
#include "SInputRestriction.h"

class ZHM5MovementDragBody : public ZHM5BaseMovement
{
public:
	enum EDragBodyState
	{
		eStandIdleToDragIdle_State = 0,
		eDragBodyMain_State = 1,
		eDragIdle_State = 2,
		eDragIdleToStandIdle_State = 3,
		eDragMove_State = 4,
		eNumDragStates = 5
	};

	bool m_bWantsControl;
	TEntityRef<ZActor> m_pActor;
	float m_fToStandIdleAnimTime;
	float m_fToStandIdleAnimDuration;
	float m_fGrabVictimTime;
	float m_fGrabVictimTimeLimit;
	unsigned int m_nGrabBoneID;
	bool m_bGrabRagDollDirect;
	bool m_bPlayEnterAnimation;
	unsigned int m_aDragStateIDs[5];
	unsigned int m_nTurnAnlgeControlParamID;
	unsigned int m_nMoveRequestID;
	unsigned int m_nStopRequestID;
	SMatrix m_StartDragBodyMatPos;
	float m_fAlignToTargetFraction;
	SInputRestriction m_InputRestriction;
	float1 m_vDragDist;
	float4 m_vPrevHitmanPos;

	~ZHM5MovementDragBody() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void ActivateMovement() override;
	void DeactivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	bool CanActivate() const override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void GetInputRestriction(SInputRestriction& InputRestriction) const override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void PrepareForCutSequence() override;

	ZHM5MovementDragBody() = default;
	ZHM5MovementDragBody(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	const TEntityRef<ZActor>& GetDragVictim();
	void ReleaseVictim();
	void UpdateTurnAngle(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	bool UpdateTurnToTarget(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateStandIdleToDragIdleState(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateDragIdleToStandIdleState(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateDragIdleState(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateDragMoveState(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void CalcTurnTargetMatPos();
	bool GrabRagDoll();
	void OnActorDeleted(const ZEntityRef& pActor);
	bool RefreshCanGrabRagdoll(const TEntityRef<ZActor>& pActor, bool bUseLongRange, unsigned int& nGrabBone) const;
	SVector2 UpdateInput();
	void SetActorRef(const TEntityRef<ZActor> rActor);
};
