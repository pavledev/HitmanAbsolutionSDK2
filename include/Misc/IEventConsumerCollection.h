#pragma once

#include "ZMorphemeEventConsumerList.h"
#include "MR.h"
#include "ZEntityRef.h"

class __declspec(novtable) IEventConsumerCollection
{
public:
	virtual ~IEventConsumerCollection() = default;
	virtual ZMorphemeEventConsumerList GetConsumerList() = 0;
	virtual void SendEventsToConsumers(const MR::TriggeredEventsBuffer& triggeredEventsBuffer, ZEntityRef entityRef) = 0;

	static void RegisterType();
	IEventConsumerCollection() = default;
};
