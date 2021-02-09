#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "TArray.h"
#include "STextureDesc.h"
#include "ZString.h"
#include "ZRenderMaterialEffectData.h"
#include "TFixedArray.h"
#include "ZDelegate.h"

class ZRenderMaterialInstance : TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
    ZRenderMaterialInstance* m_pPrev;
    ZRenderMaterialInstance* m_pNext;
    unsigned int m_nHash;
    struct ZRenderMaterialBinderBlock3* m_Binders3[28];
    TArray<STextureDesc> m_Textures;
    TArray<ZString> m_Params;
    unsigned __int32 m_nUpdateBlock : 1;
    TResourcePtr<ZRenderMaterialEffectData> m_pEffectData;
    ZRenderEffect* m_pEffect;
    TFixedArray<ZRenderEffectTechnique*, 28> m_pTechniques;
    ZResourcePtr m_pMaterialDescriptor;
    unsigned int m_nMaterialClassFlags;
    unsigned int m_nTransparencyFlags;
    unsigned int m_nLayerMask;
    unsigned int m_nSortingValue;
    unsigned int m_nVersion;
    unsigned int m_nResources;
    ZResourcePtr* m_pResourcePtr;
    TBag<ZDelegate<void __cdecl(ZRenderMaterialInstance const*)>, TArray<ZDelegate<void __cdecl(ZRenderMaterialInstance const*)> > > m_ChangedEventHandlers;
    bool m_bBackFaceCulling;
};
