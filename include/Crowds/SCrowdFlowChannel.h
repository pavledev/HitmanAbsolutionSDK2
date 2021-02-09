#pragma once

#include "TArray.h"

class SCrowdFlowChannel
{
public:
    TArray<unsigned char> m_aFlowVectorIndex;
    TArray<unsigned short> m_aFlowCost;
};
