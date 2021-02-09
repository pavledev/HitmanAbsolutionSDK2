#pragma once

#include "TRefCountPtr.h"
#include "ZActorDialog.h"
#include "SSpeakEntry.h"
#include "SVoiceCooldownEntry.h"

class ZActorDialogManager
{
public:
    int m_nRandSeed;
    TRefCountPtr<ZActorDialog> m_pUpdatingDialog;
    TFixedArray<TRefCountPtr<ZActorDialog>, 5> m_tracks;
    TMaxArray<SSpeakEntry, 16> m_speaks;
    TMaxArray<SVoiceCooldownEntry, 32> m_voiceCooldowns;
};
