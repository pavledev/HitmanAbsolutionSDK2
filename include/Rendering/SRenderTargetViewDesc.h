#pragma once

#include "ERenderFormat.h"

struct SRenderTargetViewDesc
{
	enum EViewDimension
	{
		VIEW_DIMENSION_TEXTURE2D = 1,
		VIEW_DIMENSION_TEXTURE2DMS = 2,
		VIEW_DIMENSION_TEXTURE2DARRAY = 3,
		VIEW_DIMENSION_TEXTURE3D = 4
	};

	struct SViewTexture2D
	{
		unsigned int nMipSlice;
	};

	struct SViewTexture2DArray
	{
		unsigned int nMipSlice;
		unsigned int nFirstArraySlice;
		unsigned int nArraySize;
	};

	struct SViewTexture3D
	{
		unsigned int nMipSlice;
		unsigned int nFirstWSlice;
		unsigned int nWSize;
	};

	ERenderFormat eFormat;
	EViewDimension eViewDimension;

	union 
	{
		SViewTexture2D viewTexture2D;
		SViewTexture2DArray viewTexture2DArray;
		SViewTexture3D viewTexture3D;
	};

	SRenderTargetViewDesc() = default;
	~SRenderTargetViewDesc() = default;
};
