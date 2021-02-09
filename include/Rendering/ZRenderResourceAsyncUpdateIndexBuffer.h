#pragma once

#include "ZRenderIndexBuffer.h"

class ZRenderResourceAsyncUpdateIndexBuffer
{
public:
    alignas(8) ZRenderIndexBuffer* m_pIndexBuffer;
    unsigned __int64 m_nBookmark;
    unsigned int m_nOffset;
    unsigned int m_nSize;
    char* m_pData;

    virtual ~ZRenderResourceAsyncUpdateIndexBuffer();
};
