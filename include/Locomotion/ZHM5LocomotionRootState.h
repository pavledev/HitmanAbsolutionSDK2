#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionRootState : public ZHM5LocomotionState
{
public:
	~ZHM5LocomotionRootState() override = default;
	void Update(float fDeltaTime) override;
	void Deactivate() override;

	ZHM5LocomotionRootState() = default;
};
