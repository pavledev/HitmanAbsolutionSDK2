#pragma once

#include "ZSoundBlendSubtrackBase.h"

class ZSoundBlendItemSubtrack : public ZSoundBlendSubtrackBase
{
public:
    TArray<ZEntityRef> m_Items;
};
