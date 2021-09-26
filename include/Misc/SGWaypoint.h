#pragma once

#include "float4.h"

struct SGWaypoint
{
	union 
	{
		struct 
		{
			short nNeighbor0;
			short nNeighbor1;
			short nNeighbor2;
			short nNeighbor3;
			short nNeighbor4;
			short nNeighbor5;
			short nNeighbor6;
			short nNeighbor7;
		};

		short Neighbors[8];
	};

	float4 vPos;

	SGWaypoint() = default;
	~SGWaypoint() = default;
};
