#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZSpatialEntity;
class ZString;
struct STypeID;
template <class T> class TEntityRef;

class ZVolumeTriggerEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZSpatialEntity>> m_Spatials;
	bool m_bEnabled;
	bool m_TypeHitman;
	bool m_TypeActorAlive;
	bool m_TypeActorDead;
	bool m_TypeExplodeableItem;
	ZEntityRef m_pOwner;
	unsigned int m_nTypeFlags;
	bool m_bActivated : 1;
	bool m_bColliding : 1;
	bool m_bRegistered : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZVolumeTriggerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZVolumeTriggerEntity() = default;
	static void RegisterType();
	ZVolumeTriggerEntity(ZComponentCreateInfo& info);
	void OnEnable();
	void OnDisable();
	void SetOwner(ZEntityRef pOwner);
	ZEntityRef GetOwner() const;
	void SetTypeFlags(unsigned int nTypeFlags);
	const unsigned int GetTypeFlags() const;
	const TArray<TEntityRef<ZSpatialEntity>>& GetSpatials() const;
	void Register();
	void Unregister();
};
