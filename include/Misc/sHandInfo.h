#pragma once

#include "float4.h"
#include "SQuaternion.h"
#include "SQV.h"

struct sHandInfo
{
	bool m_bUpdated;
	float4 m_HandPos[2];
	SQuaternion m_HandMat[2];
	SQV m_HandModelMatPos[2];
	float m_fWeights[2];
	bool m_bUseHeadRealtive;
	bool m_bAllignClavicle[2];
	bool m_bDoNotReallignHand[2];

	sHandInfo() = default;
	~sHandInfo() = default;
};
