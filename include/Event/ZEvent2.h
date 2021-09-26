#pragma once

#include "TArray.h"
#include "TList.h"

template <class A, class B> class TPair;
template <class T> class alignas(8) ZDelegate;

template <class A, class B>
class ZEvent2
{
public:
	struct SInvocationData
	{
		SInvocationData* pNullOrDelegateAddedIndicator;
		unsigned int nRemoved;
		TList<TPair<int, ZDelegate<void __cdecl(A, B)>>> added;

		SInvocationData() = default;
		~SInvocationData() = default;
	};

	TArray<TPair<int, ZDelegate<void __cdecl(A, B)>>> m_delegates;
	SInvocationData* m_pInvocation;

	ZEvent2() = default;
	~ZEvent2() = default;
};
