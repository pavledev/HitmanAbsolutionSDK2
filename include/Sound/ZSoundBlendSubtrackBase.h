#pragma once

#include "ZEntityImpl.h"
#include "TArray.h"

class ZSoundBlendSubtrackBase : ZEntityImpl
{
public:
    TArray<ZEntityRef> m_ParameterCurves;
};
