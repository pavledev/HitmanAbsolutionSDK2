#pragma once

#include "SRenderTexture2DAccess.h"

struct SRenderTempTexture2DAccess : SRenderTexture2DAccess
{
	bool m_bTempAllocated;

	SRenderTempTexture2DAccess() = default;
	~SRenderTempTexture2DAccess() = default;
	void Allocate();
	void Free();
	bool GetIsTempAllocated() const;
};
