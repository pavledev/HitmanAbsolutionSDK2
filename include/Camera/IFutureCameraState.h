#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"

class __declspec(novtable) IFutureCameraState : public IComponentInterface
{
public:
	struct SCameraState
	{
		SMatrix transform;
		float fov;

		SCameraState() = default;
	};

	~IFutureCameraState() override = default;
	virtual SCameraState GetFutureCameraState() = 0;
	virtual SCameraState GetCurrentCameraState() = 0;
	virtual void DisableCameraControl() = 0;
	virtual void EnableCameraControl() = 0;

	static void RegisterType();
	IFutureCameraState() = default;
};
