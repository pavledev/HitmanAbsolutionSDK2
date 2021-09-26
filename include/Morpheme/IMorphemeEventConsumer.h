#pragma once

#include "MR.h"
#include "ZEntityRef.h"

template <class T> class TArrayRef;

class __declspec(novtable) IMorphemeEventConsumer
{
public:
	virtual void HandleAnimationEvents(const TArrayRef<MR::TriggeredEvent*>& arrayRef, ZEntityRef entityRef) = 0;
	virtual const char* GetConsumerID() const = 0;
	virtual void StopAll() = 0;
	virtual ~IMorphemeEventConsumer() = default;

	static void RegisterType();
	IMorphemeEventConsumer() = default;
};
