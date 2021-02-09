#pragma once

#include "SRenderPostfilterStarDefinition.h"
#include "SRenderPostfilterStarLineDefinition.h"
#include "ERenderPostfilterStarType.h"

class ZRenderPostfilterStarDefinition
{
public:
    SRenderPostfilterStarDefinition* m_pStarDefinition;
    SRenderPostfilterStarLineDefinition* m_pStarLineDefinitions;
    ERenderPostfilterStarType m_eStarType;
};
