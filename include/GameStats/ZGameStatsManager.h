#pragma once

#include "IComponentInterface.h"
#include "SGameStats.h"
#include "ELevelIndex.h"
#include "ZGameTime.h"
#include "ELastSoundTension.h"
#include "ZAIGameState.h"
#include "EKillType.h"
#include "SGameStatsWeapon.h"
#include "EGSBodyPart.h"
#include "EGSKillSituation.h"
#include "EActionKillsEvent.h"
#include "EStealthSituation.h"
#include "EGSExplodingPropType.h"
#include "EGSKillVictim.h"
#include "EActorDeathType.h"
#include "EGameTension.h"
#include "ZEvent.h"
#include "SGameEventArgs.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZCheckPointEntity;
class ZHitman5;
struct SGameUpdateEvent;
struct SHitInfo;
class IHM5Item;
class ZEventNull;
class IGameStatsListener;
class IReusableProp;
class ZAIEventEmitterEntity;
class ZActor;
struct SComponentMapEntry;
struct STypeID;
template <class T> class TEntityRef;

class ZGameStatsManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EAchievement40State
	{
		EAchievement40State_Inactive = 0,
		EAchievement40State_Active = 1,
		EAchievement40State_Completed = 2
	};

	struct SForwardSpawnTempData
	{
		bool m_bAnyDisguisesTaken;
		bool m_bSpottedOnCheckpoint;
		bool m_bPickedUpDisguiseOnCP[13];
	};

	bool m_bPickedUpDisguiseOnCP[13];
	SGameStats m_GameStats;
	unsigned int m_nTotalShotsFiredCP;
	unsigned int m_nShotsThatHitCP;
	unsigned int m_nTotalShotsFiredByWeaponClass[8];
	unsigned int m_nShotsThatHitByWeaponClass[8];
	unsigned int m_nTotalShotsFiredByWeaponClassPS[8];
	unsigned int m_nShotsThatHitByWeaponClassPS[8];
	int m_nCheckpointKills;
	int m_nCheckpointCrowdKills;
	int m_nCheckpointCrowdExplosionKills;
	ELevelIndex m_nPrevLevel;
	int m_nPrevCheckpoint;
	int m_nCPReplayCount;
	int m_nLevelReplayCount;
	int m_nNotebookOpenedCount;
	bool m_bTrackingPerfectHit;
	bool m_bHasPerfectHitRatio;
	bool m_bAnyShotsFired;
	bool m_bAnyDisguisesTaken;
	bool m_bHitmanRunning;
	bool m_bHitmanCrouching;
	bool m_bSpottedOnCheckpoint;
	bool m_bDebugKill;
	ZGameTime m_tLastShotTime;
	ZGameTime m_tCheckpointStartedTime;
	bool m_bSeenDraggingBody;
	ZGameTime m_LastTimeBodyDraggingSeen;
	bool m_bCaughtTrespassing;
	ZGameTime m_LastTimeCaughtTresspassing;
	TArray<IGameStatsListener*> m_aListeners;
	TArray<IReusableProp*> m_aReusableProps;
	TArray<int> m_aCurrentCheckPointStealthEvents;
	ELastSoundTension m_eLastSoundTension;
	SForwardSpawnTempData m_sForwardSpawnTempData;
	ZAIGameState m_GameState;
	ZAIGameState m_OldGameState;
	TArray<ZAIEventEmitterEntity*> m_nAIEventEmitters;
	ZEvent<EGameTension, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_GameTensionChangedEvent;
	EAchievement40State m_eAchievement40State;
	float m_fAchievement40Timer;
	bool m_bTrackAchievement31;
	int m_nTrackAchievement31NumKills;

	~ZGameStatsManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZGameStatsManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void GameStarted();
	void RegisterListener(IGameStatsListener* pListener);
	void UnregisterListener(IGameStatsListener* pListener);
	void ProcessGameEvent(const SGameEventArgs& args);
	void RegisterReusableProp(IReusableProp* prop);
	void UnregisterReusableProp(IReusableProp* prop);
	void RegisterKill(const TEntityRef<ZActor> pActor, EActorDeathType eDeathType, const TArray<SHitInfo>& aHitInfoList, bool bDeathMarked, EKillType eKillType, TEntityRef<IHM5Item> rItem);
	void IncrementKillCount(const TEntityRef<ZActor>& pActor, SGameStatsWeapon eWeapon, EGSBodyPart eBodyPart, EGSKillSituation eSituation, EActionKillsEvent eActionKill, unsigned int killflags);
	void IncrementKillCountCrowd(SGameStatsWeapon eWeapon, EGSBodyPart eBodyPart, EGSKillSituation eSituation, unsigned int killflags);
	void UpdateHitRatio();
	void IncrementStrayBulletCount();
	void DamageWasTaken(float fDamage);
	void TriggerStealthSituation(EStealthSituation eSituation);
	void CheckPointActivated(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void CheckPointDeactivated(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void SetHitmanRunning(bool running);
	bool GetHitmanRunning() const;
	void SetHitmanCrouching(bool crouching);
	bool GetHitmanCrouching() const;
	void IncrementHMShotCount(const SGameStatsWeapon& weapon);
	void IncrementActorDamage(SGameStatsWeapon eWeapon, EGSBodyPart eBodyPart);
	void IncrementExplodingProp(EGSExplodingPropType eProp);
	int GetKillCountByWeapon(SGameStatsWeapon eWeapon);
	int GetKillCountByBodyPart(EGSBodyPart eBodyPart);
	int GetKillCountBySituation(EGSKillSituation eSituation);
	int GetKillCountByVictim(EGSKillVictim eVictim);
	int GetCheckpointKills();
	unsigned int GetContractsCompleted();
	void IncrementContractsCompleted(unsigned int amount);
	unsigned int GetContractsCreated();
	void IncrementContractsCreated(unsigned int amount);
	int GetTotalMoneyEarned();
	void IncrementTotalMoneyEarned(int amount);
	int GetTotalMoneySpent();
	void IncrementTotalMoneySpent(int amount);
	ZGameTime GetTimeSpentInFirefights();
	void IncrementTimeSpentInFirefights(ZGameTime amount);
	float GetDamageTaken();
	void IncrementDamageTaken(float amount);
	float GetHealthReplenished();
	void IncrementHealthReplenished(float amount);
	float GetHitRatio();
	void IncrementHitRatio(float amount);
	float GetHitRatioPistol();
	void IncrementHitRatioPistol(float amount);
	float GetHitRatioSniper();
	void IncrementHitRatioSniper(float amount);
	float GetHitRatioSMG();
	void IncrementHitRatioSMG(float amount);
	float GetHitRatioShotgun();
	void IncrementHitRatioShotgun(float amount);
	float GetHitRatioAssault();
	void IncrementHitRatioAssault(float amount);
	float GetHitRatioRevolver();
	void IncrementHitRatioRevolver(float amount);
	unsigned int GetBodiesHidden();
	void IncrementBodiesHidden(unsigned int amount);
	unsigned int GetDisguisesPickedUp();
	void IncrementDisguisesPickedUp(unsigned int amount);
	unsigned int GetContainersEntered();
	void IncrementContainersEntered(unsigned int amount);
	unsigned int GetFuseBoxesDisabled();
	void IncrementFuseBoxesDisabled(unsigned int amount);
	unsigned int GetSuccessfulBlendIns();
	void IncrementSuccessfulBlendIns(unsigned int amount);
	unsigned int GetCaughtDraggingBody();
	void IncrementCaughtDraggingBody(unsigned int amount);
	unsigned int GetCaughtTrespassing();
	void IncrementCaughtTrespassing(unsigned int amount);
	unsigned int GetDisguisesBlown();
	void IncrementDisguisesBlown(unsigned int amount);
	unsigned int GetKnockoutByHand();
	void IncrementKnockoutByHand(unsigned int amount);
	unsigned int GetKnockoutsByProp();
	void IncrementKnockoutsByProp(unsigned int amount);
	unsigned int GetNPCsKilled();
	void IncrementNPCsKilled(unsigned int amount);
	unsigned int GetHeadshots();
	void IncrementHeadshots(unsigned int amount);
	unsigned int GetFiberwires();
	void IncrementFiberwires(unsigned int amount);
	unsigned int GetDeadlyThrows();
	void IncrementDeadlyThrows(unsigned int amount);
	unsigned int GetPropKills();
	void IncrementPropKills(unsigned int amount);
	unsigned int GetPullOfLedges();
	void IncrementPullOfLedges(unsigned int amount);
	unsigned int GetPushOverRailings();
	void IncrementPushOverRailings(unsigned int amount);
	unsigned int GetShootingBalletKills();
	void IncrementShootingBalletKills(unsigned int amount);
	unsigned int GetKillshotsFromCover();
	void IncrementKillshotsFromCover(unsigned int amount);
	unsigned int GetActionKillsTriggered();
	void IncrementActionKillsTriggered(unsigned int amount);
	unsigned int GetKillShotsPistol();
	void IncrementKillShotsPistol(unsigned int amount);
	unsigned int GetKillShotsSniper();
	void IncrementKillShotsSniper(unsigned int amount);
	unsigned int GetKillShotsSMG();
	void IncrementKillShotsSMG(unsigned int amount);
	unsigned int GetKillShotsShotgun();
	void IncrementKillShotsShotgun(unsigned int amount);
	unsigned int GetKillShotsAssault();
	void IncrementKillShotsAssault(unsigned int amount);
	unsigned int GetKillShotsRevolver();
	void IncrementKillShotsRevolver(unsigned int amount);
	unsigned int GetCiviliansKilled();
	void IncrementCiviliansKilled(unsigned int amount);
	unsigned int GetCopsKilled();
	void IncrementCopsKilled(unsigned int amount);
	unsigned int GetPigsBlownUp();
	void IncrementPigsBlownUp(unsigned int amount);
	unsigned int GetPigeonsKilled();
	void IncrementPigeonsKilled(unsigned int amount);
	ZGameTime GetTimePlayed();
	void IncrementTimePlayed(ZGameTime amount);
	ZGameTime GetTimeSpentInInstinctMode();
	void IncrementTimeSpentInInstinctMode(ZGameTime amount);
	ZGameTime GetTimeSpentInCover();
	void IncrementTimeSpentInCover(ZGameTime amount);
	unsigned int GetLedgesUsed();
	void IncrementLedgesUsed(unsigned int amount);
	float GetMilesDraggingBodies();
	void IncrementMilesDraggingBodies(float amount);
	float GetMilesRunned();
	void IncrementMilesRunned(float amount);
	float GetMilesWalked();
	void IncrementMilesWalked(float amount);
	unsigned int GetWindowsEntered();
	void IncrementWindowsEntered(unsigned int amount);
	float GetMilesStealthed();
	void IncrementMilesStealthed(float amount);
	unsigned int GetRemotelyDetonations();
	void IncrementRemotelyDetonations(unsigned int amount);
	unsigned int GetBarrelsBlownUp();
	void IncrementBarrelsBlownUp(unsigned int amount);
	unsigned int GetCarsBlownUp();
	void IncrementCarsBlownUp(unsigned int amount);
	unsigned int GetPetrolCansBlownUp();
	void IncrementPetrolCansBlownUp(unsigned int amount);
	unsigned int GetGasCanistersBlownUp();
	void IncrementGasCanistersBlownUp(unsigned int amount);
	unsigned int GetGasTanksBlownUp();
	void IncrementGasTanksBlownUp(unsigned int amount);
	unsigned int GetLandminesBlownUp();
	void IncrementLandminesBlownUp(unsigned int amount);
	unsigned int GetFireworksBoxesBlownUp();
	void IncrementFireworksBoxesBlownUp(unsigned int amount);
	bool HasPerfectHitRatio() const;
	void UpdateKillCount(int cnt, SGameStatsWeapon eWeapon);
	bool IsPerfectShooter() const;
	bool AnyDisguisesTaken(int cp) const;
	int GetStealthSituationCount(EStealthSituation eSituation);
	int GetExplodingPropCount(EGSExplodingPropType eExplodingProp);
	void SetNumberSBVictims(int nVictims);
	void ClearAll();
	void ClearFromDisk();
	void ClearGameStatsData();
	void FrameUpdate(const SGameUpdateEvent& __formal);
	void SetDebugKill(bool b);
	bool GetDebugKill();
	void SaveGameStats();
	ZEvent<EGameTension, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetGameTensionChangedEvent();
	bool WasSpottedOnCheckpoint() const;
	void StoreForwardSpawnStats();
	void RestoreForwardSpawnStats();
	ZGameTime GetCheckpointStartedTime() const;
	int GetCrowdKillsOnCheckpoint() const;
	int GetCrowdExplosionKillsOnCheckpoint() const;
	int GetCheckpointReplayCount() const;
	int GetLevelReplayCount() const;
	int GetNotebookOpenedCount() const;
	void IncrementLevelReplayCount();
	void IncrementCheckpointReplayCount();
	void IncrementNotebookOpenedCount();
	EGSKillVictim GetKillTarget(const TEntityRef<ZActor>& pActor) const;
	void EnablePerfectHitTracking(bool bEnable);
	SHitInfo GetKillingHit(const TArray<SHitInfo>& aHitInfoList) const;
	SGameStatsWeapon GetWeaponForStats(const SHitInfo& hitInfo) const;
	SGameStatsWeapon GetWeaponForItem(TEntityRef<IHM5Item> item) const;
	EGSBodyPart GetBodyPartForStats(const TEntityRef<ZActor> pActor, const SHitInfo& hitInfo) const;
	EActionKillsEvent SignalActionKill(const TEntityRef<ZActor> pActor, EGSBodyPart eBodyPart, SGameStatsWeapon eWeapon, const SHitInfo& killingHit) const;
	bool TestKillingHitInCameraView(const TEntityRef<ZHitman5>& rHitman, const SHitInfo& killingHit) const;
	void ResetAIState();
	void RegisterAIEventEmitter(ZAIEventEmitterEntity* pAIEventEmitter);
	void UnregisterAIEventEmitter(ZAIEventEmitterEntity* pAIEventEmitter);
	ZAIGameState& GetAIGameState();
	void SendAISignals();
	void SignalSoundTensionAmbient();
	void SignalSoundTensionUpToYellow();
	void SignalSoundTensionDownToYellow();
	void SignalSoundTensionUpToOrange();
	void SignalSoundTensionDownToOrange();
	void SignalSoundTensionUpToRed();
};
