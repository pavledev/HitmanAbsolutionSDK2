#pragma once

#include "TEntityRef.h"

class ZActor;

class IActorAction
{
public:
	virtual ~IActorAction();
	virtual void SetActor(TEntityRef<ZActor>);
};
