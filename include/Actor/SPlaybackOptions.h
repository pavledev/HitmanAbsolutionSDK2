#pragma once

struct SPlaybackOptions
{
	float m_fDurationScale;
	float m_fMagnitudeScale;
	float m_fBlendInTime;
	float m_fBlendOutTime;
	float m_fStartDelay;

	SPlaybackOptions() = default;
	SPlaybackOptions(float fStartDelay, float fBlendInTime, float fBlendOutTime, float fDurationScale, float fMagnitudeScale);
	~SPlaybackOptions() = default;
};
