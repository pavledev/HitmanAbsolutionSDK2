#pragma once

#include "GRefCountBase.h"
#include "GFxResource.h"

class GFxResourceLibBase : public GRefCountBase<GFxResourceLibBase, 2>
{
public:
    virtual void RemoveResourceOnRelease(GFxResource*);
    virtual void PinResource(GFxResource*);
    virtual void UnpinResource(GFxResource*);
};
