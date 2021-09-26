#pragma once

#include "TArray.h"

struct STraversalSortedIndex;
class ZRenderGraphNode;
struct SRenderDrawFilterEntry;

struct SRenderGatherContext
{
	TArray<ZRenderGraphNode*> m_NodeLists[2];
	TArray<SRenderDrawFilterEntry> m_DrawLists[13];
	ZRenderGraphNode** m_pNodes[21];
	unsigned int m_nNumNodes[21];

	void Clear();
	void GatherTypeNodes(STraversalSortedIndex* pSortIndices, TArray<ZRenderGraphNode*>& VisibleNodes);
	SRenderGatherContext() = default;
	~SRenderGatherContext() = default;
};
