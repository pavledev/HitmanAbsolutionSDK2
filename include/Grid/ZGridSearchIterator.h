#pragma once

#include "float4.h"
#include "TArray.h"
#include "TQueue.h"
#include "ZBitArray.h"
#include "ZGridNodeRef.h"
#include "TBlockArray.h"

class ZGridSearchIterator
{
public:
	struct SSearchItem
	{
		ZGridNodeRef m_node;
		float m_fDistance;

		SSearchItem(const SSearchItem& __that);
		SSearchItem(const ZGridNodeRef& node, float fDist);
		SSearchItem& operator=(const SSearchItem& __that);
	};

	float4 m_vStartPos;
	TArray<float> m_aGridDistance;
	unsigned int m_nCurrentNodeIndex;
	TQueue<SSearchItem, TBlockArray<SSearchItem>> m_NodeQueue;
	ZBitArray m_Open;

	ZGridSearchIterator(const ZGridSearchIterator& __that);
	ZGridSearchIterator() = default;
	void Start(const float4& vStartPos, float fRadius);
	void Start(const ZGridNodeRef& rStart);
	bool IsDone() const;
	const SSearchItem& Current() const;
	void Add(const ZGridNodeRef& rNode, float fDistance);
	void Continue(bool bIncludeCurrentNeighbors, float fMultiplier);
	float GetCurrentEuclidianDistance() const;
	float GetCurrentGridDistance() const;
	void SetCurrentGridDistance(float fDist);
	~ZGridSearchIterator() = default;
	ZGridSearchIterator& operator=(const ZGridSearchIterator& __that);
};
