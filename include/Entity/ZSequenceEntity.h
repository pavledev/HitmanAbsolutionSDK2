#pragma once

#include "ZEntityImpl.h"
#include "TBlockArray.h"
#include "TQueue.h"
#include "ZGameTime.h"
#include "TEntityRef.h"
#include "ESequencePreviewState.h"
#include "ISequenceEntity.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "TArray.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ISequenceTrack;
class ZComponentCreateInfo;
class ZEventNull;
class ZSpatialEntity;
struct STypeID;
template <class T> class TEnumerator;

class ZSequenceEntity : public ZEntityImpl, public ISequenceEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum ECommand
	{
		COMMAND_START = 0,
		COMMAND_ENABLE_PREVIEW = 1,
		COMMAND_STOP = 2,
		COMMAND_DISABLE_PREVIEW = 3,
		COMMAND_ABORT = 4,
		COMMAND_PAUSE = 5,
		COMMAND_UNPAUSE = 6,
		COMMAND_SETTIME = 7,
		COMMAND_GAME_PAUSE = 8,
		COMMAND_GAME_UNPAUSE = 9,
		COMMAND_PREVIEW_PAUSE = 10,
		COMMAND_PREVIEW_STOP = 11,
		COMMAND_PREVIEW_PLAY = 12,
		COMMAND_PREVIEW_LOOPED = 13
	};

	enum StateFlags
	{
		FORCE_UPDATE = 1,
		IS_RUNNING = 2,
		IS_PAUSED = 4,
		LAST_IS_PAUSED_STATE = 8,
		IS_STOPPED_NATURALLY = 16,
		IS_PREVIEWING = 32,
		IS_READY = 64,
		IS_PREFETCH_ENABLED = 128,
		IS_FORCING_2DSOUNDS = 256
	};

	struct RunData
	{
		TArray<TEntityRef<ISequenceTrack>> m_aTracks;
		TArray<TEntityRef<ISequenceTrack>> m_aStartedTracks;
		ZGameTime m_effectiveSequenceTime;
		int m_nCurrentLoop;

		RunData() = default;
		~RunData() = default;
	};

	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnStopEvent;
	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnAbortEvent;
	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnStartEvent;
	TArray<ZEntityRef> m_aTracksAndGroups;
	TQueue<ECommand, TBlockArray<ECommand>> m_commandQueue;
	ZGameTime m_sequenceTime;
	ZGameTime m_duration;
	ZGameTime m_startTime;
	ZGameTime m_previewTime;
	TEntityRef<ZSpatialEntity> m_sequenceOrigin;
	RunData* m_pRunData;
	int m_nLoopCount;
	ESequencePreviewState m_ePreviewState;
	unsigned short m_eStateFlags;
	bool m_bPausedOnStart;
	bool m_bActivatedByIActivatable : 1;
	bool m_bGettingDeactivated : 1;
	bool m_bOnGameStopped : 1;
	bool m_bLetterbox;
	ZGameTime m_letterboxFadeIn;
	ZGameTime m_letterboxFadeOut;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnPause;
	static unsigned int m_snOnUnpause;
	static unsigned int m_snOnAbort;
	static unsigned int m_snOnStart;
	static unsigned int m_snStopped;
	static unsigned int m_snOnPlay;

	~ZSequenceEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	virtual bool CheckIfItemsReady(ZGameTime previousSequenceTime, ZGameTime newSequenceTime);
	virtual void ResetPrefetchedData();

	bool StartSequence(bool bIsPreviewing) override;
	void Stop() override;
	void Abort() override;
	bool IsPaused() const override;
	bool IsPausedOnStart() const override;
	bool IsPreviewing() const override;
	bool IsRunning() const override;
	bool IsReady() const override;
	void EnablePreview() override;
	void DisablePreview() override;
	void UpdatePreview(ZGameTime newPreviewTime, bool dueToLoop) override;
	void SetPreviewPlayState(ESequencePreviewState state) override;
	bool GetForce2DSounds() const override;
	void SetForce2DSoundsInPreview(bool value) override;
	void GettingDeactivated() override;
	bool ShouldSignalOutputPins() const override;
	void NotifyHierarchyChanged() override;
	void SetTime(float fTime) override;
	float GetDuration() const override;
	float GetEffectiveSequenceTime() const override;
	int GetLoopCount() const override;
	int GetCurrentLoop() const override;
	void Pause(bool bPause) override;
	TArray<TEntityRef<ISequenceTrack>> GetTracks() override;
	ZString GetSequenceName() override;
	void NotifySequenceRequiresUpdate() override;
	bool HasSequenceOrigin() override;
	void SetSequenceOrigin(TEntityRef<ZSpatialEntity> pOrigin) override;
	SMatrix GetSequenceOriginTransform() override;
	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnStopEvent() override;
	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnAbortEvent() override;
	ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnStartEvent() override;
	void ForceExecuteCommands() override;

	ZSequenceEntity() = default;
	static void RegisterType();
	ZSequenceEntity(ZComponentCreateInfo& info);
	void OnGameStop();
	void OnGamePaused(bool pause);
	void SequenceFrameUpdate(ZGameTime deltaGameTime);
	void Stop(bool bAbort);
	bool IsTrackIgnoredInPreview(TEntityRef<ISequenceTrack> pTrack);
	bool IsTrackDisabled(TEntityRef<ISequenceTrack> pTrack);
	void OnStart();
	void OnPause();
	void OnUnpause();
	void OnStop();
	void OnAbort();
	void OnTime(float fValue);
	void OnStartAndSkipToEnd();
	void ExecuteCommands();
	void Update(ZGameTime deltaSequenceTime);
	void StartAllTracks(bool bStartsSequence);
	void UpdatePauseState();
	bool IsSequencePaused() const;
	void StopAllTracks(bool bEndsSequence, bool bAbort);
	void LoopAllTracks();
	void UpdateAllTracks(ZGameTime previousSequenceTime, ZGameTime newSequenceTime);
	void StopTrack(TEntityRef<ISequenceTrack> pTrack, bool bEndsSequence);
	void StartTrack(TEntityRef<ISequenceTrack> pTrack, bool bForceStart, bool bStartsSequence);
	static void AddTracksRecursive(TArray<TEntityRef<ISequenceTrack>>& aTracks, TEnumerator<ZEntityRef> trackAndGroupEnum);
	void SetSequenceOnChildEntity(ZEntityRef entity, const TEntityRef<ISequenceEntity>& pSequence);
	void SetSequenceOnAllChildren();
	void OnSequenceTimeChanged();
	void OnTracksAndGroupsChanged(const TArray<ZEntityRef>& oldValue);
	bool GetStateFlag(StateFlags flag) const;
	void SetStateFlag(StateFlags flag, bool value);
	void CreateRunData();
	void FreeRunDataSafely();
};
