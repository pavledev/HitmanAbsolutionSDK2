#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"
#include "IValueEntity.h"

class ZHM5ValueReceiver_bool;

enum EForwardRule : __int32
{
    eAlways = 0x0,
    eValueChanged = 0x1,
};

class ZHM5ValueEntity_bool : public ZEntityImpl, public IBoolCondition, public IValueEntity
{
public:
    bool m_Value;
    bool m_bForwardOnSet;
    bool m_bGenerateOnStart;
    EForwardRule m_eForwardRule;
    ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_ChangedEvent;
    TArray<ZHM5ValueReceiver_bool*> m_ReceiverList;
};
