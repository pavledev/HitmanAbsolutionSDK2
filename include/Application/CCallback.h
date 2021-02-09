#pragma once

#include "CCallbackBase.h"

template<class A, class B, int C>
class CCallback : CCallbackBase
{
public:
    A* m_pObj;
    void* m_Func;

    /*void(__thiscall* m_Func)(A* this, B*);

    virtual void Run(void*, bool, unsigned __int64);
    virtual void Run(void*);
    virtual int GetCallbackSizeBytes();
    virtual void ~CCallback();*/
};
