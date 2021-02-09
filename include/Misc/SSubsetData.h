#pragma once

#include "ZString.h"
#include "STypeID.h"
#include "TArray.h"
#include "TPair.h"

class SSubsetData
{
public:
    ZString m_sSubsetName;
    unsigned int m_nSubsetFlags;
    STypeID* m_subsetType;
    TArray<int> m_aEntityOffsets;
    TArray<TPair<int, SSubsetData*>> m_aEntitySubsets;
};
