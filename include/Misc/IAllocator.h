#pragma once

#include "IComponentInterface.h"

class IAllocator : IComponentInterface
{
    virtual unsigned int GetDefaultAlignment();
    virtual bool SupportsAlignedAllocations();
    virtual void* Allocate(unsigned int, unsigned int);
    virtual void* AllocateAligned(unsigned int, unsigned int, unsigned int);
    virtual void Free(void*);
    virtual unsigned int GetAllocationSize(void*);
    virtual void* ReAllocate(void*, unsigned int, unsigned int);
    virtual void* ReAllocateAligned(void*, unsigned int, unsigned int, unsigned int);
    virtual void CheckHeap();
};
