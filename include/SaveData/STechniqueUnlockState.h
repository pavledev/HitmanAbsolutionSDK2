#pragma once

#include "STokenID.h"
#include "HMTechniques.h"

struct STechniqueUnlockState
{
	STokenID m_CheckpointTokenID;
	HMTechniques::ETechnique m_eTechnique;
	int m_iLevel;

	STechniqueUnlockState(STokenID token, HMTechniques::ETechnique techn, int level);
	STechniqueUnlockState() = default;
	~STechniqueUnlockState() = default;
};
