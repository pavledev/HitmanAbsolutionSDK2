#pragma once

#include "ZEntityImpl.h"
#include "IValueEntity.h"

class alignas(4) ZHM5ValueEntity_Base : public ZEntityImpl, public IValueEntity
{
public:
    bool m_bForwardOnSet;
    bool m_bGenerateOnStart;

    virtual void FirePin();
    virtual void SendValueToReceivers();
};
