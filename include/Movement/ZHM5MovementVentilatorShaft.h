#pragma once

#include "ZHM5BaseMovement.h"
#include "eMorphemeRequests.h"
#include "ZHM5GuideVentilatorShaft.h"
#include "ZMovementAnimNode.h"
#include "ZMovementAnimNodeEx.h"
#include "ZMovementAnimTransition.h"
#include "ZSplinePosition.h"
#include "HM5Utils.h"
#include "ZGameTime.h"
#include "ZMapPoly.h"

class IHM5Item;

class ZHM5MovementVentilatorShaft : public ZHM5BaseMovement
{
public:
	enum EState
	{
		StateNone = 0,
		StateMounting = 1,
		StateIdle = 2,
		StateForward = 3,
		StateBackward = 4,
		StateDismount = 5,
		StateLookGrill = 6
	};

	EState m_eState;
	bool m_bAnimationActivated;
	int m_iMountIdx;
	int m_iDismountIdx;
	eMorphemeRequests m_iMorpheneRequest;
	float4 m_vDirection;
	float4 m_vOldSplinePosition;
	float m_fMovement;
	float m_fMovementSign;
	float m_fMovementAcceleration;
	float m_fAnimPrc;
	float m_fLookLeftRight;
	float m_fLookUpDown;
	TEntityRef<ZSpatialEntity> m_rPeekEntity;
	float m_fLookAtWeight;
	float m_fFrameZippoActivateDeactivateEvent;
	float m_fFrameZippoShowHideEvent;
	TEntityRef<IHM5Item> m_pZippo;
	ZGameTime m_ttLastPlayerMovement;
	bool m_bPeekHoleAvailable;
	float m_fSpatialBlurValue;
	ZMapPoly m_MapPolySlow;
	TEntityRef<ZHM5GuideVentilatorShaft> m_rGuide;
	ZMovementAnimNode* m_pCurrentAnim;
	ZMovementAnimNodeEx m_AnimForward;
	ZMovementAnimNodeEx m_AnimBackward;
	ZMovementAnimNode m_AnimEnterHigh;
	ZMovementAnimNode m_AnimEnterLow;
	ZMovementAnimNode m_AnimExitForwardHigh;
	ZMovementAnimNode m_AnimExitBackwardsHigh;
	ZMovementAnimNode m_AnimExitForwardLow;
	ZMovementAnimNode m_AnimExitBackwardsLow;
	ZMovementAnimNode m_AnimIdle;
	ZMovementAnimNode m_AnimLookGrillDown;
	ZMovementAnimNode m_AnimLookGrillLeft;
	ZMovementAnimNode m_AnimLookGrillRight;
	ZMovementAnimNode m_AnimLookGrillForward;
	ZMovementAnimTransition m_TransitionEnter;
	ZMovementAnimTransition m_TransitionExit;
	ZMovementAnimTransition m_TransitionLook;
	ZSplinePosition m_SplinePositionHead;
	ZSplinePosition m_SplinePositionHand;
	ZSplinePosition m_SplinePosition;
	ZSplinePosition m_OldSplinePosition;
	ZSplinePosition m_SplinePositionStart;
	ZSplinePosition m_SplinePositionEnd;
	ZMapPoly m_MapPoly;
	SMatrix m_mLookGrillDelta;
	float m_fLookGrillDist;
	float m_fLookGrillPrc;
	SMatrix m_mvBlendMats[3];
	HM5Utils::SAnimBlend m_sAnimBlends[3];
	float4 m_vForcedPos;
	bool m_bForcedCanPeekStart : 1;
	bool m_bForcedCanPeekEnd : 1;
	float m_fDismountBlendOutFraction;
	bool m_bZippoLighterActivated;
	SVector2 m_vCurrentHandPosition;

	~ZHM5MovementVentilatorShaft() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	unsigned int ShowItems() const override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mFrom, SMatrix& mTo) override;

	ZHM5MovementVentilatorShaft() = default;
	ZHM5MovementVentilatorShaft(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void SetForceVent(TEntityRef<ZHM5GuideVentilatorShaft> rVentilatorShaft, const float4& vPos, bool bForcedCanPeekStart, bool bForcedCanPeekEnd);
	TEntityRef<ZHM5GuideVentilatorShaft> GetGuide() const;
	void UpdatePath();
	void ActivateEnterVentilatorShaft(TEntityRef<ZHM5GuideVentilatorShaft> rVentilatorShaft);
	void ActivateExitVentilatorShaft();
	bool IsAtEndPosition(unsigned int& nIndex) const;
	bool IsMountingDismounting() const;
	bool IsPeekHoleAvailable() const;
	bool IsExitVentPosible() const;
	void SetPeekEntity(TEntityRef<ZSpatialEntity> rRef);
	void SetPeekHoleAvailable(bool bValue);
	unsigned int GetCurrentAnimId() const;
	bool IsEntering() const;
	bool IsExiting() const;
	void OnEnterVentilatorShaft();
	void OnExitVentilatorShaft();
	void OnEnterEndOfPath(unsigned int iIdx);
	void OnLeaveEndOfPath(unsigned int iIdx);
	void UpdateSpatialBlur();
	void SetupMountAnimBlendList();
	void AttachZippo(bool bAttach);
	bool ActivateZippo(bool bTurnOn) const;
	void DeAttachZippo();
	SVector2 GetInput() const;
};
