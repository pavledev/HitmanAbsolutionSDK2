#pragma once

#include "ZHM5BaseMovement.h"
#include "sCoverCorner.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"

class ZHM5CoverPlane;
class IHM5Door;
struct SRecoilAnimInfo;

class ZHM5MovementCover : public ZHM5BaseMovement
{
public:
	enum eCoverMoveType
	{
		eMoveCoverDefault = 0,
		eMoveSwitchCoverFacing = 1,
		eMoveShootFromCover = 2,
		eMoveEnterToShootPos = 3,
		eMoveExitFromShootPos = 4,
		eMoveEnterCover = 5,
		eMoveExitCover = 6,
		eMoveBlindFire = 7,
		eMoveExitBlindFire = 8,
		eMoveEnterCoverForced = 9,
		eMoveEnterCoverNoTrans = 10,
		eMoveCoverToCover = 11,
		eMoveExitCoverScale = 12
	};

	enum eCoverStance
	{
		eLowStance = 0,
		eHighStance = 1
	};

	enum eCoverOTSMode
	{
		eCoverOTSModeOff = 0,
		eCoverOTSModeLookAt = 1,
		eCoverOTSModeAim = 2
	};

	struct sExitCoverInfo
	{
		ZHM5CoverPlane* m_pCoverPlane;
		SMatrix m_mvPosOnCoverPlane;
		eCoverStance m_eStance;
		bool m_bAtCorner;
		bool m_bFacingRight;

		sExitCoverInfo() = default;
		void Reset();
	};

	struct sSideCToCData
	{
		ZHM5CoverPlane* m_pPlane;
		sCoverCorner m_Corner;

		sSideCToCData() = default;
		void Reset();
	};

