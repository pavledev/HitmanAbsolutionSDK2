#pragma once

#include "IComponentInterface.h"
#include "ISoundPlayerChannel.h"
#include "ISoundPlayable.h"

class ISoundDefinition : public IComponentInterface
{
public:
    virtual ISoundPlayerChannel* PlayDefinition(int, void*);
    virtual TEntityRef<ISoundPlayable>* GetEmitter(TEntityRef<ISoundPlayable>* result);
};
