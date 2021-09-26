#pragma once

#include "ZHM5BaseMovement.h"
#include "EShootingBalletState.h"
#include "SHM5SBShared.h"
#include "ZHM5ShootingBalletWeapon.h"
#include "SSBAnim.h"
#include "SBWeaponNodes.h"
#include "HM5Utils.h"
#include "SSBFocus.h"

class ZHM5MovementShootingBallet : public ZHM5BaseMovement
{
public:
	enum EShootingBalletState
	{
		eNotInShootingBallet = 0,
		eEnteringFromCover = 1,
		eTagging = 2,
		eExecuting = 3,
		eWaitOutroAnim = 4,
		eTerminateControl = 5
	};

	EShootingBalletState m_eShootingBalletState;
	SHM5SBShared m_SBShared;
	ZHM5ShootingBalletWeapon* m_pSBWeapon;
	bool m_bEnteredTagAnimNode;
	float m_fTagTime;
	ZGameTime m_StartRealTime;
	ZGameTime m_EndTime;
	bool m_bTagRampUpSignalSend;
	bool m_bAnyoneDamaged;
	float m_fCinMultiplier;
	float m_fForcedTimeMultiplier;
	const SSBAnim* m_pEndAnimation;
	float m_fImpactZoomTime;
	float m_fTagModeTimeMultiplyerOverride;
	ZMapPoly m_MapPoly;
	SBWeaponNodes* m_pWeaponNodes;
	ESBWeaponType m_eCurrentWeaponType;
	bool m_bKilledAllCharacterChecked;
	int m_nCharactersKilled;
	bool m_bReturnToCover;
	ZHM5CoverPlane* m_pLastCoverPlane;
	SMatrix m_mvLastCoverPos;
	bool m_bFaceRight;
	bool m_bCoverHighStance;
	bool m_bUsesManualControlForCamera;
	unsigned int m_nEnterFromCoverAnimID;
	unsigned int m_nSBWildCardTransitID;
	HM5Utils::SAnimBlend m_sAnimBlend;
	SMatrix m_mvStartMatPos;
	SMatrix m_mvDestMatPos;
	SMatrix m_mvCameraGroundStart;
	float4 m_vCameraOffset;
	bool m_bLerpCameraGround;
	float m_fCameraLerpFraction;
	float m_fBlendOutFraction;
	float4 m_avGripOffset[2];
	SQuaternion m_aqGripOrientation[2];
	float m_fCameraAim;
	bool m_bAimBlendOut;
	float m_fAimBlendOutTime;
	float m_afTagLookAtWeightsHorizontal[6];
	float m_afTagLookAtWeightsVertical[6];
	SSBFocus m_SBFocus;
	bool m_bForced;
	bool m_bAllowPlayerToExecute;
	bool m_bExecuteWhenInstinctRunsOut;
	TEntityRef<ZActor> m_rPrimaryActor;
	bool m_bForceExecute;
	float m_fStartFocus;
	bool m_bLookAtPoseChanged;
	bool m_bUpdateLookAt;

	~ZHM5MovementShootingBallet() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdateOutsideControl() override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void ReinitializeMorphemeData(IMorphemeEntity* pMorphemeEntity) override;
	void UpdateLookAt(SHM5LookAtInfo& sLookAtInfo) const override;

	ZHM5MovementShootingBallet() = default;
	ZHM5MovementShootingBallet(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	float GetExecutionFraction() const;
	float GetTagTimeRemaining() const;
	float GetExecutionTimeRemaining() const;
	ZHM5SBTagMode& GetTagMode() const;
	bool IsExecuting() const;
	bool CanStartExecution() const;
	bool CanSkipCinematics() const;
	ZGameTime GetStartRealTime() const;
	ZGameTime GetEndTime() const;
	void SBDamagingShot(unsigned int iProjectileId);
	void SBConfirmKill(unsigned int iProjectileId);
	void IncreaseKillCount();
	void OnChainReactionHit(ZActor* pActor, unsigned int iProjectileId);
	bool FireAtTag(unsigned int nTagIndex, bool bRightHand);
	bool IsTagging() const;
	float GetExecutionDuration() const;
	float GetProperTagTimeMultiplier() const;
	void SetTagModeTimeMultiplyerOverride(float fTagModeTimeMultiplyerOverride);
	bool CanStartShootingBallet(const bool bForceCheck) const;
	bool TriggerAimAssist() const;
	bool IsTagModeZoomed() const;
	float GetCameraAim() const;
	float GetBlendOutFraction() const;
	bool UsesManualControlForCamera() const;
	const SSBFocus& GetSBFocus() const;
	void SetForcedData(const SSBFocus& sSBFocus, bool bAllowPlayerToExecute, bool bExecuteWhenInstinctRunsOut, TEntityRef<ZActor> rPrimaryActor);
	void ForceExecute();
	SSBFocus GetDefaultFocusSettings() const;
	bool IsInShootingBallet();
	void StartEnterFromCoverState(ZHM5MovementCover* pCoverMovement);
	void StartTaggingMode();
	void EnterShootSequence(const SMatrix& mHitman);
	void StartEndAnimation();
	void EndShootingBallet(bool bInterrupted);
	void SetTimeMultiplier(float fTimeMultiplier);
	void UpdateBlends(float fNormalizedDeltaTime);
	void UpdateExecutionGrip(const SSBAnim* pAnim, float fAnimFraction);
	ESBWeaponType GetSBWeaponTypeEquipped() const;
	ESBTagMode GetSBTagMode() const;
	void UpdateAimBlendOut(float fDeltaTime);
};
