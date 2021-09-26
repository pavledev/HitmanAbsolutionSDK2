#pragma once

#include "TRefCountPtr.h"
#include "EActorDialogTrack.h"
#include "EAIEventType.h"
#include "SActorSoundDefs.h"
#include "TEntityRef.h"
#include "TFixedArray.h"
#include "TMaxArray.h"
#include "ZGameTime.h"
#include "ZSharedKnowledgeRef.h"

class ZActor;
class ZActorDialog;
template <class T> class TRefCountPtrArg;

class ZActorDialogManager
{
public:
	enum ESpeakStatus
	{
		SPEAK_PLAYING = 0,
		SPEAK_FAILED = 1,
		SPEAK_INTERRUPTED = 2,
		SPEAK_SUCCEEDED = 3
	};

	struct SSpeakEntry
	{
		ESpeakStatus m_status;
		SActorSoundDefs::EDefinition m_eSound;
		EAIEventType m_eAIEvent;
		TEntityRef<ZActor> m_rActor;
		TRefCountPtr<ZActorDialog> m_pDialog;
		ZGameTime m_tStarted;
		ZGameTime m_tEnded;

		SSpeakEntry(const SSpeakEntry& __that);
		SSpeakEntry() = default;
		~SSpeakEntry() = default;
		SSpeakEntry& operator=(const SSpeakEntry& __that);
	};

	struct SVoiceCooldownEntry
	{
		SActorSoundDefs::EDefinition m_eSound;
		ZGameTime m_tEnd;

		SVoiceCooldownEntry() = default;
	};

	int m_nRandSeed;
	TRefCountPtr<ZActorDialog> m_pUpdatingDialog;
	TFixedArray<TRefCountPtr<ZActorDialog>, 5> m_tracks;
	TMaxArray<SSpeakEntry, 16> m_speaks;
	TMaxArray<SVoiceCooldownEntry, 32> m_voiceCooldowns;

	ZActorDialogManager() = default;
	~ZActorDialogManager() = default;
	EActorDialogTrack GetDialogTrack(SActorSoundDefs::EDefinition eSound);
	float GetPlayChance(SActorSoundDefs::EDefinition eSound);
	bool IsTrackAvailable(SActorSoundDefs::EDefinition eSound);
	bool IsOnCooldown(SActorSoundDefs::EDefinition eSound);
	void StartEvalCooldown(SActorSoundDefs::EDefinition eSound);
	bool CanActorSpeak(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound);
	float CalculateActorWeight(const TEntityRef<ZActor>& pActor, SActorSoundDefs::EDefinition eSound, const ZSharedKnowledgeRef& rTarget);
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSound, const TEntityRef<ZActor>& rSpeaker);
	bool AddDialogEntry(TRefCountPtr<ZActorDialog> pDialog, SActorSoundDefs::EDefinition eSound, const TEntityRef<ZActor>& rSpeaker);
	void InterruptDialog(TRefCountPtrArg<ZActorDialog> pDialog, bool bStopSpeak);
	TRefCountPtr<ZActorDialog> FindActorDialog(const TEntityRef<ZActor>& rActor);
	void Reset();
	void Update();
	void OnSpeakStarted(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound);
	void OnSpeakInterrupted(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound);
	void OnSpeakFailed(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound);
	void OnSpeakEnded(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound);
	EActorDialogTrack FindActorDialogTrack(const TEntityRef<ZActor>& rActor);
	void UpdateSoundCooldowns(SActorSoundDefs::EDefinition eSound);
	void UpdateActiveSpeak(const TEntityRef<ZActor>& rActor, SActorSoundDefs::EDefinition eSound, ESpeakStatus status);
};
