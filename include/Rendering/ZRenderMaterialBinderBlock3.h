#pragma once

#include "ERenderLayer.h"
#include "ZRenderShaderResourceView.h"
#include "SRenderDrawContext.h"
#include "STextureDesc.h"
#include "ZRenderShader.h"
#include "ZRenderEffectPass.h"
#include "ZMutex.h"
#include "TArray.h"
#include "SRenderRecordedDrawCmdBuffer.h"
#include "SBinderBlockPatchState.h"
#include "ZRenderBlendState.h"
#include "SBinderBlockTexture.h"
#include "SBinderBlockDesc.h"
#include "ZRPropertyReader.h"

class ZRenderMaterialInstance;

class ZRenderMaterialBinderBlock3
{
public:
	ZRenderMaterialBinderBlock3* m_pNext;
	ZRenderMaterialBinderBlock3* m_pPrev;
	unsigned int m_nVersion;
	ZRenderShader* m_pShaderF;
	ZRenderShader* m_pShaderV;
	ZRenderEffectPass* m_pTessellationPass;
	unsigned int m_nTessellationFactorOffset;
	ZRenderMaterialInstance* m_pMaterialInstance;
	ZRenderBlendState* m_pBlendState;
	TArray<SBinderBlockTexture> m_OriginalTextureStateF;
	SBinderBlockDesc m_Desc;

	static ZMutex m_Mutex;
	static ZRenderMaterialBinderBlock3* m_pGlobalHead;
	static ZRenderMaterialBinderBlock3* m_pDirtyHead;

	ZRenderMaterialBinderBlock3() = default;
	void Dump();
	ZRenderMaterialBinderBlock3(ZRenderEffectPass* pPass, ZRenderMaterialInstance* pInstance, const ZRPropertyReader* pPropertyBinders, ERenderLayer eLayer, unsigned int nVersion);
	~ZRenderMaterialBinderBlock3() = default;
	SBinderBlockParamDesc* GetParamDesc();
	SBinderBlockParamDesc* GetParamDescTextures();
	const SBinderBlockDesc& Desc();
	SBinderBlockState* GetState();
	unsigned int Version();
	void ClearPatch();
	void CreateRenderState(ERenderLayer eLayer, bool bBlendEnabled, const char* pszBlendMode, const float fOpacity, const bool bAlphaTestEnabled, const unsigned int lAlphaTestRef, const bool bFogEnabled, const char* pszCullMode, bool bDecalBlendDiffuseEnabled, bool bDecalBlendNormalEnabled, bool bDecalBlendSpecularEnabled);
	void EXECUTE(SRenderDrawContext* pDrawContext, SBinderBlockPatchState* pPatchState, SRenderRecordedDrawCmdBuffer& DrawCommands, unsigned int nLayerIndex, bool bAllowOverrideFS);
	void SetSRV(unsigned int nId, ZRenderShaderResourceView* pSRV);
	void UpdateTextures(STextureDesc* pTextureDesc, unsigned int nNumTextures);
	void SetDefaultTextures();
	void SetTessellationPass(ZRenderEffectPass* pTessellationPass);
	void UpdateAndSetHullShaderConstBuffer(SRenderDrawContext* pDrawContext, SRenderRecordedDrawCmdBuffer& DrawCommands);
};
