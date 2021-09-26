#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"

class ISoundPlayable;
class ISoundPlayerChannel;

class __declspec(novtable) ISoundDefinition : public IComponentInterface
{
public:
	~ISoundDefinition() override = default;
	virtual ISoundPlayerChannel* PlayDefinition(int param1, void* param2) = 0;
	virtual TEntityRef<ISoundPlayable> GetEmitter() const = 0;

	static void RegisterType();
	ISoundDefinition() = default;
};
