#pragma once

#include "IComponentInterface.h"
#include "ZRuntimeResourceID.h"

class ZResourcePending;

class IResourceInstaller : public IComponentInterface
{
public:
    virtual void Release(const ZRuntimeResourceID*, void*, unsigned int);
    virtual void* Allocate(unsigned int);
    virtual bool Install(ZResourcePending*);
    virtual bool IsStreamInstaller();
    virtual bool IsIndirectionInstaller();
    virtual bool SupportsAllocate();
    virtual void OnOrphanedResource(const ZRuntimeResourceID*, void*, unsigned int);
};
