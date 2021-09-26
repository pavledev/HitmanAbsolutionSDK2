#pragma once

#include "eNeigbourState.h"

class ZHM5CoverPlane;

struct sNeighbourInfo
{
	ZHM5CoverPlane* m_pNPlane;
	float m_fAngle;
	eNeigbourState m_NState;
	bool m_bConvex : 1;

	sNeighbourInfo() = default;
	~sNeighbourInfo() = default;
	void Reset();
};
