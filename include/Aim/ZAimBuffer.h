#pragma once

#include "SQV.h"

class alignas(4) ZAimBuffer
{
public:
    SQV* m_qvBones;
    int* m_nBoneIDMap;
    bool m_bMapped;
    unsigned int m_nSize;
    bool m_bAimWasMirrored;
};
