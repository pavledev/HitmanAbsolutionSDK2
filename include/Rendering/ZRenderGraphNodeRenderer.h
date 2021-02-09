#pragma once

#include "TPriorityQueue.h"
#include "SRenderGraphNodeLight.h"
#include "TQueue.h"
#include "SRenderShadowMapInfo.h"
#include "TFixedArray.h"
#include "SLightBundle.h"
#include "ZRenderDevice.h"

class ZRenderGraphNodeRenderer
{
public:
    TPriorityQueue<SRenderGraphNodeLight, TArray<SRenderGraphNodeLight>> m_lights;
    TPriorityQueue<SRenderGraphNodeLight, TArray<SRenderGraphNodeLight>> m_darklights;
    TQueue<SRenderShadowMapInfo*, TBlockArray<SRenderShadowMapInfo*>> m_ShadowFadeQueue;
    TFixedArray<SLightBundle, 256> m_lightBundles;
    TFixedArray<SLightBundle, 256> m_reflectionLightBundles;
    TFixedArray<SLightBundle, 256> m_darklightBundles;
    unsigned int m_nDarkLightIndex;
    ZRenderDevice* m_pRenderDevice;
    ZRenderConstBufferRef m_ConstBufferLightingV;
    ZRenderConstBufferRef m_ConstBufferLightingF;
    ZRenderConstBufferRef m_PerViewSharedData;
    ZRenderConstBufferRef m_PerViewSharedData2;
};
