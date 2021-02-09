#pragma once

#include "ZSharedPointerTarget.h"

class alignas(4) ZResourceDataBuffer : public ZSharedPointerTarget
{
public:
    unsigned __int8* m_pData;
    unsigned int m_nSize;
    unsigned int m_nCapacity;
    bool m_bOwnsDataPtr;
};
