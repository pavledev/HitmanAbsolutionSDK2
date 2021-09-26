#pragma once

#include "float4.h"
#include "EAimMode.h"

struct SHM5AimInfo
{
	float m_fAimWeight;
	float m_fHandLayerWeight;
	float m_fArmLayerWeight;
	bool m_bRecalculateMuzzle;
	unsigned int m_nAimPoseHigh;
	unsigned int m_nAimPoseLow;
	const float* m_pHorizontalWeights;
	const float* m_pVerticalWeights;
	float4 m_vMuzzlePos;
	float4 m_vMuzzleDir;
	float4 m_vAimPos;
	float4 m_vAimPosHead;
	EAimMode m_eAimMode;
	float m_fPoseFraction;
	float m_fAttacherFraction;
	float m_fHeadFraction;
	bool m_bMirrorAim;
	bool m_bSwapLayerWeights;
	bool m_bClampedYawDir;
	bool m_bClampedPitchDir;
	bool m_bPoseChange;

	SHM5AimInfo() = default;
	~SHM5AimInfo() = default;
	void Reset();
};
