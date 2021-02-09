#pragma once

#include "SRenderTexture2DAccess.h"

class alignas(4) SRenderTempTexture2DAccess : public SRenderTexture2DAccess
{
public:
    bool m_bTempAllocated;
};
