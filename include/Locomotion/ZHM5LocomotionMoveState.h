#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionMoveState : public ZHM5LocomotionState
{
public:
	~ZHM5LocomotionMoveState() override = default;
	void Activate() override;

	ZHM5LocomotionMoveState() = default;
};
