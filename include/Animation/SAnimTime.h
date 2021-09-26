#pragma once

struct SAnimTime
{
	float m_fDuration;
	float m_fTime;
	float m_fCurrentFrac;
	float m_fLastFrac;

	SAnimTime() = default;
	~SAnimTime() = default;
	void Update(float fDeltaTime);
	void ForceTime(float fTime);
	void Reset();
};
