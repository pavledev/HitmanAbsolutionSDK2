#pragma once

#include "float4.h"

struct SQuaternion
{
	enum
	{
		X = 0,
		Y = 1,
		Z = 2,
		W = 3
	};

	float4 w128;

	SQuaternion() = default;
	~SQuaternion() = default;
	bool IsNearEqual(const SQuaternion& rhs, const float fTolerance) const;
	const float& x() const;
	float& x();
	const float& y() const;
	float& y();
	const float& z() const;
	float& z();
	const float& w() const;
	float& w();
	float& operator[](int nSubscript);
};
