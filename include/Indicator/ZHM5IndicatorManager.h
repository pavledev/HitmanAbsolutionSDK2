#pragma once

#include "IComponentInterface.h"
#include "TArray.h"
#include "SIndicator.h"

class alignas(4) ZHM5IndicatorManager : public IComponentInterface
{
public:
    TArray<SIndicator> m_ActiveIndicators;
    bool m_bEasterActorEnabled;
};
