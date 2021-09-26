#pragma once

#include "SQV.h"
#include "float4.h"

struct sLedgeHangBoneBuffer
{
	bool m_bValid;
	SQV m_Bones[13];
	int m_nBoneIds[13];
	float4 m_vPelvisPushDir;

	sLedgeHangBoneBuffer() = default;
	~sLedgeHangBoneBuffer() = default;
	void Reset();
};
