#pragma once

#include "TArray.h"
#include "TList.h"
#include "TListIterator.h"
#include "TArrayIterator.h"

template <class A, class B> class TPair;
template <class T> class alignas(8) ZDelegate;

class ZEvent0
{
public:
	struct SInvocationData
	{
		SInvocationData* pNullOrDelegateAddedIndicator;
		unsigned int nRemoved;
		TList<TPair<int, ZDelegate<void __cdecl(void)>>> added;

		SInvocationData() = default;
		~SInvocationData() = default;
	};

	TArray<TPair<int, ZDelegate<void __cdecl(void)>>> m_delegates;
	SInvocationData* m_pInvocation;

	ZEvent0(const ZEvent0& __that);
	ZEvent0() = default;
	void operator()() const;
	void operator+=(const ZDelegate<void __cdecl(void)>& d);
	void operator-=(const ZDelegate<void __cdecl(void)>& d);
	bool Contains(const ZDelegate<void __cdecl(void)>& d) const;
	bool IsEmpty() const;
	void Add(const ZDelegate<void __cdecl(void)>& d, int priority);
	void Remove(const ZDelegate<void __cdecl(void)>& d);
	void InvokeAll() const;
	static int CompareContainedTypes(const void* pA, const void* pB);
	static TListIterator<TPair<int, ZDelegate<void __cdecl(void)>>> Find(TList<TPair<int, ZDelegate<void __cdecl(void)>>>& container, const ZDelegate<void __cdecl(void)>& d);
	static TArrayIterator<TPair<int, ZDelegate<void __cdecl(void)>>> Find(TArray<TPair<int, ZDelegate<void __cdecl(void)>>>& container, const ZDelegate<void __cdecl(void)>& d);
	static TArrayIterator<TPair<int, ZDelegate<void __cdecl(void)>> const> Find(const TArray<TPair<int, ZDelegate<void __cdecl(void)>>>& container, const ZDelegate<void __cdecl(void)>& d);
	static bool IsSet(const SInvocationData* pInvocation);
	~ZEvent0() = default;
	ZEvent0& operator=(const ZEvent0& __that);
};
