#pragma once

#include "ZHM5ValueReceiver_Base.h"
#include "TEntityRef.h"

class alignas(4) ZHM5ValueReceiver_float32 : public ZHM5ValueReceiver_Base
{
public:
    TEntityRef<ZHM5ValueEntity_float32> m_ValueEntity;
};
