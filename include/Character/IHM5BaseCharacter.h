#pragma once

#include "IComponentInterface.h"

class IHM5BaseCharacter : public IComponentInterface
{
public:
	~IHM5BaseCharacter() override = default;

	static void RegisterType();
	IHM5BaseCharacter(const IHM5BaseCharacter& __that);
	IHM5BaseCharacter() = default;
	IHM5BaseCharacter& operator=(const IHM5BaseCharacter& __that);
};
