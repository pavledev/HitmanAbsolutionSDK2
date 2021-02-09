#pragma once

#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"
#include "ICharacterController.h"

class IBoneCollidable
{
public:
    virtual bool CheckLineCollision(const ZRayQueryInput*, ZRayQueryOutput*);
    virtual ICharacterController* GetCharacterController();
    virtual ~IBoneCollidable();

    IBoneCollidable();
    IBoneCollidable(IBoneCollidable const&);
    IBoneCollidable* operator=(IBoneCollidable const&);
};
