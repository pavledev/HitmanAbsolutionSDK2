#pragma once

#include "ZMapEaseToState.h"
#include "ZMapPoly.h"
#include "TEntityRef.h"

class ZHitman5;

class ZHM5SneakController
{
public:
    bool m_bSneakToggled;
    bool m_bSneakActivated;
    bool m_bSneakLast;
    float m_fSneakWeight;
    float m_fPreSneakWeight;
    ZMapEaseToState m_SneakMap;
    ZMapPoly m_SneakMapFunction;
    float m_fSneakInput;
    TEntityRef<ZHitman5> m_pHitman;
};
