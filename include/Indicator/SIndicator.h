#pragma once

#include "ZHM5IndicatorManager.h"
#include "SInternalIndicator.h"
#include "SHudIndicator.h"

class alignas(16) SIndicator
{
public:
    SInternalIndicator m_sInternal;
    SHudIndicator m_sHud;
};
