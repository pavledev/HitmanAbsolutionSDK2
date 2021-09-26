#pragma once

#include "ZRenderGraphNode.h"
#include "TEntityRef.h"
#include "SRenderTexture2DAccess.h"
#include "TArray.h"

class ZMirrorEntity;
class IJobChain;
class ZCameraEntity;
class ZRenderContext;
class ZRenderGraphNodeCamera;
class ZRenderGraphTraversal;
class ZRenderTraversalContext;
class ZRenderableEntity;
struct SRenderDestinationDesc;
struct float4;

class ZRenderGraphNodeMirror : public ZRenderGraphNode
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

	~ZRenderGraphNodeMirror() override = default;
	void Traverse(ZRenderGraphNode* pParent, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pParentTraversalContext, ZRenderContext* pRenderContext) override;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodeMirror() = default;
	ZRenderGraphNodeMirror(ZMirrorEntity* pMirrorEntity, ZRenderGraphNode::TYPE eType);
	unsigned int GetRenderDestinationId();
	void OnDeviceWillReset(const SRenderDestinationDesc& desc);
	void SetClientsVisible(bool bVisible);
	bool GetClientsVisible();
	TArray<ZRenderGraphNode*>& GetClientNodes();
	void MirrorUpdateSurface();
	void CalcCullParameters(const float4& vCameraPosition, const float4& vCameraDirection, float* pMirrorDot, float* fMirrorDistance, float* pMirrorBackDot);
	void FreeBlurTextures();
	void FreeTexture(SRenderTexture2DAccess& Texture);
	void AllocSurface();
	void FreeSurface();
};
