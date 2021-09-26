#pragma once

#include "TArray.h"

struct SVector3;

struct SBoneScalesList
{
	TArray<SVector3> m_aBoneScales;

	SBoneScalesList(const SBoneScalesList& __that);
	SBoneScalesList() = default;
	~SBoneScalesList() = default;
	SBoneScalesList& operator=(const SBoneScalesList& __that);
};
