#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ECombatZoneState.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZGameTime.h"
#include "ZVariantRef.h"

class ZActor;
class ZAgitatedGuardPointEntity;
class ZAgitatedPatrolEntity;
class ZBoxVolumeEntity;
class ZBystanderPointEntity;
class ZComponentCreateInfo;
class ZGuardPointEntity;
class ZSpawnPointEntity;
class ZString;
struct STypeID;
struct float4;
template <class A, int B> class TMaxArray;

class ZCombatZoneEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nZoneIndex;
	bool m_bNoStanddown;
	bool m_bWarZone;
	TArray<TEntityRef<ZBoxVolumeEntity>> m_Volumes;
	TArray<TEntityRef<ZSpawnPointEntity>> m_spawnPoints;
	TArray<TEntityRef<ZAgitatedGuardPointEntity>> m_agitatedGuardPoints;
	TArray<TEntityRef<ZGuardPointEntity>> m_guardPoints;
	TArray<TEntityRef<ZBystanderPointEntity>> m_bystanderPoints;
	TArray<TEntityRef<ZAgitatedPatrolEntity>> m_PatrolRoutes;
	bool m_bActivated;
	ZGameTime m_triggerTime;
	ZGameTime m_engageTime;
	ECombatZoneState m_eZoneState;

	static SComponentMapEntry s_componentMap[0];
	static TMaxArray<TEntityRef<ZCombatZoneEntity>, 32> s_activeZones;

	~ZCombatZoneEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZCombatZoneEntity() = default;
	static void RegisterType();
	ZCombatZoneEntity(ZComponentCreateInfo& info);
	ECombatZoneState GetZoneState() const;
	int GetZoneIndex() const;
	const TArray<TEntityRef<ZSpawnPointEntity>>& GetSpawnPoints() const;
	const TArray<TEntityRef<ZGuardPointEntity>>& GetGuardPoints();
	const TArray<TEntityRef<ZAgitatedGuardPointEntity>>& GetAgitatedGuardPoints();
	TArrayRef<TEntityRef<ZBystanderPointEntity>> GetBystanderPoints() const;
	TArrayRef<TEntityRef<ZAgitatedPatrolEntity>> GetAgitatedPatrolRoutes() const;
	void GetAdjacentZones(TMaxArray<TEntityRef<ZCombatZoneEntity>, 32>& result) const;
	void TriggerZone();
	void EngageZone();
	void DisengageZone();
	void ResetZone();
	bool IsWarZone() const;
	void SetWarZone(bool bWarZone);
	bool ContainsActor(const TEntityRef<ZActor>& rActor) const;
	bool ContainsPoint(const float4& vPoint) const;
	static const TMaxArray<TEntityRef<ZCombatZoneEntity>, 32>& ActiveZones();
	static TEntityRef<ZCombatZoneEntity> GetZoneFromPoint(const float4& vPoint);
	static TEntityRef<ZCombatZoneEntity> GetZoneFromActor(const TEntityRef<ZActor>& rActor);
	static int GetZoneIndexFromPoint(const float4& vFrom);
	static int GetZoneIndexFromActor(const TEntityRef<ZActor>& rActor, bool bIgnoreSpawnedActors);
	static int CompareZoneIndex(const float4& vFrom, int nCompareTo);
	static int CompareZoneIndex(const float4& vFrom, const TEntityRef<ZActor>& rActor, bool bIgnoreSpawnedActors);
	static int CompareZoneIndex(const float4& vFrom, const float4& vTo);
	static void ResetAllZones();
	static void TriggerZonesFromActor(const TEntityRef<ZActor>& rActor);
	static void EngageZonesFromActor(const TEntityRef<ZActor>& rActor);
	void OnTrigger();
	void OnEngage();
	void OnDisengage();
	void OnWarZone();
	void SetTriggered();
};
