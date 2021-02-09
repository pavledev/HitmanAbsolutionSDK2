#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZRenderPrimitiveResource.h"
#include "ZAnimationLibrary.h"

class ZCrowdActorEntity : public ZEntityImpl
{
public:
    TResourcePtr<ZRenderPrimitiveResource> m_pActorModel;
    TResourcePtr<ZRenderTextureResource> m_pDiffuseVariationTexture1;
    TResourcePtr<ZRenderTextureResource> m_pDiffuseVariationTexture2;
    TResourcePtr<ZRenderTextureResource> m_pDiffuseVariationTexture3;
    bool m_bIsMale;
    float m_nSizeVariation;
    TEntityRef<ZAnimationLibrary> m_animationLibrary;
    ZEvent<ZCrowdActorEntity*, unsigned int, ZEventNull, ZEventNull, ZEventNull> m_Listeners;
    bool m_bIsStreamedIn;
    TFixedArray<TFixedArray<float, 5>, 5> m_moveSpeeds;
    unsigned __int16 m_aPushClipIndex[2][2];
    int* m_pMeshIDToRigID;
    TArrayRef<int> m_aMeshIDToRigID;

    enum EActorResourceChangeFlags : __int32
    {
        AR_MODEL = 0x1
    };

    virtual void RegisterForResourceListening(const ZDelegate<void __cdecl(ZCrowdActorEntity*, unsigned int)>*);
    virtual void UnregisterForResourceListening(const ZDelegate<void __cdecl(ZCrowdActorEntity*, unsigned int)>*);
};
