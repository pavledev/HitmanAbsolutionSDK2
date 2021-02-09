#pragma once

#include "TArray.h"
#include "ZRenderGraphNode.h"
#include "SRenderDrawFilterEntry.h"

class SRenderGatherContext
{
public:
    TArray<ZRenderGraphNode*> m_NodeLists[2];
    TArray<SRenderDrawFilterEntry> m_DrawLists[13];
    ZRenderGraphNode** m_pNodes[21];
    unsigned int m_nNumNodes[21];
};
