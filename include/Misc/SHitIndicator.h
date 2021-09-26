#pragma once

#include "SVector3.h"

struct SHitIndicator
{
	SVector3 m_vProjectileStartPos;
	float m_fTime;

	SHitIndicator() = default;
	~SHitIndicator() = default;
	bool IsActive() const;
	float GetFraction() const;
};
