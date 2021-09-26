#pragma once

#include "ERenderQueryType.h"

struct SRenderQueryDesc
{
	ERenderQueryType eQueryType;
	unsigned int nMiscFlags;

	SRenderQueryDesc() = default;
	~SRenderQueryDesc() = default;
};
