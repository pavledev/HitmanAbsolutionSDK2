#pragma once

#include "ZRuntimeResourceID.h"
#include "ZEntityRef.h"

class STextureModifier
{
public:
    bool m_bEnabled;
    ZRuntimeResourceID m_idTexture;
    int m_nFrameIndex;
    ZEntityRef m_RenderDestinationTexture;
};
