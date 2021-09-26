#pragma once

#include "SDamageHistory.h"
#include "TEntityRef.h"
#include "SHitIndicator.h"
#include "ZMapPoly.h"
#include "ZGameTime.h"

class ZHitman5;
struct SGameUpdateEvent;
struct SHitInfo;

class ZHM5Health
{
public:
	int m_nDamageHistoryNext;
	SDamageHistory m_aDamageHistory[32];
	float m_fDamageHistoryLength;
	TEntityRef<ZHitman5> m_pHitman;
	bool m_bRefillHealth;
	bool m_bDrainHealth;
	float m_fHitPoints;
	float m_fMaxHitPoints;
	float m_fSoundStateHitpoints;
	ZGameTime m_ttLastBlur;
	bool m_bBlurActive;
	ZMapPoly m_BlurMap;
	bool m_bHeartBeatActive;
	ZGameTime m_ttNextHeartBeat;
	int m_nHINext;
	SHitIndicator m_aHitIncications[32];

	static const float s_fDefaultMaxHitPoints;
	static unsigned int m_snHeartbeat;
	static const int MAX_DAMAGE_HISTORY;
	static const int MAX_HIT_INDICATIONS;

	ZHM5Health() = default;
	ZHM5Health(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5Health() = default;
	void SetHPDirect(float fHP);
	void ResetHealthForRestoringFromLoad(float fHP);
	void RefillHealth();
	bool CanRefillHealth() const;
	bool IsRefillHealth() const;
	void SetDrainHealth(bool bDrainHealth);
	float GetHP() const;
	ZGameTime GetLastHitTime() const;
	void SetMaxHitPoints(float fVal);
	void Update(const SGameUpdateEvent& updateEvent);
	bool YouGotHit(const SHitInfo& HitInfo);
	void OnDie();
	void OnLooseTargetEncounterCut();
	float GetMaxHitpoints() const;
	void CutSequenceStarted();
	int GetMaxHitIndications() const;
	const SHitIndicator* GetHitIndications() const;
	void RecordDamage(float fDamage, ZGameTime tTime);
	float GetDamageOverTime(float fTime);
	void OnDamage(const SHitInfo& HitInfo, float fDamage);
	void DebugHitEffects();
	int GetHealthIntervalFromValue(float fValue) const;
	int GetCurrentHealthInterval() const;
	bool IsCriticalHealth() const;
	float GetHealthFromInterval(int iIdx) const;
	int GetNumberOfHealthIntervals() const;
	void SetRumble(float fLeft, float fRight);
	float GetCriticalHealthPrc(float fCutoffPrc) const;
	void ActivateBlur(const ZGameTime& GameTime);
	void RegisterHit(const SHitInfo& HitInfo);
	void UpdateHitIndications(float fDeltaTime);
};
