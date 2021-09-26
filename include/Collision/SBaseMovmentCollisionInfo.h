#pragma once

#include "SVector3.h"

struct SBaseMovmentCollisionInfo
{
	bool m_bBlocked;
	SVector3 m_vBlockingNormal;
	bool m_bExplicitBlockingNormal;
	bool m_bReleaseBlock;

	SBaseMovmentCollisionInfo() = default;
	~SBaseMovmentCollisionInfo() = default;
};
