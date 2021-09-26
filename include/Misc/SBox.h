#pragma once

#include "SMatrix.h"
#include "float4.h"

struct SBox
{
	SMatrix m_mvCenterMatPos;
	float4 m_vHalfSize;

	SBox(const SMatrix& mvCenterMatPos, const float4& vHalfSize);
	SBox() = default;
	~SBox() = default;
	void SetOBB(const SMatrix& mvCenterMatPos, const float4& vHalfSize);
};
