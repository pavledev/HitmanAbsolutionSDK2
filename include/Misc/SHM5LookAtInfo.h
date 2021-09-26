#pragma once

#include "float4.h"
#include "SMatrix.h"

struct SHM5LookAtInfo
{
	float4 m_vLookAtPos;
	SMatrix m_mRotationBase;
	float m_fBlendSpeedFactor;
	float m_fLookAtTargetWeight;
	float m_fLookAtWeight;
	float m_fPoseWeight;
	bool m_bPoseChanged;
	const float* m_pHorizontalWeights;
	const float* m_pVerticalWeights;

	static const unsigned int NUM_DEFAULT_LOOKAT_BONES;

	SHM5LookAtInfo() = default;
	~SHM5LookAtInfo() = default;
	void Reset();
};
