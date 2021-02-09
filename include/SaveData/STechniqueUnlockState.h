#pragma once

#include "STokenID.h"
#include "HMTechniques.h"

class STechniqueUnlockState
{
public:
    STokenID m_CheckpointTokenID;
    HMTechniques::ETechnique m_eTechnique;
    int m_iLevel;
};
