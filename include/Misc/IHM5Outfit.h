#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "STokenID.h"

class IHM5Outfit : public IComponentInterface
{
public:
    virtual bool IsAllowedIn(const ZEntityRef*);
    virtual int GetZoneMask();
    virtual bool SupportsActor(const STokenID*);
};
