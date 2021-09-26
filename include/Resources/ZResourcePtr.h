#pragma once

#include "EResourceStatus.h"
#include "ZRuntimeResourceID.h"

class ZResourceStub;
class IResourceInstaller;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;
template <class T> class alignas(8) ZDelegate;

class ZResourcePtr
{
public:
	struct ZNull
	{
	};

	ZResourceStub* m_pResourceStub;

	static bool m_bLeakTrackingEnabled;

	ZResourcePtr(const ZRuntimeResourceID& rid);
	ZResourcePtr(ZResourceStub* pResourceHeader);
	ZResourcePtr(const ZResourcePtr& rhs);
	ZResourcePtr() = default;
	~ZResourcePtr() = default;
	ZResourcePtr& operator=(ZNull* __formal);
	ZResourcePtr& operator=(const ZResourcePtr& rhs);
	bool operator==(const ZResourcePtr& rhs) const;
	bool operator==(ZNull* __formal) const;
	bool operator!=(const ZResourcePtr& rhs) const;
	bool operator!=(ZNull* __formal) const;
	void Release();
	ZRuntimeResourceID GetRuntimeResourceID() const;
	bool IsReady() const;
	bool Exists() const;
	bool Failed() const;
	ZResourcePtr GetNewestVersion() const;
	bool HasNewerVersion() const;
	bool Rebind();
	bool RebindEvenIfNotReady();
	unsigned int GetResourceTag() const;
	ZResourceStub* GetResourceStub() const;
	void AddStatusChangedListener(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void RemoveStatusChangedListener(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void SetResourceStatus(EResourceStatus eStatus);
	bool AreAllReferencesLoaded(THashSet<ZResourceStub const*, TDefaultHashSetPolicy<ZResourceStub const*>>& visitedStubs) const;
	bool AreAllReferencesLoaded() const;
	bool operator<(const ZResourcePtr& rhs) const;
	bool operator>(const ZResourcePtr& rhs) const;
	void SetResourceData(void* pResourceData);
	void* GetRawPointer() const;
	void* GetInstallingRawPointer() const;
	unsigned int GetHashCode() const;
	static bool IsLeakTrackingEnabled();
	static void SetLeakTrackingEnabled(bool bEnabled);
	void AddRefStub(ZResourceStub* pStub);
	void ReleaseStub(ZResourceStub* pStub);
	EResourceStatus GetResourceStatus() const;
	IResourceInstaller* GetResourceInstaller() const;
};
