#pragma once

#include "IGameStatsListener.h"
#include "EGameEventArgType.h"
#include "SGameEventArgs.h"
#include "TEntityRef.h"
#include "ZGameTime.h"

class ZActor;
class ZStopWatchEntity;
class ZString;
class ZTargetTracker;
class ZVariant;
template <class A, class B> class TMap;

class ZTargetTrackerGUI : public IGameStatsListener
{
public:
	ZTargetTracker* m_pTargetTracker;
	ZGameTime m_tLastTimerUpdate;
	ZGameTime m_tTargetUpdateDelay;
	bool m_bUpdate;
	bool m_bInitCalled;
	bool m_bTimerInitCalled;
	TEntityRef<ZStopWatchEntity> m_pTimer;

	~ZTargetTrackerGUI() override = default;
	void ProcessGameEvent(const SGameEventArgs& args) override;
	EGameEventArgType GetArgType() const override;

	ZTargetTrackerGUI() = default;
	ZTargetTrackerGUI(ZTargetTracker* pTargetTracker);
	void OnTargetChanged(TEntityRef<ZActor>& pTarget);
	void Update();
	int GetInfo(TMap<ZString, ZVariant>& info);
	void Reset();
	void SetTimer(TEntityRef<ZStopWatchEntity> pTimer);
	bool IsTargetDead(TEntityRef<ZActor>& pActor);
};
