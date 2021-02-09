#pragma once

#include "ZGameTime.h"
#include "EFiberState.h"

class ZFiber
{
public:
    alignas(8) int m_ExecFunction[16];
    ZGameTime m_sleepUntil;
    EFiberState m_nFiberState;
    void* m_pData;
    void(__cdecl* m_pFunction)(void*);
    void* m_pStackData;
    unsigned int m_nStackStart;
    unsigned int m_nStackSize;
    unsigned int m_nStackAllocated;

    virtual ~ZFiber();
};
