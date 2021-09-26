#pragma once

#include "ZRenderableEntity.h"
#include "ERenderGlowTypes.h"
#include "TEnumerator.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TList.h"
#include "ZVariantRef.h"

class IRenderMaterialEntity;
class IRenderPrimitive;
class ZComponentCreateInfo;
struct STypeID;
struct float4;
template <class T> class TRefCountPtr;

class ZPrimitiveContainerEntity : public ZRenderableEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	unsigned short m_nRuntimeDecal;
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

	static SComponentMapEntry s_componentMap[0];

	~ZPrimitiveContainerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	virtual void ClearPrimitives();
	virtual void ClearDecalPrimitives();
	virtual bool IsPrimitiveAdded(const TRefCountPtr<IRenderPrimitive>& pPrimitive) const;
	virtual void AddPrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	virtual void AddPrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	virtual void RemovePrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	virtual void RemovePrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	virtual void PrimitiveUpdated(const TRefCountPtr<IRenderPrimitive>& pPrimitive, bool bUpdateBounds);
	virtual TEnumerator<TRefCountPtr<IRenderPrimitive> const> GetPrimitiveEnumerator() const;
	virtual TEnumerator<TRefCountPtr<IRenderPrimitive>> GetPrimitiveEnumerator();
	virtual unsigned int GetPrimitivesCount() const;
	virtual unsigned int GetPrimitiveChangeCounter() const;
	virtual bool GetCastShadows() const;
	virtual float GetLODScale() const;
	virtual float GetLODOffset() const;
	virtual void SetCastShadows(bool bCastShadows);
	virtual void SetLODScale(float fLODScale);
	virtual void SetLODOffset(float fLODOffset);
	virtual void AttachMaterialModifier(IRenderMaterialEntity* pMaterialModifier);
	virtual void DetachMaterialModifier(IRenderMaterialEntity* pMaterialModifier);
	virtual TEnumerator<IRenderMaterialEntity* const> GetMaterialModifiers() const;
	virtual TEnumerator<IRenderMaterialEntity*> GetMaterialModifiers();
	virtual void ClearMaterialModifiers();
	virtual void SetOverrideMaterial(IRenderMaterialEntity* pMaterial);
	virtual void ForceUpdateOverrideMaterial(IRenderMaterialEntity* pMaterial);
	virtual IRenderMaterialEntity* GetOverrideMaterial() const;
	virtual const ERenderGlowTypes GetGlowType() const;
	virtual void SetGlowType(const ERenderGlowTypes eGlowType);

	ZPrimitiveContainerEntity() = default;
	static void RegisterType();
	ZPrimitiveContainerEntity(const ZPrimitiveContainerEntity& __that);
	ZPrimitiveContainerEntity(ZComponentCreateInfo& Info);
	void ActivateGeom();
	void DeactivateGeom();
	void SetIsPlayer(bool bPlayer);
	bool IsPlayer();
	void OnSetLODScale(float fLODScale);
	void OnSetLODOffset(float fLODOffset);
	void OnSetGlowType(const ERenderGlowTypes eGlowType);
	void HandleChange();
	ZPrimitiveContainerEntity& operator=(const ZPrimitiveContainerEntity& __that);
};
