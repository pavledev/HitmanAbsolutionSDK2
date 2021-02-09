#pragma once

#include "TArray.h"
#include "SDialogInstanceData.h"
#include "EDialogGroupType.h"

class SDialogGroup
{
public:
    TArray<SDialogInstanceData*> m_pDialogs;
    EDialogGroupType m_eType;
    float m_fCooldown;
};
