#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "ZTextureMap.h"
#include "TArray.h"

class ZRenderTexture2D;
class IRenderResource;
class IRenderTextureResource;
class ZRenderShaderResourceView;

class ZRenderTextureResource : public TRenderReferencedCountedImpl<IRenderTextureResource, 0>
{
public:
	TArray<ZRenderShaderResourceView*> m_SRVs;
	ZTextureMap::EInterpretAs m_eInterpretAs;
	ZTextureMap::EDimensions m_eDimensions;
	bool m_bReady;

	~ZRenderTextureResource() override = default;

	ZRenderTextureResource() = default;
	ZRenderTextureResource(const TArray<IRenderResource*>& resources, const TArray<ZRenderShaderResourceView*>& SRVs, ZTextureMap::EInterpretAs eInterpretAs, ZTextureMap::EDimensions eDimensions);
	ZRenderTextureResource(IRenderResource* pResource, ZRenderShaderResourceView* pSRV, ZTextureMap::EInterpretAs eInterpretAs, ZTextureMap::EDimensions eDimensions);
	ZRenderTexture2D* GetTexture2D(unsigned int nIndex) const;
	ZRenderShaderResourceView* GetSRV(unsigned int nIndex) const;
};
