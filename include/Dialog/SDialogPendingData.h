#pragma once

#include "SDialogInstanceData.h"

class SDialogPendingData
{
public:
    SDialogInstanceData* m_pDialog;
    TEntityRef<ZActor> m_pSpeaker;
    TEntityRef<ZHM5BaseCharacter> m_pTarget;
    float m_fWeighting;
};
