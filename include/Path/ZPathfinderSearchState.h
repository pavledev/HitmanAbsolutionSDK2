#pragma once

#include "ZDelegate.h"
#include "ZPF5Location.h"
#include "TMaxArray.h"

class ZElementMarker;
struct float4;

class ZPathfinderSearchState
{
public:
	enum ESearchNodeType
	{
		KEY_TYPE_POLYGON_EDGE = 0,
		KEY_TYPE_FROM = 1,
		KEY_TYPE_TO = 2
	};

	struct SPriorityNode
	{
		int m_nPriority;
		int m_nSearchNodeID;
	};

	struct SSearchNode
	{
		unsigned int m_nNodeKey;
		unsigned short m_nPolygonID;
		unsigned short m_nPriorityNodeID;
		float m_fHeuristicCost;
		float m_fAccumulatedCost;
		const SSearchNode* m_pCameFrom;
	};

	ZDelegate<float __cdecl(float4 const&, float4 const&)> m_callback;
	unsigned short m_nPriorityNodeCount;
	unsigned int m_nSearchNodeCount;
	ZPF5Location m_lFrom;
	ZPF5Location m_lTo;
	ZElementMarker* m_pElementMarker;
	TMaxArray<SPriorityNode, 150> m_aPriorityNodes;
	TMaxArray<SSearchNode, 1500> m_aSearchNodes;

	static const int MAX_PRIORITY_NODES;
	static const int MAX_SEARCH_NODES;

	ZPathfinderSearchState() = default;
	void Init(ZElementMarker* pElementMarker);
	void Reset(const ZPF5Location& lFrom, const ZPF5Location& lTo);
	bool Full() const;
	~ZPathfinderSearchState() = default;
};
