#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"

class ZHM5MovementCarryCivilian : public ZHM5BaseMovement
{
public:
	enum EState
	{
		eIdle = 0,
		eMove = 1
	};

	enum EStrafeState
	{
		eStateForward = 0,
		eStateLeft = 1,
		eStateRight = 2,
		eStateBackward = 3,
		eStateLast = 4
	};

	TEntityRef<ZActor> m_pCarryCivilianVictim;
	TEntityRef<ZCrowdActor> m_pCrowdActorTarget;
	unsigned int m_nStrafeStateIDs[4];
	unsigned int m_nCarryCivilianStateMachineID;
	EState m_eCarryCivilianState;
	float m_fRawInputX;
	float m_fRawInputY;
	float m_fInputX;
	float m_fInputY;
	float m_fInputVelocity;
	SInputRestriction m_InputRestriction;

	~ZHM5MovementCarryCivilian() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void ActivateMovement() override;
	void DeactivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo) override;
	void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;

	ZHM5MovementCarryCivilian() = default;
	ZHM5MovementCarryCivilian(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	TEntityRef<ZActor> GetVictim();
	void GetVictimPos(SMatrix& mPos);
	void SetForcedCivilian(TEntityRef<ZActor> pActor);
	void ReleaseCivilian();
	EStrafeState GetStrafeState(float fInputX, float fInputY) const;
	void UpdateCarryCivilianIdle();
	void UpdateCarryCivilianMove();
	void RegisterDelegate();
	void UnregisterDelegate();
	void OnActorDeleted(const ZEntityRef& pActor);
	void UpdateInput();
};
