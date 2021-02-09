#pragma once

#include "SItemPair.h"
#include "ZSoundBlendItemInstance.h"

class ZSoundBlendItemManager
{
public:
    SItemPair m_CurrentItems;
    ZSoundBlendItemInstance* m_pInstances[2];
    unsigned int m_nNextSlot;
};
