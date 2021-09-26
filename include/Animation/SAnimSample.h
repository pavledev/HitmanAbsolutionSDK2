#pragma once

#include "float4.h"

struct SAnimSample
{
	unsigned int m_iNumPoints;
	unsigned int m_iNumSamples;
	float4 m_avPoints[64];
	bool m_abOwnPoint[64];

	static const int MAX_NUM_ANIM_SAMPLE_POINTS;

	SAnimSample() = default;
	~SAnimSample() = default;
	void AddPoint(const float4& vPoint);
	void Clear();
	unsigned int GetPointsPerSample() const;
};
