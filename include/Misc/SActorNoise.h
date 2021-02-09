#pragma once

#include "SActorSoundDefs.h"
#include "EAIEventType.h"

struct SActorNoise
{
    SActorSoundDefs::EDefinition m_iSpeak;
    EAIEventType m_eAIEvent;
    float m_fAIEventDistance;
};
