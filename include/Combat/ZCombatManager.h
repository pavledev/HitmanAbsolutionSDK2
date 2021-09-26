#pragma once

#include "TArray.h"

class ZActor;
class ZCombatActEntity;
class ZCombatAttractorEntity;
class ZGameTime;
struct float4;
template <class T> class TEntityRef;
template <class T> class alignas(8) ZDelegate;

class ZCombatManager
{
public:
	TArray<TEntityRef<ZActor>> m_aCombatActListenerActors;
	TArray<ZDelegate<void __cdecl(TEntityRef<ZCombatActEntity> const&, int)>> m_aCombatActListenerDelegates;
	TArray<TEntityRef<ZCombatAttractorEntity>> m_aAttractorEntities;
	TArray<TEntityRef<ZCombatActEntity>> m_aActEntities;
	TArray<ZGameTime> m_aActQuarantineEndTime;

	virtual ~ZCombatManager() = default;

	ZCombatManager() = default;
	void Trim();
	void RegisterAttractor(TEntityRef<ZCombatAttractorEntity> pAttractorEntity);
	void UnregisterAttractor(TEntityRef<ZCombatAttractorEntity> pAttractorEntity);
	void RegisterAct(const TEntityRef<ZCombatActEntity>& actEntity);
	void UnregisterAct(const TEntityRef<ZCombatActEntity>& actEntity);
	void FlagActInUse(const TEntityRef<ZCombatActEntity>& actEntity);
	void RegisterCombatActListener(const TEntityRef<ZActor>& pActor, const ZDelegate<void __cdecl(TEntityRef<ZCombatActEntity> const&, int)>& pDelegate);
	void UnregisterCombatActListener(const TEntityRef<ZActor>& pActor);
	void UpdateCombatActSensor();
	void GetValidAct(const float4& vPos, const float4& vEndPos, TEntityRef<ZCombatActEntity>& m_pCombatAct, int& m_nSubAct);
};
