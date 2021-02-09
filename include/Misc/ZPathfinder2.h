#pragma once

#include "IComponentInterface.h"
#include "ZPathfinderSearchState.h"
#include "ZNavmesh.h"
#include "TQueue.h"
#include "TRefCountPtr.h"
#include "ZPF5AsynchPathRequest.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "ZPF5LineHitInfo.h"

class ZPathfinder2 : public IComponentInterface
{
public:
    alignas(16) ZPathfinderSearchState m_immediateSearchState;
    ZPathfinderSearchState m_persistentSearchState;
    ZElementMarker* m_pImmediateMarker;
    ZElementMarker* m_pPersistentMarker;
    ZNavmesh* m_pNavmesh;
    TQueue<TRefCountPtr<ZPF5AsynchPathRequest>, TMaxArray<TRefCountPtr<ZPF5AsynchPathRequest>, 64>> m_pathRequests;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_NavmeshChangedEvent;

    bool LineBlocked(ZPF5Location* lFrom, ZPF5Location* lTo);
    bool IsLineBlocked(ZPF5Location* lFrom, ZPF5Location* lTo);
    bool TraceLine(ZPF5Location* lFinal, ZPF5Location* lFrom, float4* vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned __int16 nAllowedRegionMask);
    bool TraceLineRobust(ZPF5Location* lFinal, ZPF5Location* lFrom, float4* vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned __int16 nAllowedRegionMask);
};
