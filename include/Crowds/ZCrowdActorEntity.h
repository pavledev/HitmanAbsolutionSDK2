#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZRenderPrimitiveResource.h"
#include "ZAnimationLibrary.h"
#include "CrowdUtil.h"

class ZCrowdActorEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EActorResourceChangeFlags
	{
		AR_MODEL = 1
	};

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
	unsigned short m_aPushClipIndex[2][2];
	int* m_pMeshIDToRigID;
	TArrayRef<int> m_aMeshIDToRigID;

	static SComponentMapEntry s_componentMap[0];

	~ZCrowdActorEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void Init() override;
	virtual void RegisterForResourceListening(const ZDelegate<void __cdecl(ZCrowdActorEntity*, unsigned int)>& fpCallback);
	virtual void UnregisterForResourceListening(const ZDelegate<void __cdecl(ZCrowdActorEntity*, unsigned int)>& fpCallback);

	ZCrowdActorEntity() = default;
	static void RegisterType();
	ZCrowdActorEntity(const ZCrowdActorEntity& __that);
	ZCrowdActorEntity(ZComponentCreateInfo& Info);
	TResourcePtr<ZRenderPrimitiveResource> GetModelResourcePtr() const;
	void GetDiffuseVariationTextures(TArray<TResourcePtr<ZRenderTextureResource>>& aOut) const;
	unsigned int GetNumVisualVariations() const;
	float GetSizeVariation() const;
	float GetMovementSpeed(EGait eGait, ESpeed eSpeed);
	const ZAnimationBoneData* GetBoneData() const;
	const TArrayRef<int>& GetMeshIDToRigIDMap() const;
	bool IsMale() const;
	ZAnimationLibrary* GetAnimationLibrary() const;
	unsigned short GetPushedAnimationClip(CrowdUtil::ECrowdFacing eFacing, CrowdUtil::ECrowdSide eSide);
	void InitializeForSimulation();
	bool FullyStreamedIn();
	void OnActorModelChanged();
	const MR::Rig* GetAnimationRig() const;
	void BuildMeshIDToRigIDMap(const ZAnimationRig& pMeshRig, const MR::Rig* pAnimRig);
	ZCrowdActorEntity& operator=(const ZCrowdActorEntity& __that);
};
