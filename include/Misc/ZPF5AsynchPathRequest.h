#pragma once

#include "ZPF5Location.h"
#include "ZPathfinderSearchState.h"
#include "SSearchNode.h"
#include "TRefCountPtr.h"
#include "ZPF5Path.h"
#include "EPathRequestStatus.h"

class ZPF5AsynchPathRequest
{
    int m_nRefCount;
    bool m_bReady;
    alignas(16) ZPF5Location m_lFrom;
    ZPF5Location m_lTo;
    const SSearchNode* m_pSearchNode;
    TRefCountPtr<ZPF5Path> m_pathResult;
    unsigned int m_nNodeKeyTo;
    float m_fMaxCost;
    EPathRequestStatus m_ePathRequestStatus;
};
