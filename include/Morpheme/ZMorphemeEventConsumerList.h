#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "IMorphemeEventConsumer.h"

class ZMorphemeEventConsumerList
{
public:
    TArray<TEntityRef<IMorphemeEventConsumer>> m_aEventConsumers;
};
