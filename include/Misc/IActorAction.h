#pragma once

class ZActor;
template <class T> class TEntityRef;

class __declspec(novtable) IActorAction
{
public:
	virtual ~IActorAction() = default;
	virtual void SetActor(TEntityRef<ZActor> entityRef) = 0;

	static void RegisterType();
	IActorAction() = default;
};
