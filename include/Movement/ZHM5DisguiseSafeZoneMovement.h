#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHM5DisguiseSafeZoneEntity.h"
#include "ZMapPoly.h"

class ZHM5DisguiseSafeZoneMovement : public ZHM5BaseMovement
{
public:
	TEntityRef<ZHM5DisguiseSafeZoneEntity> m_rSafeZone;
	unsigned int m_nSafeZoneNetworkId;
	unsigned int m_nNumActiveFrames;
	bool m_bWaitingForExitEvent;
	float m_fBlendInFraction;
	SMatrix m_mStart;
	SMatrix m_mEnd;
	ZMapPoly m_MapPoly;
	bool m_bForceNoEnterAnim;

	~ZHM5DisguiseSafeZoneMovement() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void ActivateMovement() override;
	void DeactivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;

	ZHM5DisguiseSafeZoneMovement() = default;
	ZHM5DisguiseSafeZoneMovement(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	TEntityRef<ZHM5DisguiseSafeZoneEntity> GetSafeZone() const;
	void SetSafeZone(TEntityRef<ZHM5DisguiseSafeZoneEntity> rSafeZone);
	bool IsWaitingForExitEvent() const;
	void SetForced(bool bForceNoEnterAnim);
	ZMorphemeNetworkInstance* GetSafeZoneNetwork();
	void UpdateFocusGain() const;
};
