#pragma once

#include "ZRenderGraphNode.h"
#include "TEntityRef.h"
#include "ZCameraEntity.h"
#include "ZRenderGraphNodeCamera.h"

class alignas(16) ZRenderGraphNodeMirror : public ZRenderGraphNode
{
public:
    TEntityRef<ZCameraEntity> m_cameraEntity;
    ZRenderGraphNodeCamera* m_pCameraNode;
    unsigned int m_renderDestId;
    TArray<ZRenderGraphNode*> m_clientNodes;
    SRenderTexture2DAccess m_RenderDest;
    SRenderTexture2DAccess m_BlurTexture_x2[2];
    SRenderTexture2DAccess m_BlurTexture_x4[2];
    unsigned int m_nWidth;
    unsigned int m_nHeight;
    float m_fMirrorGaussScale;
    float m_fDrawDistance;
    int m_nGateTraversalDepth;
    unsigned int m_Quality;
    char m_Blur;
    bool m_bEmissiveOnly;
    bool m_bCrowd;
    bool m_bScatter;
    bool m_bClientsVisible;
    bool m_bActive;
};
