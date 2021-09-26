#pragma once

#include "SRenderRect.h"

struct SMatrix;

struct SRenderDisplayMode
{
	bool bFullScreen;
	bool bExclusiveFullScreen;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int nRefreshRate;
	bool bIsMultiMonitorMode;
	SRenderRect PrimaryRect;
	SRenderRect PrimaryRect16x9Ingame;
	SRenderRect PrimaryRectUi;
	unsigned int nGridWidth;
	unsigned int nGridHeight;

	SRenderDisplayMode() = default;
	~SRenderDisplayMode() = default;
	unsigned int PrimWidth() const;
	unsigned int PrimHeight() const;
	void AdjustProjectionForEyefinity(SMatrix& projection) const;
};
