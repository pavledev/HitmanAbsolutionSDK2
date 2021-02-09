#pragma once

#include "SActorSoundDefs.h"
#include "ZGameTime.h"

class SVoiceCooldownEntry
{
public:
    SActorSoundDefs::EDefinition m_eSound;
    ZGameTime m_tEnd;
};
