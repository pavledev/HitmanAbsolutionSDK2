#pragma once

#include "TResourcePtr.h"
#include "ZRenderTextureResource.h"
#include "ZString.h"

struct STextureDesc
{
	TResourcePtr<ZRenderTextureResource> pTexture;
	ZRenderShaderResourceView* pSRV;
	ZString Name;
	unsigned short nId;
	unsigned short nType;

	bool operator<(const STextureDesc& other);
	STextureDesc(const STextureDesc& __that);
	STextureDesc() = default;
	~STextureDesc() = default;
	STextureDesc& operator=(const STextureDesc& __that);
};
