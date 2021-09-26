#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionStrafeState : public ZHM5LocomotionState
{
public:
	~ZHM5LocomotionStrafeState() override = default;
	void Update(float fDeltaTime) override;
	void Deactivate() override;

	void SetStrafeTrajectory(float fDeltaTime);
	void ClearStrafeTrajectory();
	ZHM5LocomotionStrafeState() = default;
};
