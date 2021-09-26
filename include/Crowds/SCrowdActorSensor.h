#pragma once

#include "SVector2.h"

struct float4;

struct SCrowdActorSensor
{
	short m_aCurrentNeighbors[21];
	unsigned char m_nCurNumNeighbors;
	unsigned char m_nWorstThreat;
	float m_nTimeToCollision;
	float m_nDistanceToWall;
	SVector2 m_vWallNormal;
	float m_nObstacleDensity;

	static const unsigned char NEIGHBOR_BUFFER_SIZE;

	SCrowdActorSensor() = default;
	~SCrowdActorSensor() = default;
	float4 GetWallNormal() const;
};
