#pragma once

#include "ZHM5BaseMovement.h"
#include "HM5Utils.h"

class ZActor;

class ZHM5MovementSurrender : public ZHM5BaseMovement
{
public:
	enum ESurrenderState
	{
		eStateRaiseArms = 0,
		eStateTurnToActor = 1,
		eStateIdleWaitingForActor = 2,
		eStateIdleNormal = 3
	};

	SMatrix m_mvStartMatPos;
	SMatrix m_mvDestMatPos;
	SMatrix m_mvCameraGroundStart;
	bool m_bLerpCameraGround;
	HM5Utils::SAnimBlend m_sAnimBlend;
	unsigned int m_nRaiseArmsAnimID;
	unsigned int m_nIdleStateID;
	unsigned int m_nTurnStateID;
	unsigned int m_anAnimIDs[5];
	float m_fStartFraction;
	float m_fEndFraction;
	float m_fAnimFraction;
	float m_fAnimDuration;
	unsigned int m_nControlParam;
	bool m_bWantControl;
	bool m_bLookAtPoseChanged;
	bool m_bLookAtPosInitialized;
	float4 m_vLookAtPoint;
	float4 m_vLookAtDir;
	ESurrenderState m_eState;

	~ZHM5MovementSurrender() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void UpdateLookAt(SHM5LookAtInfo& sLookAtInfo) const override;

	ZHM5MovementSurrender() = default;
	ZHM5MovementSurrender(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	bool IsSurrenderPossible() const;
	bool CanBeArrested(const ZHM5BaseMovement* pCurrentMovement) const;
	float4 GetArrestPos() const;
	unsigned int SelectTurnAnim(const float4& vTurnPos) const;
	void SetupAnimBlend(ZHM5BaseMovement* pPrevMovement, unsigned int nAnimID);
	void UpdateLookAtPoint(const TEntityRef<ZActor>& rActor);
};