	sExitCoverInfo m_sExitInfo;
	ZHM5CoverPlane* m_pRequestedCoverPlane;
	ZHM5CoverPlane* m_pWantedCoverPlane;
	ZHM5CoverPlane* m_pCurrentCoverPlane;
	ZHM5CoverPlane* m_pLastCoverPlaneRounded;
	eCoverMoveType m_MoveType;
	eCoverMoveType m_FirstMoveType;
	eCoverMoveType m_MoveType_Debug;
	sCoverCorner m_CurrentCorner;
	sCoverCorner m_ShiftTargetCorner;
	sCoverCorner m_ShiftStartCorner;
	unsigned int m_nActiveAnimNodeID;
	HM5Utils::SAnimBlend m_sAnimBlend;
	ZMapPoly m_Mapper;
	ZMapPoly m_MoveSpeedMapBlend;
	float m_fAnimDuration;
	float m_fAnimFraction;
	unsigned int m_nCoverAimWildCardTransitID;
	float m_fAimSneak;
	float m_fAimWeight;
	bool m_bFacingRight;
	float m_fStanceBlendParam;
	bool m_bInitialMoveAngleSet;
	float m_fHandLayerFraction;
	ZHM5BaseMovement::eMoveDir m_MoveDir;
	ZHM5BaseMovement::eMoveDir m_eHitmanRelativeInputDir;
	eCoverStance m_eStance;
	float m_fRawInputX;
	float m_fRawInputY;
	float m_fInputVelocity;
	float4 m_vInput;
	float4 m_vMove;
	float4 m_vCameraWorldInput;
	float4 m_vHitmanRelativeInput;
	float m_fInputMagnitude;
	float m_fMoveLength;
	float m_fLateralSpeed;
	float m_fSpeedMultiplier;
	float m_fAbsolutAngleInput;
	int m_nQuadrantInput;
	SMatrix m_mvCameraInputWorldMat;
	bool m_bInputUpdated;
	bool m_bEnterEffectsPlayed;
	bool m_bCutSequenceActivated;
	SMatrix m_mvCoverPlaneMatPos;
	SMatrix m_mvStartMatPos;
	SMatrix m_mvDestMatPos;
	bool m_bExitToSneak;
	float m_fTimeSinceLastStickChange;
	unsigned int m_anCoverToCoverAnims[2][3];
	bool m_bUsePelvisRotationCorrection;
	bool m_bCtoCFacingChanged;
	SMatrix m_CTCStart;
	SMatrix m_CTCEnd;
	HM5Utils::SBlendParamFractions m_sCToCBlendFractions;
	bool m_bIsCoverScaleExitMovePossible;
	bool m_bExitScale;
	float m_fScaleCoverExitFraction;
	bool m_bEnterShootModeFacingRight;
	float m_fBlendToAimStateFraction;
	SMatrix m_mvShootMatPos;
	HM5Utils::SPelvisRotationCorrection m_PelvisRotationCorrection;
	bool m_bSwitchCoverFacingReversalAllowed;
	bool m_bSwitchCoverFacingUseAnimBlend;
	bool m_bSwitchCoverFacingDone;
	bool m_bIncreaseSwitchFacingFraction;
	bool m_bSwitchInitialFacingRight;
	float m_fSwitchCoverFacingAnimDuration;
	float m_fSwitchCoverFacingFraction;
	float m_fSwitchCoverFacingTime;
	float m_fBlindFire;
	float m_fBlindFireHoldTime;
	float m_fBlindFireFacing;
	float m_fBlindFireFacingTarget;
	SMatrix m_BlindFireStartPos;
	SMatrix m_BlindFireTargetPos;
	unsigned int m_anBlindFireAnimID[4][3];
	bool m_bCameraSideWhenEntering;
	bool m_bOTSActiveAtEnter;
	bool m_bCoverToCoverCameraFacing;
	float m_fCameraExitShootPosStartFraction;
	float m_fTransitionFraction;
	SMatrix m_CameraGroundStart;
	eCoverOTSMode m_eCoverOTSMode;
	float4 m_vForcedPos;
	bool m_bForcedClampToCoverCorners;
	bool m_bForceResetCamera;
	bool m_bForceExitOTSMode;
	bool m_bForceNoEnterAnimation;
	sSideCToCData m_SideCToCData;
	bool m_bWasCoverScaleExitMovePossibleCached;
	float4 m_vWasCoverScaleExitMovePossiblePos;
	bool m_bWasExitForwardPossibleCached;
	float4 m_vWasExitForwardPossiblePos;
	float m_fPosBunnyLength;
	float m_fNegBunnyLength;
	bool m_bAnimEndHigh;

	~ZHM5MovementCover() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	float GetWildCardTransitionTime(EBaseMovementType ePrevMoveType) const override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;
	void UpdateAim(SHM5AimInfo& sAimInfo) const override;
	void PrepareForCutSequence() override;

