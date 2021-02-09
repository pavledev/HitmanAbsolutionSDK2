#pragma once

#include "ZRuntimeResourceID.h"
#include "ZResourceLibrarySet.h"
#include "TResourcePtr.h"
#include "ZHeaderLibrary.h"
#include "ZEntityRef.h"

class alignas(4) ZDynamicResourceLibrary
{
    ZRuntimeResourceID m_ridHeaderLibrary;
    ZResourceLibrarySet* m_pCurrentLibrarySet;
    TResourcePtr<ZHeaderLibrary> m_HeaderLibrary;
    ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_LibraryReadyEvent;
    TArray<ZEntityRef> m_Entities;
    const unsigned int m_iEntitiesNUM;
    __int8 m_bReady : 1;
    __int8 m_bFailed : 1;
    __int8 m_bLoadingHeader : 1;
    __int8 m_bDelayedCreateEntities : 1;
};
