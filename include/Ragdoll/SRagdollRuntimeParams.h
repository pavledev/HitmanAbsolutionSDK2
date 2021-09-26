#pragma once

#include "ECCDUsage.h"
#include "ECollisionPriority.h"

struct SRagdollRuntimeParams
{
	bool m_bCreateTargetDummies;
	ECCDUsage m_eCCDUsage;
	ECollisionPriority m_eSolverPriority;
	float m_fRagdollScale;

	SRagdollRuntimeParams() = default;
	~SRagdollRuntimeParams() = default;
};
