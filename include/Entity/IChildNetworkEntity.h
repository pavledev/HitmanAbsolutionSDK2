#pragma once

#include "IComponentInterface.h"
#include "IVariationInstance.h"

class IChildNetworkEntity : public IComponentInterface
{
public:
    virtual unsigned int CreateNetworkInstance(IVariationInstance*);
    virtual ZString* GetDebugName(ZString* result);
    virtual ZRuntimeResourceID* GetNetworkRuntimeResourceID(ZRuntimeResourceID* result);
};
