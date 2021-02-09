#pragma once

#include "TArray.h"
#include "SDialogInstanceData.h"
#include "SDialogGroup.h"
#include "SDialogPendingData.h"
#include "SDialogSlotData.h"

class ZCombatDialogManagerInternal
{
public:
    TArray<SDialogInstanceData> m_aDialogs;
    TArray<SDialogGroup> m_aDialogGroups;
    TMaxArray<SDialogPendingData, 1> m_aDialogsPending;
    TMaxArray<SDialogSlotData, 1> m_aDialogSlots;
    ZProtoCombatSituation* m_pCombatSituation;
};
