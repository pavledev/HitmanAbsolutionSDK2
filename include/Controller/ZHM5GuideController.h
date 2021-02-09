#pragma once

#include "ZHM5BaseGuide.h"
#include "ZHitman5.h"

class ZHM5GuideController
{
public:
    ZHM5BaseGuide* m_pNearestGuide;
    ZHM5BaseGuide* m_pNearestFarPromptGuide;
    TEntityRef<ZHitman5> m_pHitman;
    ZHM5BaseGuide* m_QueryGuides[128];
};
