#pragma once

#include "SDialogDescData.h"

class alignas(8) SDialogInstanceData
{
public:
    SDialogDescData* m_pData;
    TEntityRef<ZActor> m_pLastSpeaker;
    ZGameTime m_cooldownTime;
    ZGameTime m_spokenEndTime;
    unsigned __int8 m_secPriority;
    bool m_bPreventLastSpeaker;
    bool m_bSharedCooldownGroup;
    bool m_bResponseGroup;
    bool m_bPlaying;
};
