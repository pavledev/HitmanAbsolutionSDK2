#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionStrafeStandState : public ZHM5LocomotionState
{
public:
	~ZHM5LocomotionStrafeStandState() override = default;
	void Update(float fDeltaTime) override;

	ZHM5LocomotionStrafeStandState() = default;
};
