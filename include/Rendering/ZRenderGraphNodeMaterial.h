#pragma once

#include "ZRenderGraphNode.h"
#include "IRenderMaterialEntity.h"
#include "TResourcePtr.h"
#include "ERenderLayer.h"
#include "TArray.h"

class ZRenderGraphNodeDestination;
struct SBinderBlockPatchState;
class IJobChain;
class ZMutex;
class ZRenderGraphNodeMirror;
class ZRenderMaterialInstance;
class ZRenderShaderResourceView;
class ZRenderTextureResource;
class ZRenderableEntity;
class ZRuntimeResourceID;
struct SRenderBinderBlock3Patch;
struct SRenderDestinationDesc;

class ZRenderGraphNodeMaterial : public ZRenderGraphNode
{
public:
	enum EDirtMask
	{
		EDIRTY_TEXTURES = 1,
		EDIRTY_BINDERS = 2,
		EDIRTY_PARAMS = 4,
		EDIRTY_DESTINATIONS = 8
	};

	struct STextureModifier
	{
		bool m_bEnabled;
		TResourcePtr<ZRenderTextureResource> m_pTexture;
		ZRenderShaderResourceView* m_pTextureSRV;
		int m_nFrameIndex;
		ZRenderGraphNodeDestination* m_pRenderDestinationTexture;
		unsigned char m_Offset3;
		unsigned char m_Index3;
		unsigned short m_nType;

		STextureModifier(const STextureModifier& __that);
		STextureModifier() = default;
		~STextureModifier() = default;
	};

	struct SFloatArrayModifer
	{
		IRenderMaterialEntity::EModifierOperation m_eOperation;
		unsigned short m_nOffset;
		unsigned short m_nSize;
		unsigned short m_Offset3;
		unsigned short m_Index3;
	};

	const IRenderMaterialEntity::SModifierDesc* m_pModifierDesc;
	TResourcePtr<ZRenderMaterialInstance> m_pMaterialInstance;
	TResourcePtr<ZRenderMaterialInstance> m_pMaterialInstanceOverrideDest;
	ZRenderMaterialInstance* m_pMaterialInstancePtr;
	ZRenderMaterialInstance* m_pMaterialInstanceOverrideDestPtr;
	bool m_bActive;
	bool m_bGlobal;
	unsigned char m_nDirty;
	TArray<STextureModifier> m_TextureModifiers;
	TArray<SFloatArrayModifer> m_FloatArrayModifiers;
	TArray<float> m_Values;
	SRenderBinderBlock3Patch* m_Patch;
	unsigned int m_nPatchSize;
	ZRenderGraphNodeMaterial* m_pNextDirty;
	ZRenderGraphNodeMirror* m_pMirror;

	static ZMutex m_Mutex;
	static ZRenderGraphNodeMaterial* m_pDirtyHead;

	~ZRenderGraphNodeMaterial() override = default;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodeMaterial() = default;
	bool IsActive() const;
	bool IsGlobal() const;
	ZRenderMaterialInstance* GetMaterialInstance();
	void Activate(ERenderLayer eRenderLayer, bool bActive, bool bGlobal);
	static bool ActivateLocal(ZRenderGraphNodeMaterial** pMaterialModifiers, unsigned int nNumMaterials, ZRenderMaterialInstance* pMaterialInstance, ERenderLayer eRenderLayer, SBinderBlockPatchState* pPatchState);
	ZRenderMaterialInstance* GetOverrideMaterial(ZRenderMaterialInstance* pBaseMaterialInstance);
	ZRenderGraphNodeMirror* GetMirror();
	void Update();
	static void UpdatePending();
	void OnTextureChanged(const ZRuntimeResourceID& id);
	void OnDestinationChanged(const SRenderDestinationDesc& Desc);
	void UpdateTextures();
	void UpdateDestinations();
	void UpdateBinders();
	void OnMaterialInstanceChanged(const ZRenderMaterialInstance* pMaterialInstance);
	void SetDirty(unsigned int nNewDirtMask);
	void UpdateMaterialInstancePtr();
	void UpdateBinders3(bool bFull);
};
