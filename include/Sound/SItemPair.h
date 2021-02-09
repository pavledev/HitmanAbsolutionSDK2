#pragma once

#include "TEntityRef.h"
#include "ZSoundBlendItem.h"

class SItemPair
{
public:
    TEntityRef<ZSoundBlendItem> m_Item[2];
};
