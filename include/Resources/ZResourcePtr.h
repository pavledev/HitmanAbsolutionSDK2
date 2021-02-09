#pragma once

#include "ZResourceStub.h"
#include "EResourceStatus.h"
#include "IResourceInstaller.h"
#include "THashSet.h"
#include "TDefaultHashSetPolicy.h"
#include "ZDelegate.h"

class ZResourcePtr
{
public:
    ZResourceStub* m_pResourceStub;

    EResourceStatus GetResourceStatus();
    void ReleaseStub(ZResourceStub* pStub);
    unsigned int GetHashCode();
    bool AreAllReferencesLoaded();
    ZResourcePtr(ZResourcePtr* rhs);
    void SetResourceStatus(EResourceStatus eStatus);
    bool Failed();
    bool HasNewerVersion();
    void* GetInstallingRawPointer();
    ZResourcePtr();
    IResourceInstaller* GetResourceInstaller();
    bool Exists();
    static bool IsLeakTrackingEnabled();
    bool Rebind();
    bool AreAllReferencesLoaded(THashSet<ZResourceStub*, TDefaultHashSetPolicy<ZResourceStub*> >* visitedStubs);
    bool operator>(ZResourcePtr* rhs);
    ZResourcePtr(ZResourceStub* pResourceHeader);
    ZRuntimeResourceID* GetRuntimeResourceID(ZRuntimeResourceID* result);
    void AddRefStub(ZResourceStub* pStub);
    void RemoveStatusChangedListener(ZDelegate<void __cdecl(ZRuntimeResourceID&)>* d);
    unsigned int GetResourceTag();
    void SetResourceData(void* pResourceData);
    bool IsReady();
    ZResourcePtr(ZRuntimeResourceID* rid);
    ~ZResourcePtr();
    ZResourcePtr* GetNewestVersion(ZResourcePtr* result);
    bool operator==(ZResourcePtr* rhs);
    bool RebindEvenIfNotReady();
    ZResourceStub* GetResourceStub();
    ZResourcePtr* operator=(ZResourcePtr* rhs);
    static void SetLeakTrackingEnabled(bool bEnabled);
    void* GetRawPointer();
    bool operator<(ZResourcePtr* rhs);
    void Release();
    bool operator!=(ZResourcePtr* rhs);
    void AddStatusChangedListener(ZDelegate<void __cdecl(ZRuntimeResourceID&)>* d);
};
