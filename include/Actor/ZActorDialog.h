#pragma once

#include "ZGameTime.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "ZActor.h"

class alignas(8) ZActorDialog
{
public:
    class SEntry
    {
    public:
        TEntityRef<ZActor> m_rActor;
        SActorSoundDefs::EDefinition m_eSound;

        class SCompareActor
        {
        public:
            TEntityRef<ZActor> m_rActor;
        };
    };

    int m_nRefCount;

    enum EState : __int32
    {
        PAUSE_BEFORE = 0x0,
        SPEAKING = 0x1,
        PAUSE_MIN_DURATION = 0x2,
        PAUSE_AFTER = 0x3,
        COMPLETED = 0x4,
    } m_state;

    int m_nCurrent;
    ZGameTime m_tStateTime;
    ZGameTime m_tCompletedTime;
    float m_fPauseBeforeOverride;
    TMaxArray<SEntry, 8> m_entries;
    bool m_bSuspendNextSpeak;
    bool m_bPauseBeforeOverride;
};
