#pragma once

#include "ZHM5ValueEntity_Base.h"
#include "ZHM5ValueReceiver_float32.h"

class ZHM5ValueEntity_float32 : public ZHM5ValueEntity_Base
{
public:
    float m_Value;
    TArray<ZHM5ValueReceiver_float32*> m_ReceiverList;
};
