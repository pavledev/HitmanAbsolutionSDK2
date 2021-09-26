#pragma once

#include "ZGameTime.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "SActorSoundDefs.h"

class ZActor;

class ZActorDialog
{
public:
	enum EState
	{
		PAUSE_BEFORE = 0,
		SPEAKING = 1,
		PAUSE_MIN_DURATION = 2,
		PAUSE_AFTER = 3,
		COMPLETED = 4
	};

	struct SEntry
	{
		struct SCompareActor
		{
			TEntityRef<ZActor> m_rActor;

			SCompareActor(const TEntityRef<ZActor>& rActor);
			bool operator()(const SEntry& entry);
			~SCompareActor() = default;
		};

		TEntityRef<ZActor> m_rActor;
		SActorSoundDefs::EDefinition m_eSound;

		SEntry(const SEntry& __that);
		SEntry() = default;
		~SEntry() = default;
		SEntry& operator=(const SEntry& __that);
	};

	int m_nRefCount;
	EState m_state;
	int m_nCurrent;
	ZGameTime m_tStateTime;
	ZGameTime m_tCompletedTime;
	float m_fPauseBeforeOverride;
	TMaxArray<SEntry, 8> m_entries;
	bool m_bSuspendNextSpeak;
	bool m_bPauseBeforeOverride;

	static const int MAX_ENTRIES;

	ZActorDialog() = default;
	void AddRef();
	void Release();
	void SuspendNextSpeak(bool bSuspend);
	bool IsNextSpeakSuspended() const;
	bool IsCompleted() const;
	bool IsEntryCompleted(int nEntry) const;
	bool IsLastSpeakTriggered() const;
	bool IsActorSpeaking(const TEntityRef<ZActor>& rActor) const;
	bool ContainsActor(const TEntityRef<ZActor>& rActor) const;
	bool RequiresCallOnRadioAct() const;
	TEntityRef<ZActor> GetCurrentSpeaker() const;
	SActorSoundDefs::EDefinition GetCurrentSound() const;
	float GetTimeSinceCompleted() const;
	void SetPauseBeforeOverride(float fPauseBeforeTime);
	ZActorDialog(SActorSoundDefs::EDefinition eSound, const TEntityRef<ZActor>& rSpeaker);
	~ZActorDialog() = default;
};
