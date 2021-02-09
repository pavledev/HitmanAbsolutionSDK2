#pragma once

#include "IAsyncRayHandle.h"

class ZSoundOcclusionProbe
{
public:
    IAsyncRayHandle* m_pRayQueryHandle;
    float m_fOcclusionFactor;
    float m_fOcclusionFactorSmooth;
    float m_fOcclusionRadiusAdaptive;
    bool m_bIsActive;
    int m_asyncRaycastHandleCleanupHelper;
};
