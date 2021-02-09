#pragma once

#include "TArray.h"
#include "ZResourceLibraryInfo.h"
#include "THashMap.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "TDefaultHashMapPolicy.h"

class ZHeaderLibrary
{
public:
    const TArray<ZResourceLibraryInfo*> m_LibraryLoadOrder;
    ZResourceStub* m_pHeaderLibraryStub;
    THashMap<ZRuntimeResourceID, ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>, TDefaultHashMapPolicy<ZRuntimeResourceID, ZEvent<ZRuntimeResourceID const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>>> m_ResourceUnloadedEvents;
};
