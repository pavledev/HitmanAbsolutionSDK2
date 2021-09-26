#pragma once

struct SHM5GameCamAngles
{
	float m_fPitchAngle;
	float m_fYawAngle;

	SHM5GameCamAngles() = default;
	~SHM5GameCamAngles() = default;
	SHM5GameCamAngles Blend(const SHM5GameCamAngles& sSource, float fFraction) const;
};
