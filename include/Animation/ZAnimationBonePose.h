#pragma once

#include "IComponentInterface.h"

class alignas(4) ZAnimationBonePose : public IComponentInterface
{
public:
    void* m_pData;
    unsigned int m_nNumBones;
    unsigned int m_nAllocationSize;
    bool m_bHasBoneScales;
    bool m_bBoundsCalculated;

    struct __cta_9
    {
        unsigned __int32 bf : 1;
    };
};
