#pragma once

#include "ZHM5BaseMovement.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "float4.h"

class IMorphemeEntity;
class ZHM5GuideLadder;
class ZHitman5;
struct SCameraUpdateEvent;
template <class T> class TEntityRef;

class ZHM5MovementLadder : public ZHM5BaseMovement
{
public:
	enum eLadderMoveType
	{
		eMoveIdle = 0,
		eMoveOnLadder = 1,
		eMoveMountBottom = 2,
		eMoveMountTop = 3,
		eMoveDismountBottom = 4,
		eMoveDismountTop = 5,
		eMoveSlideDown = 6
	};

	ZHM5GuideLadder* m_pCurrentLadder;
	unsigned int m_nActiveAnimNodeID;
	ZHM5BaseMovement::eMoveDir m_eMoveDir;
	eLadderMoveType m_eMoveType;
	float m_fAnimFraction;
	float m_fEarlyExitFraction;
	float m_fVerticalSpeed;
	float m_fUpFastSpeed;
	float m_fUpSlowSpeed;
	float m_fDownFastSpeed;
	float m_fDownSlowSpeed;
	float m_fSlideDownSpeed;
	bool m_bStopping;
	int m_nNumOfRungs;
	float m_fNumCycles;
	float m_fCurrentCycleNum;
	float m_fTargetAnimPrct;
	float m_fTargetCycleNum;
	bool m_bStopSet;
	SMatrix m_mStart;
	SMatrix m_mEnd;
	HM5Utils::SAnimBlend m_sAnimBlend;
	bool m_bOddLadder;
	bool m_bDismountDown;
	bool m_bDismountTop;
	float4 m_vForcedPos;
	bool m_bForceResetCamera;
	bool m_bRequestControl;
	ZMapPoly m_MapPoly;

	~ZHM5MovementLadder() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;
	virtual ZHM5BaseMovement::eMoveDir GetMoveDir() const;
	virtual bool IsDismountingLadder() const;

	ZHM5MovementLadder() = default;
	ZHM5MovementLadder(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void SetForceToLadder(ZHM5GuideLadder* pLadderGuide, const float4& vPos, bool bResetCamera);
	SMatrix GetDestMatPos();
	void SetupMountLadder();
	void SetupMountLadderForced();
	bool StandIdleOnLadder();
	bool HasChanceToStop();
	void SetupDismountLadderBottom(const SMatrix& mvFrom);
	void SetupDismountLadderTop(const SMatrix& mvFrom);
};
