#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "EActorPerceptionSensitivity.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZActor;
struct SGameUpdateEvent;
class ISequenceEntity;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZSequenceControllerEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EState
	{
		eIdle = 0,
		eStartSequence = 1,
		ePreparingActors = 2,
		ePlaying = 3,
		eStopping = 4,
		eAborting = 5
	};

	class ZSequenceActor
	{
	public:
		TEntityRef<ZActor> m_pActor;

		ZSequenceActor(TEntityRef<ZActor> pActor);
		~ZSequenceActor() = default;
		bool IsValid();
		TEntityRef<ZActor> GetActor();
		void FinalizeInitialization(TEntityRef<ZSequenceControllerEntity> pSequenceCtrl);
	};

	TEntityRef<ISequenceEntity> m_pSequence;
	bool m_bPauseWaypointBehavior;
	bool m_bItemGlowEnabled;
	EActorPerceptionSensitivity m_ePerceptionSensitivity;
	bool m_bEnableAmbientLookat;
	TArray<ZSequenceActor*> m_SequenceActors;
	EState m_State;
	float m_fValidateTime;
	bool m_bActivatedByIEntity : 1;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnStart;
	static unsigned int m_snOnAbort;
	static unsigned int m_snStopped;
	static unsigned int m_snOnStopOrAbort;

	~ZSequenceControllerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZSequenceControllerEntity() = default;
	static void RegisterType();
	ZSequenceControllerEntity(ZComponentCreateInfo& info);
	void StartSequence();
	void StopSequence();
	void Abort();
	bool IsRunning();
	bool IsWaypointPauseSequence();
	void OnStart();
	void OnStop();
	void OnAbort();
	void OnPause();
	void OnUnpause();
	void InternalStop(bool bAbort);
	void GameUpdate(const SGameUpdateEvent& updateEvent);
	void SetState(EState state);
	bool BuildCutsceneActorList();
	void DestroyCutsceneActorList();
	bool GetAllActorsValid();
	ZSequenceActor* GetSequenceActor(TEntityRef<ZActor> pActor);
	void SequenceOnStopEventHandler(ISequenceEntity* __formal);
	void SequenceOnAbortEventHandler(ISequenceEntity* __formal);
};
