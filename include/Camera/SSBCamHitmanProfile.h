#pragma once

#include "ESBCamProfileBone.h"
#include "ESBPose.h"

struct float4;
struct SMatrix;

struct SSBCamHitmanProfile
{
	float m_fHeight;
	float m_fStickLength;
	float m_fRadius;
	float m_fFOV;
	float m_fRoll;
	float m_fYawAngle;
	float m_fPitchAngle;
	ESBCamProfileBone m_eBone;
	ESBPose m_ePose;

	SSBCamHitmanProfile() = default;
	~SSBCamHitmanProfile() = default;
	float4 CalculateCamPos(const float4& vFrom, const float4& vLookAtPoint, const bool bTargetView) const;
	float4 CalculateCamPosHitmanTargetView(const float4& vFrom, const float4& vLookAtPoint) const;
	SMatrix CalculateCamPosHitmanView(const float4& vFrom, const float4& vLookAtPoint) const;
	void CalculateHitmanTargetProfile(const float4& vPivot, const float4& vLookAtPoint, const SMatrix& mCam, float fFovY, ESBCamProfileBone eProfileBone, ESBPose eSBPose);
	void CalculateHitmanViewProfile(const float4& vPivot, const float4& vLookAtPoint, const SMatrix& mCam, float fFovY, ESBCamProfileBone eProfileBone, ESBPose eSBPose);
	SSBCamHitmanProfile operator+(const SSBCamHitmanProfile& rhs) const;
	SSBCamHitmanProfile operator*(float fScalar) const;
};
