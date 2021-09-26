#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ISequenceEntity.h"
#include "IBoolCondition.h"
#include "SGameUpdateEvent.h"

class ZSequenceActor;

class ZActorsSequence : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EStopReason
	{
		SequenceCompleted = 0,
		SequenceInterrupted = 1,
		BeingDeactivated = 2,
		FailedToStart = 3
	};

	struct StopReason
	{
		enum Enum
		{
			SequenceCompleted = 0,
			SequenceInterrupted = 1,
			BeingDeactivated = 2,
			FailedToStart = 3
		};

	};

	TArray<TEntityRef<ZSequenceActor>> m_aActors;
	TEntityRef<ISequenceEntity> m_pSequence;
	TEntityRef<IBoolCondition> m_pStartCondition;
	bool m_bOneTimeOnly;
	bool m_bPreventItemGlow;
	bool m_bIsPlaying : 1;
	bool m_bHasPlayed : 1;
	bool m_bWasManuallyStarted : 1;
	bool m_bActive : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZActorsSequence() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZActorsSequence() = default;
	static void RegisterType();
	ZActorsSequence(ZComponentCreateInfo& info);
	void OnActorTargetingAnotherWaypoint();
	void OnActorWalkingToWaypoint();
	bool CanActorsLeaveWaypoint() const;
	void OnMandatoryActorInterrupted();
	void OnActorsSet(const TArray<TEntityRef<ZSequenceActor>>& oldActors);
	void OnSequenceSet(const TEntityRef<ISequenceEntity>& pPrevSequence);
	void OnStartConditionValueChanged(const TEntityRef<IBoolCondition>& __formal, bool bValue);
	void OnSequenceStart(ISequenceEntity* pSequence);
	void OnSequenceStop(ISequenceEntity* pSequence);
	void OnSequenceAbort(ISequenceEntity* pSequence);
	void OnGameUpdate(const SGameUpdateEvent& updateEvent);
	void OnStartPlayback();
	void OnStopPlayback();
	bool CanPlay() const;
	bool CanStart() const;
	bool AllMandatoryActorsCanPlay() const;
	bool AllAvailableActorsCanStart() const;
	bool NoActorsAreTargetingWaypoints() const;
	void StartPlayback();
	void StopPlayback(StopReason::Enum stopReason);
	void Reset();
	void AbortSequence() const;
	ZString WhyCantStart() const;
	ZString WhyCantPlay() const;
	ZString WhoAndWhyIsAvailableButCantStart() const;
	ZString WhoAndWhyIsMandatoryAndCantPlay() const;
};
