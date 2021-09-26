#pragma once

#include "float4.h"

struct SShootTargetEntry
{
	float4 m_wsPosition;
	int m_nBoneID;
	float4 m_csPlaneOffset;
	bool m_bValid;

	SShootTargetEntry() = default;
	~SShootTargetEntry() = default;
};
