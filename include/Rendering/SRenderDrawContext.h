#pragma once

#include "ZRenderRasterizerState.h"
#include "ZRenderShaderResourceView.h"
#include "ERenderLayer.h"
#include "SMatrix.h"
#include "float4.h"

struct SRenderDrawContext
{
	SMatrix m_mObjectToWorld;
	SMatrix m_mWorldToView;
	float4 m_vPerObjectSimpleColor;
	ERenderLayer m_eRenderLayer;
	ZRenderShaderResourceView* m_pWhiteSRV;
	ZRenderRasterizerState* m_pRasterizerStates[2];
	bool m_bMaterialHasVertexShader : 1;
	bool m_bMaterialUsesClip : 1;
	bool m_bDisableTexture : 1;
	bool m_bDisplayTexelDensity : 1;
	bool m_bWireFrameOverlay : 1;
	bool m_bOcclusionOverlay : 1;
	bool m_bDisplayShaderPerformance : 1;
	bool m_bSetupMiscConstBuffer : 1;
	bool m_bSetBlendState : 1;
	bool m_bSetRasterizerState : 1;
	bool m_bTessellationEnabled : 1;
	float m_fTessellationFactor;

	SMatrix GetWorldToViewMatrix() const;
	float4 GetPerObjectSimpleColor() const;
	void SetPerObjectSimpleColor(const float4& vVal);
	bool GetMaterialHasVertexShader() const;
	void SetMaterialHasVertexShader(bool bVal);
	bool GetMaterialUsesClip() const;
	void SetMaterialUsesClip(bool bVal);
	ERenderLayer GetRenderLayer() const;
	bool GetSetupMiscConstBuffer() const;
	bool SetBlendState() const;
	bool SetRasterizerState() const;
	ZRenderRasterizerState* GetRasterizerState(bool bBackfaceCulling) const;
	void SetTessellationEnabled(bool bTessellation);
	bool isTessellationEnabled() const;
	void SetTessellationFactor(float fTessellationFactor);
	float GetTessellationFactor() const;
	SRenderDrawContext() = default;
	~SRenderDrawContext() = default;
};
