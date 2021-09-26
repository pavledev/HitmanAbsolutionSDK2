#pragma once

#include "ZMutex.h"
#include "TArray.h"
#include "ZResourcePtr.h"

class ZRuntimeResourceID;
template <class T> class alignas(8) ZDelegate;

class ZResourceLibrarySet
{
public:
	ZMutex m_Mutex;
	ZMutex m_ExecutingCallbackMutex;
	TArray<ZResourcePtr> m_Libraries;
	TArray<ZDelegate<void __cdecl(void)>> m_Callbacks;
	ZResourcePtr m_pHeaderLibrary;
	bool m_bReleased : 1;
	bool m_bProcessingCallbacks : 1;

	ZResourceLibrarySet(TArray<ZRuntimeResourceID>& ids, ZResourcePtr pHeaderLibrary);
	ZResourceLibrarySet() = default;
	~ZResourceLibrarySet() = default;
	void AddReadyCallback(const ZDelegate<void __cdecl(void)>& d);
	void RemoveReadyCallback(const ZDelegate<void __cdecl(void)>& d);
	bool IsFailed() const;
	bool IsReady() const;
	void Release();
	void GetRuntimeResourceIDs(TArray<ZRuntimeResourceID>& ids) const;
	ZResourcePtr GetHeaderLibrary() const;
	void OnStatusChanged(const ZRuntimeResourceID& rid);
};
