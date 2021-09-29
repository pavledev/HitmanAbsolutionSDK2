#pragma once

#include <xmmintrin.h>
#include "SVector3.h"

struct float1;

struct float4
{
	__m128 m;

	float4() = default;
	~float4() = default;
	float1 X() const;
	float1 Y() const;
	float1 Z() const;
	float1 W() const;
	float4 SetX(const float1& s) const;
	float4 SetY(const float1& s) const;
	float4 SetZ(const float1& s) const;
	float1 Dot2(const float4& v) const;
	float1 Dot3(const float4& v) const;
	float4 Cross(const float4& v) const;
	float4 Normalize2() const;
	float4 Normalize3() const;
	float4 Normalize3Checked() const;
	float1 Length2() const;
	float1 Length3() const;
	float1 LengthSq2() const;
	float1 LengthSq3() const;
	static float4 Zero();
	static float4 UnitZ();
	const float& x() const;
	float& x();
	const float& y() const;
	float& y();
	const float& z() const;
	float& z();
	const float& w() const;
	float& w();
	const float& operator[](int nSubscript) const;
	float& operator[](int nSubscript);

	float4 operator+(float4 f);
	float4 operator-(float4 f);
	float4(float x, float y, float z, float w);
	float4(SVector3 vector);
};
