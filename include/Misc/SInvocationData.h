#pragma once

#include "TList.h"
#include "TPair.h"
#include "ZDelegate.h"

template<class A, class B = A>
class SInvocationData
{
public:
    SInvocationData* pNullOrDelegateAddedIndicator;
    unsigned int nRemoved;
    TList<TPair<int, ZDelegate<void __cdecl(A, B)>>> added;
};
