#pragma once

#include "ZRenderVertexBuffer.h"

class ZRenderResourceAsyncUpdateVertexBuffer
{
public:
    alignas(8) ZRenderVertexBuffer* m_pVertexBuffer;
    unsigned __int64 m_nBookmark;
    unsigned int m_nOffset;
    unsigned int m_nSize;
    char* m_pData;

    virtual ~ZRenderResourceAsyncUpdateVertexBuffer();
};
