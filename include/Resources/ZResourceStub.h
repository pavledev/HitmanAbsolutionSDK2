#pragma once

#include "ZRuntimeResourceID.h"
#include "TArray.h"
#include "EResourceReferenceFlags.h"
#include "EResourceLoadStatus.h"
#include "ZResourcePtr.h"
#include "EResourceStatus.h"

class ZResourceHeaderReader;
class IResourceInstaller;
template <class A, class B> class THashSet;
template <class A, class B> class TPair;
template <class T> class TDefaultHashSetPolicy;
template <class T> class TSet;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) ZResourceStub
{
public:
	struct SResourceReference
	{
		EResourceReferenceFlags m_Flags;

		union 
		{
			ZResourceStub* m_pStub;
			ZRuntimeResourceID* m_pridMediaResource;
		};

		ZResourcePtr m_pResource;

		SResourceReference(const SResourceReference& __that);
		SResourceReference() = default;
		bool IsInstallDependency() const;
		bool IsMediaStreamed() const;
		bool IsCyclic() const;
		~SResourceReference() = default;
	};

	ZRuntimeResourceID m_ridResource;
	unsigned char m_eResourceStatus;
	unsigned char m_RequestedLoadStatus;
	short m_nPriority;
	void* m_pResourceData;
	unsigned int m_nResourceTag;
	long m_nRef;
	long m_nHeaderRef;
	TArray<SResourceReference> m_resourceReferences;
	TArray<ZResourceStub*> m_backReferences;

	virtual ~ZResourceStub() = default;
	virtual bool HasNewerVersion() const = 0;
	virtual ZResourcePtr GetNewestVersion() const = 0;
	virtual bool IsReloadable() const = 0;
	virtual int GetMonitorID() const = 0;
	virtual void SetMonitorID(int param1) = 0;

	ZResourceStub() = default;
	ZResourceStub(const ZResourceStub& __that);
	ZResourceStub(const ZRuntimeResourceID& ResourceID, int nInitialPriority);
	void ReleaseResourceData();
	EResourceStatus GetResourceStatus() const;
	const ZRuntimeResourceID& GetRuntimeResourceID() const;
	void* GetResourceData() const;
	unsigned int GetResourceTag() const;
	IResourceInstaller* GetResourceInstaller() const;
	void AddRef();
	void Release();
	void AddRefInternal();
	void ReleaseInternal();
	void AddRefHeader();
	void ReleaseHeader();
	void AddStatusChangedListener(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void RemoveStatusChangedListener(const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void SetResourceStatus(EResourceStatus eResourceStatus);
	void SetResourceData(void* pResourceData);
	void ReplaceResourceData(void* pResourceData);
	void SetResourceTag(unsigned int nResourceTag);
	unsigned int GetHeaderRefCount() const;
	unsigned int GetRefCount() const;
	int GetPriority();
	void RaisePriority(int nPriority);
	bool HasHeaderResourceReferences();
	void AcquireHeaderResourceReferences(const ZResourceHeaderReader& header);
	void RebindHeaderResourceReferences();
	void AcquireResourceReferences();
	void ReleaseResourceReferences(bool bReleaseDependencies);
	EResourceStatus GetInstallTimeDependenciesStatus() const;
	TArray<TPair<ZRuntimeResourceID, EResourceStatus>> GetInstallTimeDependencies() const;
	bool HasInstallTimeDependency(const ZRuntimeResourceID& resourceID) const;
	ZResourcePtr GetInstallDependency(unsigned int nIndex) const;
	int GetResourceReferenceCount() const;
	ZRuntimeResourceID GetResourceReferenceID(int index) const;
	EResourceReferenceFlags GetResourceReferenceFlags(int idx) const;
	EResourceLoadStatus GetRequestedLoadStatus() const;
	void SetRequestedLoadStatus(EResourceLoadStatus newStatus);
	bool AreAllReferencesLoaded(THashSet<ZResourceStub const*, TDefaultHashSetPolicy<ZResourceStub const*>>& visited) const;
	void GetAllReferences(TSet<ZResourceStub*>& references) const;
	void GetBackReferences(TArray<ZResourceStub*>& references) const;
	void RemoveBackReferences();
	bool IsCyclicReference(ZResourceStub* pStub);
	ZResourceStub& operator=(const ZResourceStub& __that);
};
