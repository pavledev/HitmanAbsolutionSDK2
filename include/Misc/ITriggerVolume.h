#pragma once

#include "IComponentInterface.h"
#include "float4.h"
#include "ZDelegate.h"
#include "ZEntityRef.h"

class ITriggerVolume : IComponentInterface
{
public:
    virtual bool ContainsPoint(const float4*);
    virtual void GetAxisAlignedBox(float4*, float4*);
    virtual void RegisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>*);
    virtual void UnregisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>*);
};
