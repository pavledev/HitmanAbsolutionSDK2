#pragma once

#include "float4.h"

struct SSoftCollisionCache
{
	float4 m_avSoftCollisions[16];
	int m_nNumSoftCollisions;
	bool m_bGotContactPoint;
	float4 m_vContactPoint;

	static const int NUM_SOFT_COLLISIONS;

	SSoftCollisionCache() = default;
	~SSoftCollisionCache() = default;
	void AddSoftCollision(const float4& vSoftCollision);
	void SetContactPoint(const float4& vContactPoint);
	void AddContactPoint();
	void ResetSoftCollisions();
	void ResetContactPoint();
	void Reset();
};
