#pragma once

#include "ZRenderDevice.h"
#include "ZRender2DRenderTarget.h"
#include "SMatrix.h"

class alignas(8) ZLightPropagationVolume
{
    ZRenderDevice* m_pRenderDevice;
    unsigned int m_nGridWidth;
    unsigned int m_nGridHeight;
    unsigned int m_nGridDepth;
    float m_fCellSize;
    ZRender2DRenderTarget* m_p3DRedAccumulate;
    ZRender2DRenderTarget* m_p3DGreenAccumulate;
    ZRender2DRenderTarget* m_p3DBlueAccumulate;
    ZRender2DRenderTarget* m_p3DRedVolume[2];
    ZRender2DRenderTarget* m_p3DGreenVolume[2];
    ZRender2DRenderTarget* m_p3DBlueVolume[2];
    unsigned int m_nCurrentBuffer;
    SMatrix m_mWorldToLPVBB;
    SMatrix m_mWorldToLPVNormTex;
    ZRenderVertexBuffer* m_pRenderToLPVVertexBuffer;
    ZRenderIndexBuffer* m_pRenderToLPVIndexBuffer;
    float4 m_vPosition;
    bool m_bInitialized;
    unsigned int m_nNumLights;
    unsigned int m_nPrevNumLights;
};
