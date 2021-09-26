#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHitmanMorphemePostProcessorFiberWireCallback.h"
#include "HM5Utils.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "TSharedPointer.h"
#include "ZString.h"
#include "float4.h"

class IHM5Item;
class IMorphemeEntity;
class ZActor;
class ZControlledAnimLocomotion;
class ZHitman5;
struct SBaseMovmentCollisionInfo;
struct SCameraUpdateEvent;
struct SHM5GameCamParams;
struct sFiberWireInfos;

class ZHM5MovementFiberWireKill : public ZHM5BaseMovement, public ZHitmanMorphemePostProcessorFiberWireCallback
{
public:
	enum EMoveType
	{
		eFWUnknown = 0,
		eFWToDrag = 1,
		eFWToStandOrSneak = 2
	};

	TEntityRef<ZActor> m_pVictim;
	ZString m_sVictimAnimSM;
	ZString m_sVictimAnim;
	unsigned int m_nActiveAnimId;
	unsigned int m_nToStandOrSneakAnimId;
	float m_fAnimFraction;
	float m_fAnimFraction2;
	float m_fAnimDelta;
	float m_fAnimDelta2;
	float m_fAlignTime;
	float m_fContactTime;
	float m_fDropItemsFraction;
	SMatrix m_mVictimStart;
	SMatrix m_mVictionAlign;
	float m_fHandRetargetFrom;
	float m_fHandRetargetTo;
	float m_fNPCDeadFraction;
	float m_fImpactFraction;
	float m_fDragBlendHeightLow;
	float m_fDragBlendHeightHigh;
	EMoveType m_eMoveType;
	bool m_bUpdate;
	TSharedPointer<ZControlledAnimLocomotion> m_pLoco;
	TEntityRef<IHM5Item> m_rFiberWire;
	bool m_bEffectPlayed;
	bool m_bShortAnim;
	bool m_bActivateButtonPrompt;
	float m_fCurrentTimeMultiplier;
	float m_fFailSafeEndFraction;
	float m_fFiberWireFeedBackWeight;
	int m_nDragBoneMeshId;
	SMatrix m_mvHitmanStartMatPos;
	SMatrix m_mvHitmanDestMatPos;
	HM5Utils::SAnimBlend m_sAnimBlend;
	float m_fEndCameraFollowFraction;
	bool m_bCameraInitialized;
	float m_fDesiredStickLength;
	float m_fCurCamStickLength;
	float m_fDesiredHeight;
	float m_fCurCamHeight;
	float4 m_vDesiredGround;
	float4 m_vCurrentFocusPoint;
	SMatrix m_CameraGround;

	~ZHM5MovementFiberWireKill() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void DeactivateMovement() override;
	void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo) override;
	void UpdateOutsideControl() override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	unsigned int ShowItems() const override;
	void HitmanOutfitMeshChanged() override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;

	void FiberWireCallBack(sFiberWireInfos* pInfo) override;

	ZHM5MovementFiberWireKill() = default;
	ZHM5MovementFiberWireKill(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	float GetCamDragFraction() const;
	bool ActivateButtonPrompt() const;
	void ResetButtonPrompt();
	const TEntityRef<ZActor>& GetVictim() const;
	bool CanFiberWire() const;
	void SetFeedBackAnimWeight(const float fWeight);
	void SelectAnim();
	void UpdateAnimFraction();
	void UpdateAnimFraction2();
	void UpdateVictimground(const SMatrix& mvHMMatPos);
	void SetupAnimBlend();
	void SwapFiberWireHands(bool bBackToOriginal);
	void SetActiveFlag(bool bActive);
	void PlayRumbleEffect();
	void UpdateTimeMultiplier();
	void UpdateDragAnim();
	void CacheBoneData();
};
