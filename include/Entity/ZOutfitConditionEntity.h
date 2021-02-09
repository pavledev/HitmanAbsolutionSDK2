#pragma once

#include "ZBaseConditionEntity.h"
#include "ZHM5Outfit.h"

class ZOutfitConditionEntity : public ZBaseConditionEntity
{
public:
    TArray<TEntityRef<ZHM5Outfit>> m_OutfitList;
};
