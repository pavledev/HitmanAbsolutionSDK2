#pragma once

#include "TResourcePtr.h"

class ZAnimationResource;

struct SCutSequenceData
{
	TResourcePtr<ZAnimationResource> m_animResource;
	float m_fAnimationTime;
	float m_fCachedFrameWeight;
	bool m_bEnableAnimationScaling;

	SCutSequenceData(const SCutSequenceData& __that);
	SCutSequenceData(const TResourcePtr<ZAnimationResource>& animResource, float fAnimationTime);
	SCutSequenceData() = default;
	~SCutSequenceData() = default;
	SCutSequenceData& operator=(const SCutSequenceData& __that);
};
