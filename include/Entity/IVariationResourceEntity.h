#pragma once

#include "IComponentInterface.h"
#include "IVariationInstance.h"

class IVariationResourceEntity : public IComponentInterface
{
public:
    virtual bool IsReady();
    virtual IVariationInstance* GetVariationInstance();
    virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetVariationResourceStatusEvent();
};
