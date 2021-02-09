#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "ZHitman5.h"

class IHM5ForceMovementCallBack : public IComponentInterface
{
public:
    virtual void ForceMovement();
    virtual TEntityRef<ZHitman5>* Hitman(TEntityRef<ZHitman5>* result);
};
