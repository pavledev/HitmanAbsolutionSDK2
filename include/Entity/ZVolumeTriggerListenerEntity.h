#pragma once

#include "ZEntityImpl.h"
#include "IBoolCondition.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZVariantRef.h"

class ISoundPlayable;
class ZBoxVolumeEntity;
class ZComponentCreateInfo;
class ZEventNull;
class ZSpatialEntity;
class ZSphereVolumeEntity;
class ZString;
class ZVolumeTriggerEntity;
struct SMatrix43;
struct STypeID;

class ZVolumeTriggerListenerEntity : public ZEntityImpl, public IBoolCondition
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZBoxVolumeEntity>> m_Boxes;
	TArray<TEntityRef<ZSphereVolumeEntity>> m_Spheres;
	TArray<TEntityRef<ZSpatialEntity>> m_Spatials;
	bool m_bEnabled;
	bool m_TriggerOnHitman;
	bool m_TriggerOnActorAlive;
	bool m_TriggerOnActorDead;
	bool m_TriggerOnThrownItem;
	TArray<TEntityRef<ZVolumeTriggerEntity>> m_TriggerEntities;
	TArray<TEntityRef<ZSpatialEntity>> m_ExclusionList;
	TEntityRef<ISoundPlayable> m_SoundFootstepSweetenerHM;
	TEntityRef<ISoundPlayable> m_SoundFootstepSweetenerNPC;
	bool m_bActivated : 1;
	bool m_bColliding : 1;
	bool m_bRegistered : 1;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_BoolConditionChangedEvent;

	static SComponentMapEntry s_componentMap[0];

	~ZVolumeTriggerListenerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	bool GetBoolConditionValue() override;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() override;

	ZVolumeTriggerListenerEntity() = default;
	static void RegisterType();
	ZVolumeTriggerListenerEntity(ZComponentCreateInfo& info);
	void SetTriggered(bool bColliding);
	void OnEnable();
	void OnDisable();
	const unsigned int GetListenerFlags() const;
	const TArray<TEntityRef<ZBoxVolumeEntity>>& GetBoxes() const;
	const TArray<TEntityRef<ZSphereVolumeEntity>>& GetSpheres() const;
	const TArray<TEntityRef<ZVolumeTriggerEntity>>& GetTriggerEntities() const;
	const TArray<TEntityRef<ZSpatialEntity>>& GetExclusionList() const;
	TEntityRef<ISoundPlayable> GetFootstepSweetenerHM() const;
	TEntityRef<ISoundPlayable> GetFootstepSweetenerNPC() const;
	void Register();
	void Unregister();
	void RegisterBoxChangehandlers();
	void RegisterSphereChangehandlers();
	void OnVolumeChangedCallback(const ZEntityRef& entity, const SMatrix43& mNewMatris);
	void OnBoxesChanged(const TArray<TEntityRef<ZBoxVolumeEntity>>& oldBoxes);
	void OnSpheresChanged(const TArray<TEntityRef<ZSphereVolumeEntity>>& oldSpheres);
	void UnregisterSphereChangehandlers(const TArray<TEntityRef<ZSphereVolumeEntity>>& oldSpheres);
	void UnregisterBoxChangehandlers(const TArray<TEntityRef<ZBoxVolumeEntity>>& oldBoxes);
};
