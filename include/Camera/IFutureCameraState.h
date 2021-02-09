#pragma once

#include "IComponentInterface.h"
#include "SCameraState.h"

class IFutureCameraState : public IComponentInterface
{
public:
    virtual SCameraState* GetFutureCameraState(SCameraState* result);
    virtual SCameraState* GetCurrentCameraState(SCameraState* result);
    virtual void DisableCameraControl();
    virtual void EnableCameraControl();

    IFutureCameraState();
    IFutureCameraState(IFutureCameraState const&);
    IFutureCameraState* operator=(IFutureCameraState const&);
};
