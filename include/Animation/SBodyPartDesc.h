#pragma once

#include "SMatrix43.h"
#include "SVector3.h"

struct SBodyPartDesc
{
	enum EShapeType
	{
		ESHAPETYPE_VOID = 0,
		ESHAPETYPE_SPHERE = 1,
		ESHAPETYPE_CAPSULE = 2,
		ESHAPETYPE_BOX = 3
	};

	unsigned int m_nID;
	SMatrix43 m_tTransform;
	EShapeType m_Type;
	float m_fRadius;
	SVector3 m_vExtents;
	SVector3 m_vOffset;
	float m_fFriction;
	float m_fMassPercentage;

	SBodyPartDesc() = default;
	~SBodyPartDesc() = default;
};
