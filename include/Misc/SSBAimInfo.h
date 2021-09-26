#pragma once

#include "float4.h"
#include "EAimMode.h"

struct SSBAimInfo
{
	unsigned int m_nAimPose;
	unsigned int m_nAimPoseGrips;
	float4 m_vAimPos;
	float m_fAimWeight;
	float m_fPoseWeight;
	bool m_bStorePose;
	EAimMode m_eAimMode;

	SSBAimInfo() = default;
	~SSBAimInfo() = default;
	void Reset();
};
