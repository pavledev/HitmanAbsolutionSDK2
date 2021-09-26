#pragma once

#include "TArray.h"
#include "TArrayEnumerator.h"
#include "MR.h"
#include "ZEntityRef.h"

class IMorphemeEventConsumer;
template <class T> class TArrayRef;
template <class T> class TEntityRef;

class ZMorphemeEventConsumerList
{
public:
	TArray<TEntityRef<IMorphemeEventConsumer>> m_aEventConsumers;

	ZMorphemeEventConsumerList(const ZMorphemeEventConsumerList& __that);
	ZMorphemeEventConsumerList(const TArrayRef<TEntityRef<IMorphemeEventConsumer>> aEventConsumers);
	ZMorphemeEventConsumerList() = default;
	static bool ConsumerMatchesEvent(const TEntityRef<IMorphemeEventConsumer>& pConsumer, const MR::TriggeredEvent& discreteEvent);
	void SendEventsToConsumers(const MR::TriggeredEventsBuffer& aEvents, ZEntityRef pCharacterEntity) const;
	void StopAll() const;
	void Enable();
	void Disable();
	void CleanupCurrentEvents();
	TArrayEnumerator<TEntityRef<IMorphemeEventConsumer> const> GetEnumerator() const;
	void AddConsumers(ZMorphemeEventConsumerList consumerList);
	void RemoveConsumers(ZMorphemeEventConsumerList consumerList);
	static void SendEventsToConsumerList(TArrayRef<TEntityRef<IMorphemeEventConsumer>> Consumers, const MR::TriggeredEventsBuffer& aEvents, ZEntityRef pCharacterEntity);
	~ZMorphemeEventConsumerList() = default;
	ZMorphemeEventConsumerList& operator=(const ZMorphemeEventConsumerList& __that);
};
