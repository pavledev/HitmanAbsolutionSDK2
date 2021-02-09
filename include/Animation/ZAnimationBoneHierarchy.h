#pragma once

#include "TArrayRef.h"

class alignas(4) ZAnimationBoneHierarchy
{
public:
    int* m_pParentIndexes;
    TArrayRef<int> m_aParentIndexes;
    int* m_pParentListIndexes;
    TArrayRef<int> m_aParentListIndexes;
    bool m_bDirty;
};
