#pragma once

#include "float4.h"

struct float1
{
	float4 m4;

	float1(float f);
	float1() = default;
	~float1() = default;
	float ToFloat() const;
	float1& operator=(float f);
	float1& operator=(const float1& rhs);
	static float1 FromReplicated(const float4& f4);
};
