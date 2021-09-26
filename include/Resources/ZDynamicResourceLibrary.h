#pragma once

#include "ZRuntimeResourceID.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "TArray.h"
#include "ZEvent.h"

class ZEventNull;
class ZHeaderLibrary;
class ZResourceLibrarySet;
template <class T> class alignas(8) ZDelegate;

class ZDynamicResourceLibrary
{
public:
	ZRuntimeResourceID m_ridHeaderLibrary;
	ZResourceLibrarySet* m_pCurrentLibrarySet;
	TResourcePtr<ZHeaderLibrary> m_HeaderLibrary;
	ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_LibraryReadyEvent;
	TArray<ZEntityRef> m_Entities;
	const unsigned int m_iEntitiesNUM;
	bool m_bReady : 1;
	bool m_bFailed : 1;
	bool m_bLoadingHeader : 1;
	bool m_bDelayedCreateEntities : 1;

	ZDynamicResourceLibrary() = default;
	ZDynamicResourceLibrary(const ZDynamicResourceLibrary& __that);
	ZDynamicResourceLibrary(const ZRuntimeResourceID& ridHeaderLibrary, bool bDelayedCreateEntities, unsigned int nNumInstances);
	~ZDynamicResourceLibrary() = default;
	ZRuntimeResourceID GetLibraryResourceID();
	ZEntityRef GetEntity(int nIndex);
	void WaitForResources();
	bool IsReady();
	bool IsFailed();
	void DeleteAllEntities();
	unsigned int GetEntityCount() const;
	bool IsRegisteredForLibraryReadyEvent(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& fpCallback) const;
	void RegisterForLibraryReadyEvent(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& fpCallback);
	void UnregisterForLibraryReadyEvent(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& fpCallback);
	void ForceCreateEntities();
	void OnHeaderLibraryReady(const ZRuntimeResourceID& rid);
	void OnResourceLibrariesReady();
	void SetCurrentLibrarySet(ZResourceLibrarySet* pSet);
	void SetReady();
	void CreateEntities();
};
