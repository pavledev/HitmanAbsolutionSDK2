#pragma once

#include "SVector4.h"

struct SVertexW1Decal
{
	enum Offsets
	{
		OFFSET_POSITION = 0,
		OFFSET_NORMAL = 16,
		OFFSET_TANGENT = 20,
		OFFSET_BINORMAL = 24,
		OFFSET_TEXCOORD = 28
	};

	enum Formats
	{
		FORMAT_POSITION = 2,
		FORMAT_NORMAL = 28,
		FORMAT_TANGENT = 28,
		FORMAT_BINORMAL = 28,
		FORMAT_TEXCOORD = 37
	};

	SVector4 p;
	unsigned int n;
	unsigned int T;
	unsigned int B;
	short t[2];

	SVertexW1Decal() = default;
	~SVertexW1Decal() = default;
};
