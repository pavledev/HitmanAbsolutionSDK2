#pragma once

#include "ZRenderQuery.h"

class SLightPriorityQuery
{
public:
    void* m_pOwner;
    unsigned int m_nLastFrameUsed;
    unsigned int m_nNumFramesUsed;
    ZRenderQuery* m_pQuery[3];
};
