#pragma once

#include "ZMorphemeEventConsumerList.h"

class IEventConsumerCollection
{
public:
    virtual ~IEventConsumerCollection();
    virtual ZMorphemeEventConsumerList* GetConsumerList(ZMorphemeEventConsumerList* result);
    virtual void SendEventsToConsumers(const MR::TriggeredEventsBuffer*, ZEntityRef);
};
