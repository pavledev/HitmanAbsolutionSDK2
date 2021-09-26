#pragma once

#include "ZHM5BaseLedgeMovement.h"
#include "ZHitmanMorphemePostProcessorLedgeHangCallback.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "SMatrix43.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "TSharedPointer.h"
#include "ZGameTime.h"
#include "ZString.h"
#include "float4.h"

class ZHM5GuideLedge;
class IMorphemeEntity;
class ZActor;
class ZControlledAnimLocomotion;
class ZHM5BaseGuide;
class ZHM5BaseMovement;
class ZHitman5;
struct SCameraUpdateEvent;
struct SHM5GameCamParams;
struct sLedgeHangInfos;

class ZHM5MovementLedgeHang : public ZHM5BaseLedgeMovement, public ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
	SMatrix43 m_mvDestJumpUp320cm;
	bool m_bSecDestSet;
	float m_fJumpUp320FirstContact;
	float4 m_vPelvisPushDir;
	bool m_bTurningCorner;
	float m_fTurnCornerAngle;
	TEntityRef<ZActor> m_pVictim;
	TSharedPointer<ZControlledAnimLocomotion> m_pVictimLoco;
	float m_fAnimPrct;
	float m_fAnimDelta;
	ZString m_sVictimAnimSM;
	ZString m_sVictimAnim;
	float m_fAllignTime;
	float m_fFallSoundTime;
	bool m_bFallSoundTriggered;
	SMatrix m_mvVictimStartMatPos;
	SVector3 m_vNearEnemyPO;
	SMatrix m_mEnd;
	SMatrix m_mStart;
	HM5Utils::SAnimBlend m_sAnimBlend;
	ZMapPoly m_MapPoly;
	float m_fHandIKBlend;
	float m_fCameraEndBlendFraction;
	ZGameTime m_timeInLedgeHangPullUpDown;
	ZGameTime m_timeInLedgeHangPullLeftRight;
	bool m_bActivateButtonPrompt;
	bool m_bRequestControl;
	bool m_bMountFromTop;
	float m_fCameraPullVictimBlendInTime;
	float m_fEndCameraFollowFraction;
	float m_fActivateRagdollFraction;
	bool m_bCameraInitialized;
	float m_fDesiredStickLength;
	float m_fCurCamStickLength;
	float m_fDesiredHeight;
	float m_fCurCamHeight;
	float4 m_vDesiredGround;
	float4 m_vCurrentFocusPoint;
	SMatrix m_CameraGround;

	~ZHM5MovementLedgeHang() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void DeactivateMovement() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;
	void SetCurrentGuide(ZHM5BaseGuide* pGuide) override;

	void LedgeHangCallBack(sLedgeHangInfos* pLHInfos) override;

	ZHM5MovementLedgeHang() = default;
	ZHM5MovementLedgeHang(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	bool CanHMMountFromTop() const;
	bool CanHMMountFromBelow() const;
	void UpdateMovementMain();
	void UpdateFacing();
	void UpdateFeedBackPose();
	bool CanPullUpOnLedge();
	ZHM5GuideLedge* CanDropDownToLedgeBelow();
	ZHM5BaseGuide* CanJumpLeft();
	ZHM5BaseGuide* CanJumpRight();
	bool IsJumpPossible();
	const TEntityRef<ZActor>& GetVictim() const;
	bool ActivateButtonPrompt() const;
	void ResetButtonPrompt();
	void UpdateGroundMovementMountGuide(SMatrix& mvFrom, SMatrix& mvTo);
	void UpdateGroundMovementDismountGuide(SMatrix& mvFrom, SMatrix& mvTo);
	void AllignMatPosToTurnCorners(SMatrix& mvTo, ZHM5BaseGuide* pNeighbourGuide);
	SMatrix43 CalcGetWalkLedgeDestination(ZHM5BaseGuide* pGuide, bool bUseColiAdjustment);
	SMatrix43 CalcGetHangLedgeDestination(ZHM5BaseGuide* pGuide, bool bUseColiAdjustment);
	void StartJumpLedge(ZHM5BaseGuide* pNextGuide, unsigned int nAnimNode, bool bRight);
	void UpdateMovementPullVictim();
	void UpdateGroundMovementPullVictim(SMatrix& mvFrom, SMatrix& mvTo);
	void StartPullVictimMove();
	void SelectPullVictimAnim();
	void UpdatePullVictimAnimPrct();
	void UpdateVictimground(const SMatrix& mvHMMatPos);
	float CalcGetRightHandRetargetWeight();
	void SetupDismountAnimation(bool bUpToStand);
	void SetupMountAnimation(bool bMountFromTop);
	void SetupEnterLedgeWalkAnimation();
	float GetDismountTurnAngle() const;
};
