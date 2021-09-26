#pragma once

#include "SVector3.h"

struct SPathCorner
{
	SVector3 m_vPos;
	float m_fAngle;

	SPathCorner() = default;
	~SPathCorner() = default;
};
