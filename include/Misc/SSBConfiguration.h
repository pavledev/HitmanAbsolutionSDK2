#pragma once

struct SSBConfiguration
{
	float m_fDuration;
	float m_fEaseOutTime;
	float m_fStartMultiplier;
	float m_fEndMultiplier;

	SSBConfiguration() = default;
	~SSBConfiguration() = default;
	bool Update(float& fStateFraction, float& fTimeMultiplier, float fStateTime);
};
