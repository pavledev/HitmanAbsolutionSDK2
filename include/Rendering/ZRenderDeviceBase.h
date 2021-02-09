#pragma once

#include "ZRenderBlendState.h"
#include "ZRenderRasterizerState.h"
#include "ZRenderDepthStencilState.h"
#include "TBag.h"
#include "STempBufferEntry.h"
#include "TArray.h"
#include "StatesBundle.h"
#include "ZMutex.h"
#include "SRenderSubResourceData.h"
#include "ZRenderTexture3D.h"
#include "SRenderTexture3DDesc.h"

class ZRenderDeviceBase
{
public:
    ZRenderBlendState* m_pBlendState;
    float m_fBlendFactor;
    ZRenderRasterizerState* m_pRasterizerState;
    unsigned int m_nStencilRef;
    ZRenderDepthStencilState* m_pDepthStencilState;
    TBag<STempBufferEntry, TArray<STempBufferEntry>> m_TempBuffers;
    unsigned int m_nPushedStateBundlesCnt;
    StatesBundle m_PushedStates[3];
    ZMutex m_DeviceMutex;
    ZMutex m_GraphMutex;
    unsigned int m_nPresentCount;

    virtual ~ZRenderDeviceBase();
    virtual ZRenderTexture2D*  CreateTexture2D(const SRenderTexture2DDesc*, const SRenderSubResourceData*);
    virtual ZRenderTexture3D*  CreateTexture3D(const SRenderTexture3DDesc*, const SRenderSubResourceData*);
    virtual void SetGamma(float);
    virtual void Trim();
    virtual void PlayCommandBufferWait();
};
