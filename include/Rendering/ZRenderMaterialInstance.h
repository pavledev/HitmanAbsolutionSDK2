#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "TArray.h"
#include "TFixedArray.h"
#include "TBag.h"
#include "TResourcePtr.h"
#include "ZResourcePtr.h"

class ZRenderMaterialBinderBlock3;
struct SRenderBinderBlock3Patch;
class ZResourceReader;
class RenderReferencedCountedBaseStub;
class ZMutex;
class ZRenderEffect;
class ZRenderEffectTechnique;
class ZRenderMaterialEffectData;
class ZRenderShaderResourceView;
class ZRenderTextureResource;
class ZRuntimeResourceID;
class ZString;
struct STextureDesc;
template <class T> class TSharedPointer;
template <class T> class alignas(8) ZDelegate;

class ZRenderMaterialInstance : public TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
public:
	ZRenderMaterialInstance* m_pPrev;
	ZRenderMaterialInstance* m_pNext;
	unsigned int m_nHash;
	ZRenderMaterialBinderBlock3* m_Binders3[28];
	TArray<STextureDesc> m_Textures;
	TArray<ZString> m_Params;
	unsigned int m_nUpdateBlock : 1;
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
	TBag<ZDelegate<void __cdecl(ZRenderMaterialInstance const*)>, TArray<ZDelegate<void __cdecl(ZRenderMaterialInstance const*)>>> m_ChangedEventHandlers;
	bool m_bBackFaceCulling;

	static ZRenderMaterialInstance* m_pDirtyHead;
	static ZMutex m_Mutex;

	~ZRenderMaterialInstance() override = default;

	ZRenderMaterialInstance() = default;
	ZRenderMaterialInstance(TResourcePtr<ZRenderMaterialEffectData> pEffectData, const TSharedPointer<ZResourceReader>& pResourceReader);
	void SetMaterialDescriptor(const ZResourcePtr& pMaterialDescriptor);
	unsigned int GetMaterialClassFlags();
	unsigned int GetTransparencyFlags();
	unsigned int GetLayerMask() const;
	void AddChangedListener(const ZDelegate<void __cdecl(ZRenderMaterialInstance const*)>& callback);
	void RemoveChangedListener(const ZDelegate<void __cdecl(ZRenderMaterialInstance const*)>& callback);
	bool IsLightMaterial() const;
	void SetTextureType(const char* Name, unsigned short nType);
	unsigned int GetParamId(const ZString& name);
	unsigned int GetTextureId(const char* name, unsigned short* pTypeOut);
	ZRenderShaderResourceView* GetSRV(TResourcePtr<ZRenderTextureResource>& pTexture);
	void UpdateTextures();
	void SetDirty();
	void ClearDirty();
	void RemoveFromList();
	void AddToList(ZRenderMaterialInstance*& pHead);
	static void Check();
	void OnTextureChanged(const ZRuntimeResourceID& id);
	SRenderBinderBlock3Patch* CreateBinderBlock3Patch(unsigned int nNumTextures, unsigned int nNumParams, unsigned int nNumFloats);
	void SetBackFaceCulling(bool bVal);
	static void UpdatePendingTextures();
	void PatchMaterialInstanceForHighRes();
	void OnEffectChanged(const TSharedPointer<ZResourceReader>& pResourceReader);
	void UpdateFromEffect(const TSharedPointer<ZResourceReader>& pResourceReader);
	unsigned int Version();
	void OnChanged();
};
