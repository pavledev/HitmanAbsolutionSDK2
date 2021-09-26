#pragma once

#include "float4.h"

struct SMatrix
{
	float4 mat[4];

	SMatrix(const float4& R0, const float4& R1, const float4& R2, const float4& R3);
	SMatrix() = default;
	~SMatrix() = default;
	const float4 XAxis() const;
	float4& XAxis();
	const float4 YAxis() const;
	float4& YAxis();
	const float4 ZAxis() const;
	float4& ZAxis();
	const float4 Trans() const;
	float4& Trans();
	const float4 operator[](int nSubscript) const;
	float4& operator[](int nSubscript);
	const float& r1c1() const;
	float& r1c1();
	float& r2c1();
	const float& r3c1() const;
	float& r3c1();
	float& r4c1();
	float& r1c2();
	const float& r2c2() const;
	float& r2c2();
	const float& r3c2() const;
	float& r3c2();
	float& r4c2();
	float& r1c3();
	float& r2c3();
	const float& r3c3() const;
	float& r3c3();
	const float& r4c3() const;
	float& r4c3();
	float& r1c4();
	float& r2c4();
	const float& r3c4() const;
	float& r3c4();
	const float& r4c4() const;
	float& r4c4();
};
