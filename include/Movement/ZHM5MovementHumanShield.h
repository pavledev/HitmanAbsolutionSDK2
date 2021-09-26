#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"
#include "HM5Utils.h"
#include "ZInventorySlot.h"
#include "SInputRestriction.h"

class ZHM5MovementHumanShield : public ZHM5BaseMovement
{
public:
	enum EState
	{
		eEntering = 0,
		eIdle = 1,
		eMove = 2,
		eExit = 3,
		eDeactivated = 4
	};

	enum EStrafeState
	{
		eStateForward = 0,
		eStateLeft = 1,
		eStateRight = 2,
		eStateBackward = 3,
		eStateLast = 4
	};

	TEntityRef<ZActor> m_rArrestActor;
	TEntityRef<ZActor> m_pHumanShieldVictim;
	TEntityRef<ZCrowdActor> m_pCrowdActorTarget;
	unsigned int m_nStrafeStateIDs[4];
	unsigned int m_nHumanShieldStateMachineID;
	unsigned int m_nHumanShieldEnterSM;
	unsigned int m_nEnterHSShieldGrabAnimNodeID;
	unsigned int m_nEnterHSDisarmRifleAnimNodeID;
	unsigned int m_nEnterHSDisarmGunAnimNodeID;
	unsigned int m_nExitHSAnimNodeID;
	unsigned int m_nExitKillHSAnimNodeID;
	unsigned int m_nFreeAttacherID;
	EState m_eHumanShieldState;
	unsigned int m_nEnterAnimNodeID;
	unsigned int m_nExitAnimNodeID;
	bool m_bFromSurrender;
	SMatrix m_mvVictimStart;
	SMatrix m_aBlendMats[3];
	HM5Utils::SAnimBlend m_aAnimBlends[3];
	bool m_bAlignYawAngle;
	float m_fAlignYawAngle;
	bool m_bActivateButtonPrompt : 1;
	bool m_bCloseCombatImpactEventSent : 1;
	bool m_bCloseCombatKillEventSent : 1;
	ZInventorySlot* m_pHumanShieldWeaponCandidateSlot;
	float m_afAimHorizontalWeights[8];
	float m_afAimVerticalWeights[8];
	float m_fGrabHumanShieldFraction;
	float m_fAimBlendInFraction;
	float m_fKillHumanShieldFraction;
	float m_fDropWeaponFraction;
	float m_fTakeWeaponFraction;
	float m_fRagdollFraction;
	float m_fAimFraction;
	float m_fRawInputX;
	float m_fRawInputY;
	float m_fInputX;
	float m_fInputY;
	float m_fInputVelocity;
	SInputRestriction m_InputRestriction;
	bool m_bCCScaleActor;
	float m_fCCScaleUpWindowStartTime;
	float m_fCCScaleUpWindowEndTime;
	float m_fCCScaleDownWindowStartTime;
	float m_fCCScaleDownWindowEndTime;
	float m_fCCScaleUpBlend;
	float m_fCCScaleDownBlend;

	~ZHM5MovementHumanShield() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void ActivateMovement() override;
	void DeactivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo) override;
	void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo) override;
	void UpdateOutsideControl() override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void GetInputRestriction(SInputRestriction& InputRestriction) const override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void UpdateAim(SHM5AimInfo& sAimInfo) const override;
	void PrepareForCutSequence() override;

	ZHM5MovementHumanShield() = default;
	ZHM5MovementHumanShield(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	TEntityRef<ZActor> GetVictim() const;
	bool AimAllowed() const;
	void GetVictimPos(SMatrix& mPos) const;
	bool ActivateButtonPrompt() const;
	void ResetButtonPrompt();
	bool ActivateArrest(const TEntityRef<ZActor>& rActor);
	bool IsEntering() const;
	void TakeDisarmWeapon(const TEntityRef<ZActor>& rActor, bool bOneHandedWeapon);
	EStrafeState GetStrafeState(float fInputX, float fInputY) const;
	void UpdateHumanShieldIdle();
	void UpdateHumanShieldMove();
	void UpdateHumanShieldExit();
	void OnActorDeleted(const ZEntityRef& pActor);
	void UpdateInput();
	SActorHSState::EHSEnterAnimation GetEnterAnimation(const bool bFromSurrender, const TEntityRef<ZActor>& rActor) const;
	void SetupAnimBlend(const unsigned int nEnterAnimNodeID);
	void RegisterDelegate();
	void UnregisterDelegate();
	void KillVictim();
	void UpdateActorScaling();
};
