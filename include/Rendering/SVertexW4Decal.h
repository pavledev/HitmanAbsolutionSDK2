#pragma once

#include "SVector3.h"

struct SVertexW4Decal
{
	enum Offsets
	{
		OFFSET_POSITION = 0,
		OFFSET_BLENDWEIGHT = 12,
		OFFSET_BLENDINDICES = 16,
		OFFSET_NORMAL = 20,
		OFFSET_TANGENT = 24,
		OFFSET_BINORMAL = 28,
		OFFSET_TEXCOORD = 32
	};

	enum Formats
	{
		FORMAT_POSITION = 6,
		FORMAT_BLENDWEIGHT = 28,
		FORMAT_BLENDINDICES = 30,
		FORMAT_NORMAL = 28,
		FORMAT_TANGENT = 28,
		FORMAT_BINORMAL = 28,
		FORMAT_TEXCOORD = 37
	};

	SVector3 p;
	unsigned int w;
	unsigned int m;
	unsigned int n;
	unsigned int T;
	unsigned int B;
	short t[2];

	SVertexW4Decal() = default;
	~SVertexW4Decal() = default;
};
