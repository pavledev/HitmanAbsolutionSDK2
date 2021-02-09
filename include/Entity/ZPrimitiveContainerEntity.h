#pragma once

#include "ZRenderableEntity.h"
#include "IRenderMaterialEntity.h"
#include "ERenderGlowTypes.h"
#include "TEnumerator.h"
#include "TRefCountPtr.h"
#include "IRenderPrimitive.h"

class alignas(4) ZPrimitiveContainerEntity : public ZRenderableEntity
{
public:
    unsigned __int16 m_nRuntimeDecal;
    TArray<TRefCountPtr<IRenderPrimitive>> m_Primitives;
    TList<IRenderMaterialEntity*> m_pMaterialModifiers;
    IRenderMaterialEntity* m_pOverrideMaterial;
    unsigned int m_nPrimitiveChangeCounter;
    float m_fLODScale;
    float m_fLODOffset;
    ERenderGlowTypes m_eGlowType;
    bool m_bCastShadows;
    bool m_bPCCastShadows;
    bool m_bIsPlayer;

    virtual void ClearPrimitives();
    virtual void ClearDecalPrimitives();
    virtual bool IsPrimitiveAdded(const TRefCountPtr<IRenderPrimitive>*);
    virtual void AddPrimitive(const TRefCountPtr<IRenderPrimitive>*);
    virtual void AddPrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>*);
    virtual void RemovePrimitive(const TRefCountPtr<IRenderPrimitive>*);
    virtual void RemovePrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>*);
    virtual void PrimitiveUpdated(const TRefCountPtr<IRenderPrimitive>*, bool);
    virtual TEnumerator<TRefCountPtr<IRenderPrimitive> const > GetPrimitiveEnumerator();
    virtual TEnumerator<TRefCountPtr<IRenderPrimitive> >* GetPrimitiveEnumerator(TEnumerator<TRefCountPtr<IRenderPrimitive> >* result);
    virtual unsigned int GetPrimitivesCount();
    virtual unsigned int GetPrimitiveChangeCounter();
    virtual bool GetCastShadows();
    virtual float GetLODScale();
    virtual float GetLODOffset();
    virtual void SetCastShadows(bool);
    virtual void SetLODScale(float);
    virtual void SetLODOffset(float);
    virtual void AttachMaterialModifier(IRenderMaterialEntity*);
    virtual void DetachMaterialModifier(IRenderMaterialEntity*);
    virtual TEnumerator<IRenderMaterialEntity* const>* GetMaterialModifiers(TEnumerator<IRenderMaterialEntity* const>* result);
    virtual TEnumerator<IRenderMaterialEntity*>* GetMaterialModifiers(TEnumerator<IRenderMaterialEntity*>* result);
    virtual void ClearMaterialModifiers();
    virtual void SetOverrideMaterial(IRenderMaterialEntity*);
    virtual void ForceUpdateOverrideMaterial(IRenderMaterialEntity*);
    virtual IRenderMaterialEntity* GetOverrideMaterial();
    virtual ERenderGlowTypes GetGlowType();
    virtual void SetGlowType(const ERenderGlowTypes);
};
