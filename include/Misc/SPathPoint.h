#pragma once

#include "ZPF5Location.h"

struct SPathPoint
{
	ZPF5Location m_Location;
	SPathPoint* m_Prev;
	SPathPoint* m_Next;
	float m_fRemaining;
	int m_nCornerID;

	SPathPoint() = default;
	~SPathPoint() = default;
};
