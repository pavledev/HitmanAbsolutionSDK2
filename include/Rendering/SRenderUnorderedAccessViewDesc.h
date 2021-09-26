#pragma once

#include "ERenderFormat.h"

struct SRenderUnorderedAccessViewDesc
{
	enum EViewDimension
	{
		UAV_DIMENSION_BUFFER = 1,
		UAV_DIMENSION_TEXTURE1D = 2,
		UAV_DIMENSION_TEXTURE1DARRAY = 3,
		UAV_DIMENSION_TEXTURE2D = 4,
		UAV_DIMENSION_TEXTURE2DARRAY = 5,
		UAV_DIMENSION_TEXTURE3D = 8
	};

	struct SUAVBuffer
	{
		unsigned int nFirstElement;
		unsigned int nNumElements;
		unsigned int nFlags;
	};

	struct SUAVTexture
	{
		unsigned int nMipSlice;
	};

	struct SUAVTextureArray
	{
		unsigned int nMipSlice;
		unsigned int nFirstArraySlice;
		unsigned int nArraySize;
	};

	struct SUAVTexture3D
	{
		unsigned int nMostDetailedMip;
		unsigned int nMipLevels;
	};

	ERenderFormat eFormat;
	EViewDimension eViewDimension;

	union 
	{
		SUAVBuffer UAVBuffer;
		SUAVTexture UAVTexture;
		SUAVTextureArray UAVTextureArray;
		SUAVTexture3D UAVTexture3D;
	};

	SRenderUnorderedAccessViewDesc() = default;
	~SRenderUnorderedAccessViewDesc() = default;
};
