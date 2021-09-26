#pragma once

#include "IComponentInterface.h"

class IFabricColliderEntity : public IComponentInterface
{
public:
	~IFabricColliderEntity() override = default;

	static void RegisterType();
	IFabricColliderEntity() = default;
};
