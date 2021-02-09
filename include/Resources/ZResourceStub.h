#pragma once

#include "ZRuntimeResourceID.h"
#include "TArray.h"
#include "EResourceReferenceFlags.h"

class SResourceReference;
class ZResourcePtr;

class alignas(8) ZResourceStub
{
public:
    ZRuntimeResourceID m_ridResource;
    unsigned __int8 m_eResourceStatus;
    unsigned __int8 m_RequestedLoadStatus;
    __int16 m_nPriority;
    void* m_pResourceData;
    unsigned int m_nResourceTag;
    int m_nRef;
    int m_nHeaderRef;
    TArray<SResourceReference> m_resourceReferences;
    TArray<ZResourceStub*> m_backReferences;
    char gap2C[12];

    virtual ~ZResourceStub();
    virtual bool HasNewerVersion();
    virtual ZResourcePtr* GetNewestVersion(ZResourcePtr* result);
    virtual bool IsReloadable();
    virtual int GetMonitorID();
    virtual void SetMonitorID(int);
};