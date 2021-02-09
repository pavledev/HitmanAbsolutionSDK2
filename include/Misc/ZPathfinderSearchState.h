#pragma once

#include "ZDelegate.h"
#include "float4.h"
#include "ZPF5Location.h"
#include "ZElementMarker.h"
#include "TMaxArray.h"
#include "SPriorityNode.h"
#include "SSearchNode.h"

class alignas(16) ZPathfinderSearchState
{
public:
    ZDelegate<float __cdecl(float4 const&, float4 const&)> m_callback;
    alignas(8) unsigned __int16 m_nPriorityNodeCount;
    unsigned int m_nSearchNodeCount;
    ZPF5Location m_lFrom;
    ZPF5Location m_lTo;
    ZElementMarker* m_pElementMarker;
    TMaxArray<SPriorityNode, 150> m_aPriorityNodes;
    TMaxArray<SSearchNode, 1500> m_aSearchNodes;
};
