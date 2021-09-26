#pragma once

#include "ZHM5BaseMovement.h"
#include "ZMovementAnimNode.h"
#include "ZHM5Closet.h"
#include "ZMovementAnimTransition.h"
#include "HM5Utils.h"
#include "SCameraUpdateEvent.h"

class ZHM5MovementHideInCloset : public ZHM5BaseMovement
{
public:
	enum EState
	{
		eStateNone = 0,
		eStateStart = 1,
		eStateEntering = 2,
		eStateInside = 3,
		eStateExitingPending = 4,
		eStateExitingNormal = 5
	};

	EState m_eState;
	ZMovementAnimNode* m_pCurrentAnim;
	TEntityRef<ZHM5Closet> m_rCloset;
	float m_fCameraPeekPrc;
	float m_fEarlyExitFraction;
	ZHM5Closet::EClosetType m_eCurrentClosetType;
	unsigned int m_nClosetRootNodeID[3];
	ZMovementAnimNode m_AnimEnter[3];
	ZMovementAnimNode m_AnimInside[3];
	ZMovementAnimNode m_AnimExit[3];
	ZMovementAnimTransition m_TransEnter[3];
	ZMovementAnimTransition m_TransExit[3];
	bool m_bExitAlignmentStarted : 1;
	bool m_bForceResetCamera : 1;
	SMatrix m_mvStartPos;
	SMatrix m_mvDestPos;
	SMatrix m_mvHitmanInside;
	HM5Utils::SAnimBlend m_sAnimBlend;
	SCameraUpdateEvent m_StartCameraEvent;
	ZGameTime m_TimeSpentInCloset;

	~ZHM5MovementHideInCloset() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;

	ZHM5MovementHideInCloset() = default;
	ZHM5MovementHideInCloset(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	TEntityRef<ZHM5Closet> GetCloset() const;
	void OnEnterCloset();
	void OnInsideCloset();
	void OnExitCloset();
	bool IsEntering() const;
	bool IsExiting() const;
	bool IsPeekHoleAvailable() const;
	void ActivateEnter(TEntityRef<ZHM5Closet> rCloset);
	bool ActivateExit();
	void SetForceCloset(TEntityRef<ZHM5Closet> rCloset, bool bForceResetCamera);
	void SetCameraStartMat() const;
};
