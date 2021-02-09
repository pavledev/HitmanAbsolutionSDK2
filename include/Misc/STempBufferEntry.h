#pragma once

#include "ZRenderTexture2D.h"

struct alignas(4) STempBufferEntry
{
    unsigned int nKey;
    ZRenderTexture2D* pTexture;
    bool bFree;
    bool bLocked;
};
