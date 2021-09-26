#pragma once

#include "float4.h"
#include "SQuaternion.h"
#include "SMatrix.h"

class ZPolarAnimBlend;

struct SLedgeAimInfo
{
	bool m_bMirrorAim;
	float4 m_avAimPos[2];
	float4 m_avAimPosWindow[2];
	float4 m_vPelvisBindPosePos;
	SQuaternion m_vPelvisBindPoseRot;
	float m_afFractions[2];
	float m_afFractionsWindow[2];
	float m_afAnimFractionsWindow[2];
	SMatrix m_aHandAttacherToMuzzle[2];
	unsigned int m_anWindowAimPoses[2];
	ZPolarAnimBlend* m_pPolarAnimBlend[2];

	SLedgeAimInfo() = default;
	~SLedgeAimInfo() = default;
	void Reset();
};
