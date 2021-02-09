#pragma once

#include "TResourcePtr.h"
#include "ZRenderTextureResource.h"
#include "ZString.h"

class STextureDesc
{
public:
    TResourcePtr<ZRenderTextureResource> pTexture;
    ZRenderShaderResourceView* pSRV;
    ZString Name;
    unsigned __int16 nId;
    unsigned __int16 nType;
};
