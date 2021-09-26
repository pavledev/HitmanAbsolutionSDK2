#pragma once

#include "TArray.h"
#include "THashMap.h"
#include "ZResourcePtr.h"

class ZResourceLibrarySet;
class ZEventNull;
class ZResourceLibraryInfo;
class ZResourceStub;
class ZRuntimeResourceID;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class A, class B> class TDefaultHashMapPolicy;
template <class T> class alignas(8) ZDelegate;

class ZHeaderLibrary
{
public:
	const TArray<ZResourceLibraryInfo*> m_LibraryLoadOrder;
	ZResourceStub* m_pHeaderLibraryStub;
	THashMap<ZRuntimeResourceID, ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>, TDefaultHashMapPolicy<ZRuntimeResourceID, ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>>> m_ResourceUnloadedEvents;

	ZHeaderLibrary() = default;
	ZHeaderLibrary(const ZHeaderLibrary& __that);
	ZHeaderLibrary(const TArray<ZResourceLibraryInfo*>& libraries, ZResourceStub* pHeaderLibrary);
	~ZHeaderLibrary() = default;
	ZResourceLibrarySet* CreateLibrarySet(int nStateIndex) const;
	TArray<ZRuntimeResourceID> GetLibraryIdsPresentIn(int nStateIndex) const;
	void CheckResourceLeaks(int nCurrentStateIndex) const;
	bool ContainsLibrary(const ZRuntimeResourceID& ridLibrary) const;
	ZResourcePtr GetSourceResource() const;
	ZResourcePtr GetHeaderLibResource() const;
	ZResourceLibraryInfo* GetLibraryInfo(const ZRuntimeResourceID& ridLibrary) const;
	void AddResourceUnloadedListener(const ZRuntimeResourceID& resourceID, const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void RemoveResourceUnloadedListener(const ZRuntimeResourceID& resourceID, const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void SendResourceUnloadedEvents(const ZRuntimeResourceID& ridLibrary);
};
