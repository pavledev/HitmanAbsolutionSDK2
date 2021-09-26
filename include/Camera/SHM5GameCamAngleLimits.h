#pragma once

struct SHM5GameCamAngleLimits
{
	float m_fPitchAngleMax;
	float m_fPitchAngleMin;
	float m_fYawOffset;
	float m_fYawAngle;
	bool m_bEnableSmootingAtLimits;

	SHM5GameCamAngleLimits() = default;
	~SHM5GameCamAngleLimits() = default;
	void ClampAngles(float& fPitch, float& fYaw, float fYawBase) const;
	SHM5GameCamAngleLimits Blend(const SHM5GameCamAngleLimits& Dest, float fFraction) const;
};
