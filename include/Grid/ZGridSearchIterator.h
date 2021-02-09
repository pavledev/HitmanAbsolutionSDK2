#pragma once

#include "float4.h"
#include "TArray.h"
#include "TQueue.h"
#include "SSearchItem.h"
#include "ZBitArray.h"

class alignas(16) ZGridSearchIterator
{
public:
    float4 m_vStartPos;
    TArray<float> m_aGridDistance;
    unsigned int m_nCurrentNodeIndex;
    TQueue<SSearchItem, TBlockArray<SSearchItem>> m_NodeQueue;
    ZBitArray m_Open;
};
