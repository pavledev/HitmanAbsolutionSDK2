#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZLinkedEntity;
class ZSpatialEntity;
struct SMatrix43;
struct STypeID;

class ZBoneAttachEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EResetMode
	{
		eAtBoneOrigin = 0,
		eKeepOffset = 1
	};

	TEntityRef<ZLinkedEntity> m_linkedEntity;
	ZString m_BoneName;
	TEntityRef<ZSpatialEntity> m_spatial;
	bool m_bStartAttached;
	EResetMode m_eResetMode;
	bool m_bIsAttached;
	unsigned int m_nGlobalBoneID;
	bool m_bGameStarted;
	TEntityRef<ZLinkedEntity> m_AttachLinkedEntity;
	TEntityRef<ZSpatialEntity> m_AttachSpatial;

	static SComponentMapEntry s_componentMap[0];

	~ZBoneAttachEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;

	ZBoneAttachEntity() = default;
	static void RegisterType();
	ZBoneAttachEntity(const ZBoneAttachEntity& __that);
	ZBoneAttachEntity(ZComponentCreateInfo& Info);
	void SetLinkedEntity(TEntityRef<ZLinkedEntity> pLinkedEntity);
	void OnAttach();
	void OnDetach();
	void OnLinkedEntityChanged();
	void OnBoneNameChanged();
	void OnSpatialChanged();
	void Attach();
	void Detach();
	void RegisterForTransformParentChanges();
	void UnregisterForTransformParentChanges();
	void OnAttachedEntityTransformChange(const ZEntityRef& entity, const SMatrix43& mNewValue);
	ZBoneAttachEntity& operator=(const ZBoneAttachEntity& __that);
};
