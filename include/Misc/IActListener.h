#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) IActListener : public IComponentInterface
{
public:
	~IActListener() override = default;
	virtual void OnActStart() = 0;
	virtual void OnActFinished() = 0;
	virtual void OnActLoopStart() = 0;
	virtual void OnActInFullbody() = 0;
	virtual void OnActBehaviorEvent(unsigned int param1, float param2) = 0;

	static void RegisterType();
	IActListener() = default;
};
