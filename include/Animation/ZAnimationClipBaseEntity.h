#pragma once

#include "ZEntityImpl.h"

class alignas(4) ZAnimationClipBaseEntity : public ZEntityImpl
{
public:
    bool m_bStreamedIn;
};
