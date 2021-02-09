#pragma once

#include "ZEntityType.h"

class ZEntityImpl;

class ZEntityRef
{
public:
    ZEntityType** m_pEntityTypePtrPtr;

    bool operator!=(ZEntityRef* rhs);
    bool operator==(ZEntityRef* rhs);
    ZEntityType** QueryInterfacePtr(STypeID* interfaceID);
    static ZEntityRef* FromEntityTypePtrPtr(ZEntityRef* result, ZEntityType** pEntityTypePtrPtr);
    ZString* GetDebugNameScenePath(ZString* result);
    bool operator<(ZEntityRef* rhs);
    ZString* ToString(ZString* result);
    void RegisterForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback);
    bool IsNull();
    ZString* GetDebugName(ZString* result);
    //~ZEntityRef();
    static void RegisterType();
    ZEntityType** GetEntityTypePtrPtr();
    static ZEntityRef* FromTEntityRef(ZEntityRef* result, ZVariantRef entityRef);
    //ZEntityRef(ZEntityRef* rhs);
    ZEntityRef* operator=(ZEntityRef* rhs);
    unsigned int GetHashCode();
    ZEntityImpl* GetEntityImpl();
    unsigned int ToCString(char* pBuffer, unsigned int nSize, ZString* sFormat);
    //ZEntityRef();
    void UnregisterForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback);
    void FillSubsetArray(ZString* subsetName, TArray<ZEntityRef>* entities, bool bChildSet);
    bool IsRegisteredForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback);
    bool operator>(ZEntityRef* rhs);
};
