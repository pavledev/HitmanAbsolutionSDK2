#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHM5LocomotionNetwork.h"
#include "ZHM5LocomotionInput.h"
#include "SInputRestriction.h"

class ZHM5MovementLocomotion : public ZHM5BaseMovement
{
public:
	enum ELocoState
	{
		eLocoState_InActive = 0,
		eLocoState_TransitInPreCheck = 1,
		eLocoState_TransitIn = 2,
		eLocoState_Active = 3
	};

	ELocoState m_eLocoState;
	ZHM5LocomotionNetwork m_LocomotionNetwork;
	ZHM5LocomotionInput m_LocomotionInput;
	unsigned int m_nRequestEnterLocomotion;
	unsigned int m_nControlParamSneakSpeedFactorID;
	unsigned int m_nControlParamSneakPelvisAngleID;
	unsigned int m_nControlParamSneakPelvisOffssetID;
	unsigned int m_nControlParamWalkTurnSpeedID;
	unsigned int n_nControlParamRunTurnSpeedID;
	unsigned int m_nLocomotionState;
	unsigned int m_nStandMask;
	unsigned int m_nStrafeMask;
	ENetworkState m_eNetworkStartState;
	bool m_bStartRight;
	bool m_bStartRunning;
	bool m_bLerpPos;
	bool m_bLerpCameraGround;
	float m_fTransitionInFraction;
	int m_nHMMovementIndex;
	float4 m_vStartPos;
	float4 m_vLerpPos;
	SMatrix m_mCameraGroundStart;
	ZMapPoly m_Mapper;
	float m_fSwingAtWillWeight;
	float m_fSwingAtWillHoldTime;
	bool m_bSwingAtWillActive;
	float m_fAimTime;
	ZMapPoly m_MapPolyAim;
	SInputRestriction m_InputRestriction;
	SMatrix m_mStandRotBase;
	SMatrix m_mSneakdRotBase;
	bool m_bLookAtPointInitialized;
	float4 m_vLookAtPoint;
	float4 m_vLookAtDir;
	float m_fLookAtHoldTime;
	float m_fLookAtTargetWeight;
	float m_fMaxYaw;
	float m_fMaxPitch;
	float m_afStandLookAtHorWeights[6];
	float m_afStandLookAtVerWeights[6];
	float m_afSneakLookAtHorWeights[6];
	float m_afSneakLookAtVerWeights[6];
	float m_afLookAtHorWeights[6];
	float m_afLookAtVerWeights[6];
	bool m_bOpenDoorActive;
	float m_fOpenDoorWeight;

	~ZHM5MovementLocomotion() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo) override;
	void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo) override;
	void UpdateOutsideControl() override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void GetInputRestriction(SInputRestriction& InputRestriction) const override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;
	void ReinitializeMorphemeData(IMorphemeEntity* pMorphemeEntity) override;
	void UpdateAim(SHM5AimInfo& sAimInfo) const override;
	void UpdateLookAt(SHM5LookAtInfo& sLookAtInfo) const override;
	void PrepareForCutSequence() override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;

	ZHM5MovementLocomotion() = default;
	ZHM5MovementLocomotion(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void SetStartState(ENetworkState eNetworkStartState, bool bStartRight, bool bStartRunning);
	void SetLerpPos(const float4& vLerpPos);
	const ZHM5LocomotionNetwork& GetLocomotionNetwork() const;
	const ZHM5LocomotionInput& GetLocomotionInput() const;
	unsigned int GetLocomotionStatus() const;
	void GetLocomotionFractions(float& fStandFraction, float& fWalkFraction, float& fRunFraction) const;
	void ResetInputMoveAngle();
	void ResetInputRestriction();
	float GetRunFraction() const;
	void PlayOpenDoorAnim();
	void InitNetwork();
	void UpdateTransitIn();
	void UpdateActive();
	void UpdateLocomotionStatus();
	void SetStartConditions(ENetworkState eNetworkStartState, bool bStartRight, bool bStartRunning);
	void UpdateLookAtPoint();
	void CalculateBaseRotationMatrices();
	SMatrix CalculateLookAtConstrainMatrix();
	void UpdateOpenDoorAnim();
};
