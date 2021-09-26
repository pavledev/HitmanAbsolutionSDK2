#pragma once

#include "SRenderMixedResolutionBuffers.h"
#include "ZRenderShaderResourceView.h"
#include "ZRenderGBuffer.h"
#include "ZRenderDestination.h"
#include "ZRenderContext.h"
#include "ZRenderDepthStencilView.h"
#include "ZRenderTargetView.h"
#include "SMatrix.h"
#include "float4.h"
#include "ZRenderGraphTraversal.h"
#include "SRenderTempTexture2DAccess.h"

struct SRenderPostfilterContext
{
	ZRenderShaderResourceView* m_pDepthSRV;
	ZRenderDepthStencilView* m_pDepthDSV;
	ZRenderGBuffer* m_pGBuffer;
	SMatrix m_mWorldToView;
	SMatrix m_mProjection;
	SRenderTempTexture2DAccess* m_pSrcAccess;
	ZRenderTargetView* m_pDestRTV;
	ZRenderDestination* m_pRenderDestination;
	SRenderMixedResolutionBuffers* m_pBuffers;
	float m_fCameraFovY;
	float4 m_vCameraPosition;
	float4 m_vEyeUpperLeft;
	float4 m_vEyeUpperRight;
	float4 m_vEyeLowerLeft;
	float4 m_vEyeLowerRight;
	float4 m_vViewRemap;
	float m_fNearPlane;
	float m_fFarPlane;
	bool m_bDofEnabled;
	bool m_bColorCorrectFar;
	float m_fDofBlurriness;
	ZRenderContext* m_pRenderContext;
	ZRenderGraphTraversal* m_pRenderGraphTraversal;

	SRenderPostfilterContext() = default;
	~SRenderPostfilterContext() = default;
};
