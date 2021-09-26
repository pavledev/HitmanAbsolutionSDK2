#pragma once

#include "SVector3.h"

struct SVertexDecal
{
	enum Offsets
	{
		OFFSET_POSITION = 0,
		OFFSET_NORMAL = 12,
		OFFSET_TANGENT = 16,
		OFFSET_BINORMAL = 20,
		OFFSET_TEXCOORD0 = 24
	};

	enum Formats
	{
		FORMAT_POSITION = 6,
		FORMAT_NORMAL = 28,
		FORMAT_TANGENT = 28,
		FORMAT_BINORMAL = 28,
		FORMAT_TEXCOORD = 37
	};

	SVector3 p;
	unsigned int n;
	unsigned int T;
	unsigned int B;
	short t[2];

	SVertexDecal() = default;
	~SVertexDecal() = default;
};
