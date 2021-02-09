#pragma once

#include "ITriggerVolume.h"
#include "SVector3.h"

class IBoxVolumeEntity : public ITriggerVolume
{
public:
    virtual const SVector3* GetGlobalSize();
};
