#pragma once

#include "ZRenderDevice.h"
#include "TMap.h"
#include "SRenderMixedResolutionBuffers.h"
#include "IRenderDestination.h"

class ZRenderUtilities
{
public:
    ZRenderDevice* m_pRenderDevice;
    TMap<unsigned int, SRenderMixedResolutionBuffers*> m_MRBsMap;
    ZRenderConstBufferRef m_ConstBufferGaussBlurV;
    ZRenderConstBufferRef m_ConstBufferDownSample2x2MinMaxV;
    unsigned int m_currentRenderDestId;
    TMap<unsigned int, IRenderDestination*> m_renderDestMap;

    enum EDownSampleNumSamples
    {
        DOWNSAMPLE_NUM_SAMPLES_1P = 0x0,
        DOWNSAMPLE_NUM_SAMPLES_1 = 0x1,
        DOWNSAMPLE_NUM_SAMPLES_4 = 0x2,
        DOWNSAMPLE_NUM_SAMPLES_16 = 0x3
    };
};
