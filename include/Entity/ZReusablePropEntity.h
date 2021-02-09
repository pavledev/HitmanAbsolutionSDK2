#pragma once

#include "ZEntityImpl.h"
#include "IReusableProp.h"

class alignas(4) ZReusablePropEntity : public ZEntityImpl, public IReusableProp
{
public:
    bool m_bUsedOnce;
};
