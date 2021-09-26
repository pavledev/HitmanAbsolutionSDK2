#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionToMoveState : public ZHM5LocomotionState
{
public:
	~ZHM5LocomotionToMoveState() override = default;
	void Update(float fDeltaTime) override;

	ZHM5LocomotionToMoveState() = default;
};
