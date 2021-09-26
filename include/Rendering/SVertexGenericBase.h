#pragma once

#include "SVector3.h"
#include "SVector2.h"

struct SVertexGenericBase
{
	enum Offsets
	{
		OFFSET_POSITION = 0,
		OFFSET_NORMAL = 12,
		OFFSET_TANGENT = 16,
		OFFSET_BINORMAL = 20,
		OFFSET_TEXCOORD0 = 24,
		OFFSET_COLOR = 32
	};

	enum Formats
	{
		FORMAT_POSITION = 6,
		FORMAT_NORMAL = 28,
		FORMAT_TANGENT = 28,
		FORMAT_BINORMAL = 28,
		FORMAT_TEXCOORD = 16,
		FORMAT_COLOR = 28
	};

	SVector3 p;
	unsigned int n;
	unsigned int T;
	unsigned int B;
	SVector2 t;
	unsigned int c;

	SVertexGenericBase() = default;
	~SVertexGenericBase() = default;
};