	ZHM5MovementCover() = default;
	ZHM5MovementCover(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	ZHM5CoverPlane* GetCurrentCoverPlane();
	const sExitCoverInfo* GetExitCoverInfo() const;
	void SetRequestedCoverPlane(ZHM5CoverPlane* pCoverPlane);
	void SetForceCover(bool bEnterToLeftSide, bool bForcedClampToCoverCorners, bool bForceResetCamera, bool bForceNoEnteranimation, const float4& vPos);
	bool IsInHighStance() const;
	eCoverMoveType GetMoveType() const;
	eCoverOTSMode GetCoverOTSMode() const;
	bool EnterCoverOTSMode();
	void ExitCoverOTSMode();
	bool CanOperateDoorFromCover(TEntityRef<IHM5Door> pDoor);
	bool CanReloadWeapon() const;
	bool CanEnterShootingBallet() const;
	bool CanBlindFireFromCover(const SMatrix& mvStartPos) const;
	bool CanFireWeaponFromCover() const;
	bool IsInBlindFireState() const;
	bool EnterBlindFireMode();
	bool IsThrowingAllowed() const;
	void UpdateRecoilAnimID(SRecoilAnimInfo& recoilAnimInfo) const;
	bool IsFacingRight() const;
	bool GetIsCoverScaleExitMovePossible() const;
	bool IsCoverToCoverMovePossible() const;
	float4 GetCoverToCoverDestPos() const;
	SMatrix GetDestMatPos() const;
	float GetPushDist() const;
	bool IsScalingCover() const;
	void UpdateMovementEnterCover(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementEnterCoverNoTrans(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementEnterCoverForced(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementDefault(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementSwitchCoverFacing(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementCoverToCover(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementExitCoverScale(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementBlindFire(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementEnterToShootPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementShootFromPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	void UpdateMovementExitFromShootPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	bool StartSwitchCoverFacing(bool bAllowReversal);
	float GetBlindFireDistThreshold() const;
	SMatrix CalcBlindFireTargetPos(const SMatrix& mvStartMatPos) const;
	bool CheckHighCoverBlindFireAngle(const float4& vCamDir, const SMatrix& mvBlindFirePos) const;
	void ExitBlindFireMode(bool bExitDirect);
	void EnableBlindFirePostProcessing(bool bEnable);
	void SetupBlindFirePose();
	void CacheBlindFireRecoilAnimIDs();
	void SetupEnterCover(bool bForced, ZHM5BaseMovement* pPrevMovement);
	void SelectEnterCoverAnimation(bool bForced, ZHM5BaseMovement* pPrevMovement);
	void PlayEnterCoverEffects();
	void SetCurrentCoverPlane(ZHM5CoverPlane* pNextCoverPlane);
	bool CanExitCover() const;
	bool ShouldExitCover();
	void SetupExitCoverMove();
	bool IsCoverScaleExitMovePossible_Cached();
	bool IsCoverScaleExitMovePossible() const;
	bool IsEnteringCover() const;
	bool IsExitingCover() const;
	bool IsCoverToCoverPossible() const;
	void SetupCoverToCoverMove();
	void SelectSideCoverToCoverAnims();
	float CalcGetSideCoverToCoverTravelDist();
	bool ReachedCorner(const SMatrix& mvMatPos);
	void UpdateSideCoverToCoverValues();
	void ResetCachedValues();
	void ResetSideCoverProperties();
	bool ShouldUpdateBunnyLength() const;
	void UpdateBunnyLength(bool bDirectSet);
	float4 CalcGetBunnyPos(const float4& vCurPos, const float fTravelDist, ZHM5CoverPlane* pCoverPlane);
	SMatrix GetMatPosToPos(const float4& vCurPos, ZHM5CoverPlane* pCoverPlane, float fPosBunnyDist, float fNegBunnyDist);
	void SetActionClientFilter(eCoverMoveType moveType);
	void SetMoveType(eCoverMoveType moveType);
	bool CanShootFromCover() const;
	SMatrix CalcGetShootPosition();
	void CalculateCoverAimPoint(SHM5AimInfo& sAimInfo) const;
	void SetupExitFromCoverShoot();
	void SetupExitFromCoverShootAnimBlend();
	void UpdateFacing();
	void UpdateStance(bool bSetStanceBlendParamDirect);
	void UpdateInput(const SGameUpdateEvent& updateEvent);
	void ResetInput();
	void UpdateMoveDir();
	void UpdateMoveSpeedMultiplier();
	bool ForceHandLayerFractionToZero() const;
	bool IsPointingForward(ZHM5BaseMovement::eMoveDir dir);
	float CalcGetCoverPlaneLocalCameraAngle();
	bool CoverActionPerform() const;
	bool CoverSecondaryActionPerform() const;
	bool CoverSwitchCoverPerform() const;
	void DrawDebugInput() const;
	float CalculateAimSneakValue() const;
	float GetAimSneak(const ZHM5CoverPlane* pCoverPlane, const float4& vShootPos, const float4& vAimSegment0, const float4& vAimSegment1) const;
};
