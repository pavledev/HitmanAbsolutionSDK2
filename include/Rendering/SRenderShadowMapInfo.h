#pragma once

class SRenderShadowMapInfo
{
public:
    float m_fFadeStartTime;
    float m_fShadowFadeIntensity;
    unsigned int m_nFadeMode;
    unsigned int m_nLastFrameUsed;
    void* m_pOwner;
};
