#pragma once

#include "ZHM5VictimBaseMovement.h"
#include "EWindowStatus.h"
#include "ECameraOffset.h"
#include "EHM5ResetReason.h"
#include "HM5Utils.h"
#include "SMatrix.h"
#include "float4.h"

class IMorphemeEntity;
class ZHM5BaseMovement;
class ZHM5GuideLedge;
class ZHM5GuideWindow;
class ZHitman5;
struct SCameraUpdateEvent;
struct SGameUpdateEvent;
struct SHM5GameCamParams;
template <class T> class TEntityRef;

class ZHM5MovementPullVictimThroughWindow : public ZHM5VictimBaseMovement
{
public:
	ZHM5GuideWindow* m_pWindow;
	EWindowStatus m_WindowStatus;
	ZHM5GuideLedge* m_pLedge;
	float m_fBlendInFraction;
	float m_fBlendOutFraction;
	SMatrix m_aBlendMats[4];
	HM5Utils::SAnimBlend m_aAnimBlends[4];
	bool m_bGrabEventSent;
	bool m_bAnimateWindow;
	SMatrix m_mvWindowStartMatPos;
	float m_fStartWindowAnimTime;
	float m_fStopWindowAnimTime;
	float4 m_vWindowDeltaZ;
	ECameraOffset m_eCameraOffset;
	bool m_bActivateButtonPrompt;
	bool m_bVictimFacingBack;
	bool m_bCameraInitialized;
	float m_fDesiredStickLength;
	float m_fCurCamStickLength;
	float m_fDesiredHeight;
	float m_fCurCamHeight;
	float4 m_vDesiredGround;
	float4 m_vCurrentFocusPoint;
	SMatrix m_CameraGround;

	~ZHM5MovementPullVictimThroughWindow() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdateOutsideControl() override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	bool SetUpAnimation() override;
	bool InitTimeFractions() override;
	void InitBlendMatrices() override;
	SMatrix GetBlendInMatPos() const override;

	ZHM5MovementPullVictimThroughWindow() = default;
	ZHM5MovementPullVictimThroughWindow(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	bool ActivateButtonPrompt() const;
	void ResetButtonPrompt();
	void UpdateWindowAnimtion(const SMatrix& mvHMPos);
};
