#pragma once

#include "TArray.h"
#include "ERenderLayer.h"
#include "ZRenderContext.h"
#include "ZRenderGraphNode.h"
#include "ZRenderTraversalContext.h"
#include "SRenderShadowMap.h"
#include "SMatrix.h"
#include "ZRenderGraphTraversal.h"

struct SRenderShadowUpdateContext
{
	SMatrix m_mWorldToLight;
	SMatrix m_mProjection;
	float m_fShadowRange;
	TArray<ZRenderGraphNode*>* m_pNodeList;
	ZRenderGraphNode* m_pNode;
	ZRenderGraphTraversal* m_pRenderGraphTraversal;
	ZRenderTraversalContext* m_pTraversalContext;
	ZRenderContext* m_pRenderContext;
	SRenderShadowMap* m_pShadowMap2D;
	unsigned int m_nDrawMask;
	unsigned int m_nLODOffset;
	ERenderLayer m_eRenderLayer;
	ERenderLayer m_eShadeAsRenderLayer;
	bool m_bCullCorners;
	bool m_bBlur;
	bool m_bCameraCulling;
	bool m_bEnableGI;

	SRenderShadowUpdateContext() = default;
	~SRenderShadowUpdateContext() = default;
};
