#pragma once

#include "IComponentInterface.h"

class ISceneEntity : public IComponentInterface
{
public:
	~ISceneEntity() override = default;

	static void RegisterType();
	ISceneEntity() = default;
};
