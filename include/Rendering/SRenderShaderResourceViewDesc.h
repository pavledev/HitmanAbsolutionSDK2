#pragma once

#include "ERenderFormat.h"
#include "ERenderResourceMipInterpolation.h"

struct SRenderShaderResourceViewDesc
{
	enum EViewDimension
	{
		VIEW_DIMENSION_TEXTURE2D = 1,
		VIEW_DIMENSION_TEXTURE2DMS = 2,
		VIEW_DIMENSION_TEXTURE2DARRAY = 3,
		VIEW_DIMENSION_TEXTURE3D = 4,
		VIEW_DIMENSION_TEXTURECUBE = 5
	};

	struct SViewTexture2D
	{
		unsigned int nMostDetailedMip;
		unsigned int nMipLevels;
	};

	struct SViewTexture2DArray
	{
		unsigned int nMostDetailedMip;
		unsigned int nMipLevels;
		unsigned int nFirstArraySlice;
		unsigned int nArraySize;
	};

	struct SViewTexture3D
	{
		unsigned int nMostDetailedMip;
		unsigned int nMipLevels;
	};

	struct SViewTextureCube
	{
		unsigned int nMostDetailedMip;
		unsigned int nMipLevels;
	};

	ERenderFormat eFormat;
	EViewDimension eViewDimension;
	ERenderResourceMipInterpolation eMipInterpolation;

	union 
	{
		SViewTexture2D viewTexture2D;
		SViewTexture2DArray viewTexture2DArray;
		SViewTexture3D viewTexture3D;
		SViewTextureCube viewTextureCube;
	};

	SRenderShaderResourceViewDesc() = default;
	~SRenderShaderResourceViewDesc() = default;
};
