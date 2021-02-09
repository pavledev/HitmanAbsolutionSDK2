#pragma once

#include "TArray.h"
#include "TPair.h"
#include "ZDelegate.h"
#include "SInvocationData.h"

template<class A,class B>
class ZEvent2
{
    TArray<TPair<int, ZDelegate<void __cdecl(A, B)>>> m_delegates;
    SInvocationData<A, B>* m_pInvocation;
};
