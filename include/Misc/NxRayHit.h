#pragma once

#include <NxScene.h>

struct NxRayHit
{
	NxShape* m_pShape;
	float m_nT;
	NxVec3 m_vPosition;
	NxVec3 m_vNormal;

	NxRayHit() = default;
	~NxRayHit() = default;
	NxRayHit(const NxRayHit& __that);
	static int SortCompare(const void* pA, const void* pB);
};
