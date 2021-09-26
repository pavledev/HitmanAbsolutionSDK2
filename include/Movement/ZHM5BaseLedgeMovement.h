#pragma once

#include "ZHM5BaseMovement.h"
#include "eEdgeEnd.h"
#include "eOnLedgeMoveType.h"
#include "EBaseMovementType.h"
#include "ECameraOffset.h"
#include "EHM5ResetReason.h"
#include "SVector2.h"
#include "ZString.h"
#include "float4.h"

class IMorphemeEntity;
class ZHM5BaseGuide;
class ZHM5GuideJump;
class ZHitman5;
struct SMatrix;
template <class T> class TEntityRef;

class ZHM5BaseLedgeMovement : public ZHM5BaseMovement
{
public:
	ZHM5GuideJump* m_pCurrentGuide;
	eEdgeEnd m_eEdgeEndStatus;
	ZHM5BaseMovement::eMoveDir m_MoveDir;
	eOnLedgeMoveType m_eMoveType;
	unsigned int m_nActiveAnimNode;
	float m_fLateralSpeed;
	bool m_bLimitMove;
	ZHM5GuideJump* m_pJumpNextGuide;
	bool m_bShootIntoGround;
	bool m_bLedgeOTSMode;
	bool m_bPullVictimPossible;
	float m_fFeedBackPoseWeight;
	float m_fFeedBackLookUpDown;
	float m_fFeedbackLookLeftRight;
	float4 m_vForcedPos;
	float m_fForcedLookLeftRight;
	float m_fForcedTargetWeight;
	bool m_bForcedKeepPosOnLedge;
	ECameraOffset m_eCameraOffset;
	bool m_bAutoDismountFromTop;
	SVector2 m_vMove;
	float m_fRawInputX;
	float m_fRawInputY;
	float m_fInputVelocity;
	float m_fAbsolutAngleInput;
	int m_nQuadrantInput;
	bool m_bOverridePlayerCollision;
	float4 m_vPlayerCollisionPos;

	~ZHM5BaseLedgeMovement() override = default;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void DeactivateMovement() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	bool OverridePlayerCollisionPosition(float4& vPos) const override;
	virtual void SetCurrentGuide(ZHM5BaseGuide* pGuide);
	virtual bool EnterLedgeOTSMode();
	virtual void ExitLedgeOTSMode();
	virtual ZHM5BaseGuide* GetClosestNeightbourGuide(float fLookDistance, unsigned int nFilter, unsigned char nDir);

	ZHM5BaseLedgeMovement() = default;
	ZHM5BaseLedgeMovement(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman, EBaseMovementType eType);
	ZHM5GuideJump* GetCurrentGuide();
	eOnLedgeMoveType GetMoveType() const;
	void AllignClavicleForLedgeWalk(ZHM5GuideJump* pCurrentGuide, unsigned int nActiveAnimID, float fStartAllign, float fEndAllign);
	bool IsPullVictimPossible() const;
	void SetForceToLedge(ZHM5GuideJump* pJumpGuide, const float4& vPos, float fLookLeftRight, bool bKeepPosOnLedge);
	float4 GetForcedPos() const;
	bool GetForcedKeepPosOnLedge() const;
	void SetEdgeEndStatus(eEdgeEnd eEdgeEndStatus);
	bool IsMoving() const;
	bool GetAutoDismountFromTop() const;
	ZString GetMoveTypeString(eOnLedgeMoveType eMoveType) const;
	ZString GetMoveDirString(ZHM5BaseMovement::eMoveDir eDir) const;
	void AllignMatPosToColiGeom(SMatrix& mvTo, const float4& vGuideDir);
	ZHM5BaseGuide* GetConnectedGuide(unsigned int nFilter);
	bool IsGuideConnectedToCurrentGuide(ZHM5BaseGuide* pGuide);
	float GetDistToCurrentGuideEnd(float fTreshold, bool bRight);
	bool IsJumpActive();
	bool IsGuideHangable(ZHM5BaseGuide* pGuide);
	float4 CalcGetHandDir(const float4& vHandPos, ZHM5GuideJump* pHandOnGuide);
	float CalcGetAngleBetweenGuides(ZHM5GuideJump* pCurrent, ZHM5GuideJump* pNext, bool& bConcave);
	void LockMovementVector();
	float4 CalcPlayerCollisionFeetHeight(const SMatrix& mvGround) const;
	void UpdateInput();
	SVector2 GetMoveInput() const;
};
