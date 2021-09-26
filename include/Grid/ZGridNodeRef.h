#pragma once

#include "float4.h"

struct SGWaypoint;

class ZGridNodeRef
{
public:
	class ZEnumerator;

	unsigned short m_nNodeIndex;
	const SGWaypoint* m_pNode;
	unsigned short m_nRoomID;

	ZGridNodeRef(unsigned short nNodeIndex);
	~ZGridNodeRef() = default;
	ZGridNodeRef(const ZGridNodeRef& other) = default;
	ZGridNodeRef() = default;
	ZGridNodeRef& operator=(const ZGridNodeRef& other);
	float4 GetWorldPosition() const;
	bool CheckVisibility(const ZGridNodeRef& pOther, bool bLow, bool bCheckDoors) const;
	const SGWaypoint* GetNode() const;
	bool IsValid() const;
	bool operator==(const ZGridNodeRef& other) const;
	bool operator!=(const ZGridNodeRef& other) const;
	operator unsigned int() const;
	ZEnumerator GetNeighborEnumerator() const;
	bool IsNeighbor(const ZGridNodeRef& node) const;
	unsigned int GetNeighborCount() const;
};
