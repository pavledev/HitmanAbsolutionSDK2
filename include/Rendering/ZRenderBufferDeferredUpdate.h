#pragma once

#include "ZRenderBuffer.h"

class ZRenderBufferDeferredUpdate
{
public:
    unsigned int m_nOffset;
    unsigned int m_nSize;
    ZRenderBuffer* m_pBuffer;
};
