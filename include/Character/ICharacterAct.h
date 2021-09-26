#pragma once

#include "IComponentInterface.h"

class ICharacterAct : public IComponentInterface
{
public:
	~ICharacterAct() override = default;

	static void RegisterType();
	ICharacterAct() = default;
};
