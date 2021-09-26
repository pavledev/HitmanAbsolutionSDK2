#pragma once

#include "ZHM5BaseLedgeMovement.h"
#include "ZHitmanMorphemePostProcessorLedgeHangCallback.h"
#include "eMorphemeRequests.h"
#include "EWindowStatus.h"
#include "ZHM5GuideWindow.h"
#include "HM5Utils.h"
#include "ZHM5ReloadController.h"

class ZHM5MovementLedgeWalk : public ZHM5BaseLedgeMovement, public ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
	unsigned int m_nActiveSM;
	bool m_bDestSet;
	eMorphemeRequests m_nMountReq;
	bool m_bTurningCorner;
	EWindowStatus m_WindowStatus;
	float m_fWindow;
	ZHM5GuideWindow* m_pCurrentWindow;
	bool m_bPullVictimActivated;
	float m_fLookLeftRight;
	float m_fLookLeftRightTarget;
	bool m_bLocomotionStartRight;
	ZGameTime m_timeInLedgeWalkPullUpDown;
	ZGameTime m_timeInLedgeWalkPullLeftRight;
	float m_fOldAimHorLimitAngle;
	float m_fOldAimVerLimitAngle;
	bool m_bSneakPastWindowParamsUpdated;
	bool m_bSneakPastWindowPrompt;
	SMatrix m_aBlendMats[3];
	HM5Utils::SAnimBlend m_aAnimBlends[3];
	ZHM5ReloadController* m_pReloadController;
	float m_fAimWeight;
	float m_afHandAimTime[2];
	SLedgeAimInfo m_AimLedgeInfo;
	ZPolarAnimBlend m_PolarAnimBlendRight;
	ZPolarAnimBlend m_PolarAnimBlendLeft;
	float m_afWindowAimTime[2];
	ZMapPoly m_MapPoly;
	bool m_bWindowAiming : 1;
	bool m_bAllowAiming : 1;
	bool m_bAimWithRightArm : 1;
	bool m_bWantsControl : 1;

	~ZHM5MovementLedgeWalk() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;
	void ReinitializeMorphemeData(IMorphemeEntity* pMorphemeEntity) override;
	void UpdateAim(SHM5AimInfo& sAimInfo) const override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;
	void SetCurrentGuide(ZHM5BaseGuide* pGuide) override;
	bool EnterLedgeOTSMode() override;
	void ExitLedgeOTSMode() override;
	ZHM5BaseGuide* GetClosestNeightbourGuide(float fLookDistance, unsigned int nFilter, unsigned char nDir) override;

	void LedgeHangCallBack(sLedgeHangInfos* pLHInfos) override;

	ZHM5MovementLedgeWalk() = default;
	ZHM5MovementLedgeWalk(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void UpdateLedgeMovementMain();
	void UpdateFacing();
	void UpdateFeedBackPose();
	bool CanClimbDownOnLedgeToHang();
	ZHM5BaseGuide* CanJumpUpLedgeAbove();
	ZHM5BaseGuide* CanJumpLeft();
	ZHM5BaseGuide* CanJumpRight();
	bool IsJumpPossible();
	bool IsClimbWindowPossible() const;
	ZHM5GuideWindow* GetCurrentWindow() const;
	EWindowStatus GetWindowStatus();
	void ForceExitLedgeOTSMode();
	void SetPullVictimActivated(bool bActivated);
	bool GetSneakPastWindowPrompt() const;
	bool ShowCrossHair() const;
	bool AllowAiming() const;
	bool AimWithRightArm() const;
	bool WindowAiming() const;
	float GetAimWeight() const;
	void AllignMatPosToTurnCorners(SMatrix& mvTo, ZHM5BaseGuide* pNeighbourGuide, float fWeight);
	SMatrix43 CalcGetHangLedgeDestionation(ZHM5BaseGuide* pGuide, bool bUseColiAdjustment);
	void UpdateGroundMovementMountGuide(SMatrix& mvFrom, SMatrix& mvTo);
	void UpdateGroundMovementDismountGuide(SMatrix& mvFrom, SMatrix& mvTo);
	void UpdateGroundMovementClimbWindow(SMatrix& mvFrom, SMatrix& mvTo);
	bool HitmanIsOccupied() const;
	void StartJumpLedge(ZHM5BaseGuide* pNextGuide, unsigned int nAnimNode, bool bRight);
	SMatrix SetupSafeDismount(bool bRight);
	bool ReachedWindowZoneAndSetWindow(bool bFromRight);
	SMatrix43 CalcClimbWindowDestination();
	SMatrix43 CalcSecondaryWindowDestination();
	void SetupSneakPastWindowAnimDest();
	void SetupMountAnimation();
	void SetupEnterWindowAnimation();
	bool AllowShooting();
	void InitLedgeAim();
	bool UpdateLedgeAim(bool bWantAim, const SMatrix& mCam, const SMatrix& mHitman, float fDeltaTime);
	bool UpdateWindowAim(bool bWantAim, const SMatrix& mCam, const SMatrix& mHitman, float fDeltaTime);
};
