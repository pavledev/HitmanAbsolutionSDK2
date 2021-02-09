#pragma once

#include "ZRenderGraphNode.h"
#include "IRenderMaterialEntity.h"
#include "TResourcePtr.h"
#include "ZRenderMaterialInstance.h"
#include "STextureModifier.h"
#include "SFloatArrayModifer.h"
#include "SRenderBinderBlock3Patch.h"
#include "ZRenderGraphNodeMirror.h"

class __declspec(align(8)) ZRenderGraphNodeMaterial : public ZRenderGraphNode
{
public:
    IRenderMaterialEntity::SModifierDesc* m_pModifierDesc;
    TResourcePtr<ZRenderMaterialInstance> m_pMaterialInstance;
    TResourcePtr<ZRenderMaterialInstance> m_pMaterialInstanceOverrideDest;
    ZRenderMaterialInstance* m_pMaterialInstancePtr;
    ZRenderMaterialInstance* m_pMaterialInstanceOverrideDestPtr;
    bool m_bActive;
    bool m_bGlobal;
    char m_nDirty;
    TArray<STextureModifier> m_TextureModifiers;
    TArray<SFloatArrayModifer> m_FloatArrayModifiers;
    TArray<float> m_Values;
    SRenderBinderBlock3Patch* m_Patch;
    unsigned int m_nPatchSize;
    ZRenderGraphNodeMaterial* m_pNextDirty;
    ZRenderGraphNodeMirror* m_pMirror;
};
