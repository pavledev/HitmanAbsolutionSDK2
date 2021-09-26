#pragma once

#include "ZHM5BaseMovement.h"
#include "SHitInfo.h"
#include "ZGameTime.h"

class IMorphemeEntity;
class ZHitman5;
struct SCameraUpdateEvent;
struct SMatrix;
template <class T> class TEntityRef;

class ZHM5MovementDead : public ZHM5BaseMovement
{
public:
	SHitInfo m_HitInfo;
	ZGameTime m_startOfDeath;
	bool m_bTimeOut;

	~ZHM5MovementDead() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const override;
	void RemoveControl() override;
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const override;
	void UpdateMovement() override;
	void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo) override;

	ZHM5MovementDead() = default;
	ZHM5MovementDead(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void ActivateDeadMovement();
	void DeactivateDeadMovement();
	void SetHitInfo(const SHitInfo& HitInfo);
};
