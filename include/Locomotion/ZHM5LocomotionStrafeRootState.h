#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionStrafeRootState : public ZHM5LocomotionState
{
public:
	float m_fDeltaCamAngle;

	~ZHM5LocomotionStrafeRootState() override = default;
	void Activate() override;
	void Update(float fDeltaTime) override;
	void Deactivate() override;

	ZHM5LocomotionStrafeRootState() = default;
};
