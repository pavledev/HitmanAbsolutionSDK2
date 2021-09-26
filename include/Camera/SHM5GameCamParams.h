#pragma once

#include "SVector2.h"

struct SHM5GameCamParams
{
	float m_fHeight;
	float m_fStickLength;
	float m_fRadius;
	float m_fRadiusRight;
	float m_fRadiusLeft;
	float m_fFOV;
	float m_fFOVPrecisionShot;
	float m_fAngleRoll;
	float m_fYawBlendOutRadius;
	float m_fYawRotationOffsetY0;
	float m_fYawRotationOffsetY1;
	float m_fYawStickLengt0;
	float m_fYawStickLengt1;
	float m_fYawAnimationRange;
	float m_fFacingOffsetX;
	float m_fPitchAngle0;
	float m_fPitchAngle1;
	float m_fPitchHeight0;
	float m_fPitchHeight1;
	float m_fYawSpeed;
	float m_fPitchSpeed;
	float m_fYawSpeedFast;
	float m_fPitchSpeedFast;
	float m_fFastSpeedDelay;
	float m_fFastSpeedBlendInTime;
	float m_fTossHeight;
	float m_fCollisionHeight;
	float m_fSoftCollision;
	float m_fAimPushOut;
	SVector2 m_vCollisionPoint;
	SVector2 m_vRotationPoint;
	float m_fOTSFraction;

	SHM5GameCamParams() = default;
	~SHM5GameCamParams() = default;
	SHM5GameCamParams operator+(const SHM5GameCamParams& rhs) const;
	SHM5GameCamParams operator*(float fScalar) const;
};
