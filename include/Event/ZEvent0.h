#pragma once

#include "TArray.h"
#include "TPair.h"
#include "TList.h"
#include "ZDelegate.h"
#include "SInvocationData.h"

class ZEvent0
{
public:
    TArray<TPair<int, ZDelegate<void __cdecl(void)>>> m_delegates;

    class SInvocationData
    {
    public:
      ZEvent0::SInvocationData * pNullOrDelegateAddedIndicator;
      unsigned int nRemoved;
      TList<TPair<int,ZDelegate<void __cdecl(void)>>> added;
    }* m_pInvocation;
};
