#pragma once

#include "ZString.h"

struct SRenderConstDesc
{
	unsigned int nType;
	unsigned int nOffset;
	unsigned int nSize;
	ZString Name;

	SRenderConstDesc(const SRenderConstDesc& __that);
	SRenderConstDesc() = default;
	~SRenderConstDesc() = default;
};
