#pragma once

#include "float4.h"

class ZSplineKnot
{
public:
	float4 m_vPosition;
	float4 m_vTangent[2];

	ZSplineKnot() = default;
	~ZSplineKnot() = default;
	void SetPosition(const float4& p0);
	const float4& GetPosition() const;
	void SetTangent(unsigned int iIdx, const float4& v0);
	const float4& GetTangent(unsigned int iIdx);
};
