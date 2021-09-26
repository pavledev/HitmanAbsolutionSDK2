#pragma once

#include "ZSpatialEntity.h"
#include "IBoolCondition.h"
#include "EWaypointRotationAlignment.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZEvent.h"
#include "ZVariantRef.h"

class ZSequenceActor;
class ZHM5BaseCharacter;
class ZActor;
class ZChildNetworkActEntity;
class ZComponentCreateInfo;
class ZEventNull;
class ZString;
struct STypeID;

class ZWaypointEntity : public ZSpatialEntity, public IBoolCondition
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EMovementType
	{
		MT_WALK = 0,
		MT_WALK_IF_NOT_IN_SEQUENCE = 1,
		MT_SNAP = 2,
		MT_IGNORE_POSITION = 3
	};

	TEntityRef<ZSequenceActor> m_pSequenceActor;
	EMovementType m_MovementType;
	bool m_bAlignPosition;
	EWaypointRotationAlignment m_AlignRotation;
	float m_fDelay;
	TEntityRef<ZChildNetworkActEntity> m_pAct;
	TArray<TEntityRef<ZChildNetworkActEntity>> m_Acts;
	bool m_bEnabled;
	bool m_bReachedOnNear;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull> m_BoolConditionChangedEvent;
	bool m_bIsOccupied : 1;
	bool m_bPendingSkip : 1;
	bool m_bActivated : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZWaypointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	bool GetBoolConditionValue() override;
	ZEvent<TEntityRef<IBoolCondition> const&, bool, ZEventNull, ZEventNull, ZEventNull>& GetBoolConditionChangedEvent() override;

	ZWaypointEntity() = default;
	static void RegisterType();
	ZWaypointEntity(ZComponentCreateInfo& info);
	EMovementType GetMovementType();
	bool GetAlignPosition();
	EWaypointRotationAlignment GetAlignRotation();
	float GetDelay();
	TEntityRef<ZChildNetworkActEntity> GetValidAct(const TEntityRef<ZActor>& pActor);
	void OnReached(const TEntityRef<ZHM5BaseCharacter>& pCharacter);
	void OnLeaving(const TEntityRef<ZHM5BaseCharacter>& pCharacter);
	bool GetPendingSkip();
	void ResetPendingSkip();
	bool GetIsEnabled();
	bool GetIsReachedOnNear();
	bool IsActorsSequenceWaypoint() const;
	ZSequenceActor* GetSequenceActor() const;
	void OnSequenceActorSet(const TEntityRef<ZSequenceActor>& pOldSequenceActor);
	void OnSkip();
	void OnEnable();
	void OnDisable();
	void UpdateGizmoes();
};
