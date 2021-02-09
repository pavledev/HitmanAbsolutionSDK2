#pragma once

#include "THashMap.h"
#include "ZString.h"
#include "TDefaultHashMapPolicy.h"

class alignas(4) ZTextListData
{
public:
    THashMap<int, ZString, TDefaultHashMapPolicy<int, ZString>> m_Map;
    bool m_bUsingGamepad;
};
