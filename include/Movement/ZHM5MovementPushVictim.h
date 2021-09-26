#pragma once

#include "ZHM5VictimBaseMovement.h"
#include "EHM5ResetReason.h"
#include "HM5Utils.h"
#include "SMatrix.h"
#include "float4.h"

class IMorphemeEntity;
class ZActor;
class ZHM5BaseMovement;
class ZHM5CoverPlane;
class ZHM5GuideWindow;
class ZHitman5;
struct SCameraUpdateEvent;
struct SGameUpdateEvent;
struct SHM5GameCamParams;
template <class T> class TEntityRef;

class ZHM5MovementPushVictim : public ZHM5VictimBaseMovement
{
public:
	bool m_bWantsControl;
	bool m_bGrabEventSent;
	ZHM5GuideWindow* m_pWindow;
	ZHM5CoverPlane* m_pRail;
	SMatrix m_aBlendMats[4];
	HM5Utils::SAnimBlend m_aAnimBlends[4];
	bool m_bCameraInitialized;
	float m_fDesiredStickLength;
	float m_fCurCamStickLength;
	float m_fDesiredHeight;
	float m_fCurCamHeight;
	float4 m_vDesiredGround;
	float4 m_vCurrentFocusPoint;
	SMatrix m_CameraGround;

	~ZHM5MovementPushVictim() override = default;
	void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement) override;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void UpdateOutsideControl() override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	bool SetUpAnimation() override;
	SMatrix GetBlendInMatPos() const override;

	ZHM5MovementPushVictim() = default;
	ZHM5MovementPushVictim(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	ZHM5GuideWindow* CheckNearEnemyAtWindow() const;
	ZHM5CoverPlane* CheckNearEnemyAtRail() const;
	bool CheckNearEnemyAngle(TEntityRef<ZActor> rActor, float fAngle) const;
};
