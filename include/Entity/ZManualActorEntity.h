#pragma once

#include "ZSpatialEntity.h"
#include "ZAnimationClipEntity.h"
#include "ZCrowdEntity.h"

class ZManualActorEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nActorTemplateIndex;
	int m_nActorVariantIndex;
	bool m_bStartIdle;
	bool m_bNeverFlee;
	TArray<TEntityRef<ZAnimationClipEntity>> m_idleOverrideClips;
	bool m_bAllowRandomStateChanges;
	ZResourcePtr m_pGizmo;
	TEntityRef<ZCrowdEntity> m_pCrowd;
	unsigned int m_nActorIndex;

	static SComponentMapEntry s_componentMap[0];

	~ZManualActorEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	ZManualActorEntity() = default;
	static void RegisterType();
	ZManualActorEntity(ZComponentCreateInfo& Info);
	void SetOwner(const TEntityRef<ZCrowdEntity>& pCrowd, unsigned int nIndex);
	unsigned char GetActorTemplateIndex() const;
	unsigned char GetActorVariantIndex() const;
	bool GetStartIdle() const;
	bool GetAllowRandomStateChanges() const;
	bool GetNeverFlee() const;
	TArrayRef<TEntityRef<ZAnimationClipEntity>> GetOverrideClips();
	void MoveCallback(const ZEntityRef& entity, const SMatrix43& mNewValue);
	void OnGizmoChanged();
	void OnStartIdleChanged();
	void OnActorTemplateIndexChanged();
	void OnActorVariantIndexChanged();
	float4 GetActorSize() const;
};
