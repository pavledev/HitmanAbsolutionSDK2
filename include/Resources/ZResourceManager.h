#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "ZRuntimeResourceID.h"
#include "EResourceStatus.h"
#include "TSet.h"
#include "TMultiHashMap.h"
#include "TMap.h"
#include "ZMutex.h"
#include "TQueue.h"
#include "TBag.h"
#include "ZThreadEvent.h"
#include "THashMapIterator.h"
#include "EResourceLoadStatus.h"
#include "TArray.h"
#include "TBlockArray.h"
#include "ZDelegate.h"
#include "ZResourcePtr.h"
#include "ZString.h"
#include "ZVariantRef.h"

class IResourceInstaller;
class ZEventNull;
class ZResourcePending;
class ZResourceStub;
struct SComponentMapEntry;
struct STypeID;
template <class A, class B> class TDefaultHashMapPolicy;
template <class A, class B> class THashSet;
template <class T> class TArrayRef;
template <class T> class TDefaultHashSetPolicy;

class ZResourceManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct ZResourcePendingPriorityCmp
	{
	};

	struct SPendingLibraryLoad
	{
		ZResourcePtr pLibraryResource;
		long long nCreationTicks;

		SPendingLibraryLoad(const SPendingLibraryLoad& __that);
		SPendingLibraryLoad(ZResourcePtr pRes);
		~SPendingLibraryLoad() = default;
	};

	struct SQueuedChangeDelegate
	{
		ZRuntimeResourceID rid;
		ZDelegate<void __cdecl(ZRuntimeResourceID const&)> d;

		SQueuedChangeDelegate(const ZRuntimeResourceID& rid, const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
		bool operator<(const SQueuedChangeDelegate& rhs) const;
	};

	struct SMultiLanguageResourceInfo
	{
		ZResourceStub* pResourceStub;
		TArray<ZString> locales;
		TArray<int> indices;

		SMultiLanguageResourceInfo(const SMultiLanguageResourceInfo& __that);
		SMultiLanguageResourceInfo() = default;
		~SMultiLanguageResourceInfo() = default;
		SMultiLanguageResourceInfo& operator=(const SMultiLanguageResourceInfo& __that);
	};

	ZEvent<ZRuntimeResourceID const&, EResourceStatus, ZEventNull, ZEventNull, ZEventNull> m_AnyResourceStatusChangedEvent;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_FinishedLoadingEvent;
	TSet<ZResourceStub*> m_UnloadedLibraryResources;
	TArray<SPendingLibraryLoad> m_LibrariesToLoad;
	TMultiHashMap<ZRuntimeResourceID, ZResourceStub*, TDefaultHashMapPolicy<ZRuntimeResourceID, ZResourceStub*>> m_Resources;
	TMap<unsigned int, IResourceInstaller*> m_ResourceInstallers;
	ZMutex m_statusChangedTableMutex;
	ZMutex m_statusChangedCallbackBarrier;
	TMultiHashMap<ZRuntimeResourceID, ZDelegate<void __cdecl(ZRuntimeResourceID const&)>, TDefaultHashMapPolicy<ZRuntimeResourceID, ZDelegate<void __cdecl(ZRuntimeResourceID const&)>>> m_statusChangedTable;
	ZMutex m_queuedChangeEventsMutex;
	TSet<ZRuntimeResourceID> m_queuedChangeEvents;
	TSet<SQueuedChangeDelegate> m_queuedChangeDelegates;
	long m_nNumValid;
	long m_nNumHeaderLoaded;
	long m_nNumInstalling;
	long m_nNumInstallingTex;
	long m_nNumLoading;
	long m_nNumFailed;
	long m_nNumProcessing;
	long long m_nLoadTime;
	ZMutex m_IncomingResourcesMutex;
	TArray<ZResourcePending> m_IncomingResources;
	TQueue<ZResourcePending, TBlockArray<ZResourcePending>> m_InstallingLibraries;
	TBag<ZResourcePending, TArray<ZResourcePending>> m_InstallingResources;
	TBag<ZResourcePending, TArray<ZResourcePending>> m_WaitingResources;
	long m_nReleaseSuspendCount;
	TSet<ZResourceStub*> m_pendingUninstalls;
	TSet<ZResourceStub*> m_pendingDataReleases;
	long m_nLoadingMemoryUsed;
	ZThreadEvent m_nLoadingMemoryUsedReduced;
	unsigned int m_nMaxLoadingMemory;
	ZMutex m_ResourceManagerMutex;
	ZString m_sActiveLocaleName;
	ZString m_sActiveTextLocaleName;
	TMap<ZString, TArrayRef<ZResourceStub**>> m_GlobalResources;
	TArray<SMultiLanguageResourceInfo> m_multiLanguageResources;
	TArray<SMultiLanguageResourceInfo> m_multiLanguageTextResources;
	bool m_bResourceChangeReceived;
	TSet<ZRuntimeResourceID> m_ChangedResources;

	~ZResourceManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZResourceManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Activate();
	void Deactivate();
	IResourceInstaller* GetResourceInstaller(unsigned int nResourceType) const;
	bool IsResourceLoading();
	bool IsEmpty() const;
	ZResourcePtr GetResourcePtr(const ZRuntimeResourceID& ridResource, int nPriority);
	void GetResourcePtrs(const TArray<ZRuntimeResourceID>& ridResources, TArray<ZResourcePtr>& pResources, int nPriority);
	ZResourcePtr LoadResource(const ZRuntimeResourceID& ridResource);
	void HandleResourceChanged(const ZRuntimeResourceID& resourceID);
	void UpdateResourcePtr(ZResourcePtr& resource);
	void RegisterResourceInstaller(IResourceInstaller* pResourceInstaller, unsigned int nResourceType);
	void UnregisterResourceInstaller(IResourceInstaller* pResourceInstaller);
	void Update(bool bSendStatusChangedNotifications);
	void SendStatusChangedNotifications();
	void CheckIfDoneLoading();
	void Clear();
	void ReleaseUnusedResources();
	ZEvent<ZRuntimeResourceID const&, EResourceStatus, ZEventNull, ZEventNull, ZEventNull>& GetAnyResourceStatusChangedEvent();
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetFinishedLoadingEvent();
	void AddStatusChangedListener(const ZRuntimeResourceID& resourceID, const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void RemoveStatusChangedListener(const ZRuntimeResourceID& resourceID, const ZDelegate<void __cdecl(ZRuntimeResourceID const&)>& d);
	void ResourceStatusChanged(const ZRuntimeResourceID& ridResource, EResourceStatus oldStatus, EResourceStatus newStatus);
	void AddPendingResource(const ZResourcePending& resourcePending);
	void AddLibraryResource(const ZResourcePending& resourcePending);
	void ReleaseStub(ZResourceStub* stub);
	void RaisePriority(const ZRuntimeResourceID& resourceID, int nPriority);
	ZMutex& GetMutex() const;
	void WaitAndAddLoadingMemorySize(const unsigned int dataSize);
	bool TryAddLoadingMemorySize(unsigned int dataSize);
	void SubLoadingMemorySize(unsigned int dataSize);
	void GetAllReferences(ZResourcePtr pResource, THashSet<ZResourcePtr, TDefaultHashSetPolicy<ZResourcePtr>>& outReferences);
	void RegisterMultilanguageResource(const ZResourcePtr& pResource, bool bTextResource, TArray<ZString> locales, TArray<int> indices);
	void UnregisterMultilanguageResource(const ZRuntimeResourceID& rid, void* pResourceData);
	void SetActiveLocale(const ZString& sName);
	ZString GetActiveLocale() const;
	void SetActiveTextLocale(const ZString& sName);
	ZString GetActiveTextLocale() const;
	void SuspendReleasing();
	void ResumeReleasing();
	bool IsSuspended();
	unsigned int GetNumProcessing();
	bool DoneLoading() const;
	void Trim();
	void RegisterGlobalResources(const ZString& projectName, TArrayRef<ZResourceStub**> pResourceArray);
	void AssignGlobalResource(const ZString& projectName, int index, const ZResourcePtr& pResource);
	void ReleaseGlobalResources();
	void DumpResourceHolders();
	void UnloadLibraryResource(ZResourceStub* pStub);
	bool HasPendingResourceReleases();
	void RaiseResourceStatusChanged(const ZRuntimeResourceID& resourceID);
	void ReserveStubCapacity(int nNewStubCount);
	ZResourceStub* CreateLibraryResourceStub(const ZRuntimeResourceID& resourceID, int nPriority);
	ZResourceStub* GetResourceStub(const ZRuntimeResourceID& ridResource, int nPriority, EResourceLoadStatus requiredLoadStatus, bool& bOutStartLoading);
	ZResourceStub* TryFindResourceStub(const ZRuntimeResourceID& resourceID);
	THashMapIterator<ZRuntimeResourceID const, ZResourceStub*> FindResourceIterator(ZResourceStub* pResourceStub);
	void GatherDependentResources(const ZRuntimeResourceID& resourceID, TSet<ZRuntimeResourceID>& dependentSet, int nDepth);
	void ReloadResource(const ZRuntimeResourceID& resourceID);
	void PrintStatus();
	unsigned int NumPending();
	bool HasInstallDependencies(const ZResourcePending& pending);
	void UpdateWaitingResources();
	void UpdatePendingResources();
	void UpdateInstallingLibraries();
	void GetUnloadingLibraryResources(const ZRuntimeResourceID& ridLibrary, TArray<ZResourceStub*>& outResources);
	bool IsLibraryFullyReleased(const ZRuntimeResourceID& ridLibrary);
	void UpdateChangedResources();
	void UpdatePendingUninstalls();
	void CollectResourcesToUninstall();
	void UpdateMultilanguageResource(const SMultiLanguageResourceInfo& info, const ZString& localeName);
};
