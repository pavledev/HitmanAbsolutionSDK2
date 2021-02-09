#pragma once

#include "SDialogInstanceData.h"

class SDialogSlotData
{
public:
    SDialogInstanceData* m_pDialog;
    SDialogInstanceData* m_pResponseDialog;
    TEntityRef<ZActor> m_pSpeaker;
    TEntityRef<ZActor> m_pResponseSpeaker;
};
