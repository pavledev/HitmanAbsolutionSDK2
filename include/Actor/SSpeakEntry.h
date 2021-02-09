#pragma once

#include "ESpeakStatus.h"
#include "SActorSoundDefs.h"
#include "EAIEventType.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "ZActorDialog.h"

class SSpeakEntry
{
public:
    ESpeakStatus m_status;
    SActorSoundDefs::EDefinition m_eSound;
    EAIEventType m_eAIEvent;
    TEntityRef<ZActor> m_rActor;
    TRefCountPtr<ZActorDialog> m_pDialog;
    ZGameTime m_tStarted;
    ZGameTime m_tEnded;
};
