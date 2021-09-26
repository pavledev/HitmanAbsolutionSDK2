#pragma once

#include "ZRenderDevice.h"
#include "ZRender2DRenderTarget.h"
#include "SMatrix.h"

class ZLightPropagationVolume
{
public:
	struct SPropVertex
	{
		SVector3 m_vPosition;
		SVector3 m_vTexCoord;

		SPropVertex(SVector3 vPosition, SVector3 vTexcoord);
		SPropVertex() = default;
	};

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

	ZLightPropagationVolume() = default;
	~ZLightPropagationVolume() = default;
	bool Initialize(unsigned int nGridWidth, unsigned int nGridHeight, unsigned int nGridDepth, float fCellSize);
	bool Uninitialize();
	void InjectLight(ZRenderContext* pRenderContext, ZRenderGraphNodeLight* pLight, SRenderShadowUpdateContext* pShadowContext);
	void PropagateLight();
	void DrawLight(ZRenderContext* pRenderContext, unsigned int nMsaaSamples);
	void SwapBuffers();
	unsigned int GetBackbufferIndex();
	void UpdatePosition(const float4& vCameraPosition, const float4& vViewDirection);
	bool IntersectsLightFrustum(const ZRenderGraphNodeLight* pLight);
	void Propagate(bool bClearAccBuf);
	void SetPosition(const float4& vPosition);
};
