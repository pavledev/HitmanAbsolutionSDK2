#pragma once

#include "TMap.h"
#include "STypeID.h"

class SEntityStats
{
public:
    TMap<STypeID*, int> leafTypeMap;
};
