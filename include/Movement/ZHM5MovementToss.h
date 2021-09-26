#pragma once

#include "ZHM5BaseMovement.h"
#include "HM5Utils.h"
#include "ZHM5TossController.h"
#include "ECameraState.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "ZGameTime.h"
#include "float4.h"

class IHM5Item;
class IMorphemeEntity;
class ZActor;
class ZHM5CoverPlane;
class ZHitman5;
struct SCameraUpdateEvent;
struct SGameUpdateEvent;
struct SHM5AimInfo;

class ZHM5MovementToss : public ZHM5BaseMovement
{
public:
	struct SThrowAnimInfo
	{
		unsigned int m_nAnimID;
		unsigned int m_nAnimStateID;
		unsigned int m_nParentStateID;
		float m_fStartAlignFraction;
		float m_fEndAlignFraction;
		float m_fReleaseFraction;
		float m_fColiCheckFraction;
		float m_fDuration;
		SMatrix m_mLockFootReleaseMatPos;
		SMatrix m_mRightHandReleaseMatPos;
		SMatrix m_mRightAttacherReleaseMatPos;
		SMatrix m_mRightAttacherColiCheckMatPos;
		SMatrix m_mReleaseGroundDelta;

		SThrowAnimInfo() = default;
	};

	SMatrix m_mvLastRightAttMatPos;
	bool m_bWantControl;
	ZHM5TossController::EThrowType m_eThrowType;
	SThrowAnimInfo m_aThrowAnimInfo[40];
	float m_fAnimFraction;
	float4 m_vThrowDir;
	unsigned int m_nThrowFractionParamID;
	unsigned int m_nHeavyThrowWeightID;
	bool m_bReleasedItem;
	TEntityRef<IHM5Item> m_rItem;
	TEntityRef<ZActor> m_pDeadlyThrowTarget;
	bool m_bReturnToCover;
	ZHM5CoverPlane* m_pLastCover;
	SMatrix m_mvStartMatPos;
	SMatrix m_mvThrowDestMatPos;
	SMatrix m_mvCoverDestMatPos;
	HM5Utils::SAnimBlend m_sAnimBlend;
	ECameraState m_eCameraState;
	SMatrix m_CoverCameraGround;
	bool m_bApplyBoneLock;
	SMatrix m_mvLockBoneStart;
	SMatrix m_mvLockBoneDest;
	HM5Utils::SPelvisSimpleRotationCorrection m_sPelvisCorrection;

	~ZHM5MovementToss() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;
	void UpdateAim(SHM5AimInfo& sAimInfo) const override;

	ZHM5MovementToss() = default;
	ZHM5MovementToss(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	bool IsDeadlyThrow() const;
	bool IsExplosive() const;
	SMatrix GetWorldColiCheckMatPos(ZHM5TossController::EThrowType eThrowType, const SMatrix& mvStartPos, const SMatrix& mvCamAlignedStartPos, const SMatrix& mvDeadlyThrowTarget) const;
	SMatrix GetReleaseWorldMatPos(ZHM5TossController::EThrowType eThrowType, const SMatrix& mvStartPos, const SMatrix& mvCamAlignedStartPos, const SMatrix& mvDeadlyThrowTarget) const;
	void InitAnimData();
	void SetNetworkParameters() const;
	bool IsRightThrow() const;
	void SetThrowDirParam() const;
	void ReleaseNormalThrow(ZGameTime releaseTime);
	void ReleaseDeadlythrow(ZGameTime releaseTime);
	float4 CalcThrowDir(ZHM5TossController::EThrowType eThrowType, const SMatrix& mvHitmanMatPos, const SMatrix& mvDeadlythrowTarget) const;
	void CalcLockBoneDelta(SMatrix& mLockBoneStart, SMatrix& mLockBoneDest, const SMatrix& mStartPos, ZHM5TossController::EThrowType eThrowType, const float4& vThrowDir) const;
	SMatrix GetCorrectedThrowingGround(ZHM5TossController::EThrowType eThrowType, const SMatrix& mvStartPos, const SMatrix& mvCamAlignedStartPos, const SMatrix& mvDeadlyThrowTarget) const;
	void SetupThrowAnimBlend();
	void SetupBackToCoverPelvisBlend(const SMatrix& mvCurrentGround);
	void DrawDebugAttacherMatPos();
};
