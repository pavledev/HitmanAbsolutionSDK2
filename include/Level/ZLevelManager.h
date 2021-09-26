#pragma once

#include "IComponentInterface.h"
#include "SSceneParameters.h"
#include "TResourcePtr.h"
#include "TEntityRef.h"
#include "ELevelIndex.h"
#include "SHM5TransitionMovieData.h"
#include "ECheckpointGameMode.h"
#include "STokenID.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TMap.h"
#include "ZEvent.h"
#include "ZString.h"
#include "ZVariantRef.h"

class IIniFile;
class ZEventNull;
class ZFocusConfig;
class ZHM5TutorialEventsEntity;
class ZHitman5;
class ZInvestigateRoomSetup;
class ZLeaderboard;
class ZObjectiveEntity;
class ZOutfitManagerEntity;
class ZRuntimeResourceID;
class ZShootingBalletConfig;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct SHitmanGameplayState;
struct SPackageListData;
struct STypeID;

class ZLevelManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	SSceneParameters m_SceneTransitionData;
	bool m_bInSceneTransition;
	TResourcePtr<SPackageListData> m_pLoadingPackageList;
	ZString m_PreloadedSceneID;
	TEntityRef<ZHitman5> m_rHitman;
	TEntityRef<ZFocusConfig> m_rFocusConfig;
	TEntityRef<ZShootingBalletConfig> m_rShootingBalletConfig;
	TEntityRef<ZOutfitManagerEntity> m_pOutfitManager;
	TEntityRef<ZHM5TutorialEventsEntity> m_pTutorialEntity;
	bool m_bIsSceneResetting : 1;
	bool m_bPendingReset : 1;
	bool m_bResetLevel : 1;
	bool m_bMoreThanOneHitmanInTheScene : 1;
	bool m_bHitmanInScene : 1;
	TMap<unsigned short, TEntityRef<ZInvestigateRoomSetup>> m_investigateRoomSetup;
	ELevelIndex m_eCurrentLevelIndex;
	ZEvent<TEntityRef<ZHitman5>, TEntityRef<ZHitman5>, ZEventNull, ZEventNull, ZEventNull> m_HitmanChangedListeners;
	TArray<TEntityRef<ZObjectiveEntity>> m_aActiveObjectiveList;
	TArray<TEntityRef<ZObjectiveEntity>> m_aObjectiveList;
	SHM5TransitionMovieData m_ForcedMovieToPlayAtNextLoadingScreen;
	ZLeaderboard* m_pLeaderboard;
	bool m_bLevelEnded;
	IIniFile* m_pIniFile;
	int m_iBenchmarkOldQualityProfile;
	bool m_bReturnToMainMenu;
	float m_fBenchmarkMinFPS;
	float m_fBenchmarkMaxFPS;
	double m_fBenchmarkTotalFrametime;
	unsigned int m_fBenchmarkFrames;
	float m_fBenchmarkResultsTime;
	unsigned int m_benchmarkUpdateTotalTC;
	unsigned int m_benchmarkUpdateFrameCount;
	float m_benchmarkUpdateLastFps;
	unsigned int m_benchmarkUpdateLastFrameTC;
	int m_iBenchmarkSceneIndex;
	bool m_iBenchmarkSequencePlaying;
	bool m_bFinishedBenchmark;
	short m_iBenchmarkSequence;
	short m_iBenchmarkTextID;
	bool m_iBenchmarkTextIDMenu;
	TArray<ZString> m_aBenchmarkScenes;
	TArray<TArray<int>> m_aBenchmarkSceneCheckpoints;
	TArray<TArray<bool>> m_aBenchmarkSceneCheckpointsTriggered;

	~ZLevelManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZLevelManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Deactivate();
	void SwitchToScene(ECheckpointGameMode eGameMode, const ZString& sceneResource, int nCheckpointIndex, const STokenID& sCheckpoint, STokenID BonusWeapon, STokenID BonusOutfit, bool bRestoring, bool bUseSaveGame);
	void RestartScene(int nCheckpointIndex, const STokenID& sCheckpoint, bool bRestoring);
	bool IsInSceneTransition() const;
	void SetInSceneTransition(bool bInTransition);
	const SSceneParameters& GetSceneParameters() const;
	void PreloadScene(const ZString& sceneResource);
	void OnPackageListStatusChanged(const ZRuntimeResourceID& rid);
	bool CanApplyUpgrades() const;
	const TEntityRef<ZHitman5>& GetHitman() const;
	const SHitmanGameplayState& GetHitmanGameplayState() const;
	void RegisterHitman(const TEntityRef<ZHitman5>& rHitman);
	void UnregisterHitman();
	void SetHitmanInScene(bool bInScene);
	ZEvent<TEntityRef<ZHitman5>, TEntityRef<ZHitman5>, ZEventNull, ZEventNull, ZEventNull>& GetHitmanChangedEvent();
	void ValidateMoreThanOneHitmanInTheScene() const;
	void ValidateHitmanInScene() const;
	const TEntityRef<ZFocusConfig>& GetFocusConfig() const;
	void RegisterFocusConfig(const TEntityRef<ZFocusConfig>& rFocusConfig);
	const TEntityRef<ZShootingBalletConfig>& GetShootingBalletConfig() const;
	void RegisterShootingBalletConfig(const TEntityRef<ZShootingBalletConfig>& rSBConfig);
	void SetOutfitManager(const TEntityRef<ZOutfitManagerEntity>& pManager);
	TEntityRef<ZOutfitManagerEntity> GetOutfitManager() const;
	void RegisterTutorialEntity(const TEntityRef<ZHM5TutorialEventsEntity>& pTutorialEntity);
	void UnregisterTutorialEntity();
	TEntityRef<ZHM5TutorialEventsEntity> GetTutorialEntity() const;
	TEntityRef<ZInvestigateRoomSetup> GetInvestigateRoomSetup(unsigned short roomID);
	void RegisterInvestigateRoomSetup(unsigned short roomID, const TEntityRef<ZInvestigateRoomSetup>& setup);
	void UnregisterInvestigateRoomSetup(unsigned short roomID, const TEntityRef<ZInvestigateRoomSetup>& setup);
	void RestartCheckpoint(bool bUseForwardSpawn, bool bUserInitiated);
	void RestartLevel();
	void LevelEnded();
	void Reset();
	void SetCurrentLevelIndex(ELevelIndex eLevelIndex);
	ELevelIndex GetCurrentLevelIndex() const;
	void RegisterObjective(const TEntityRef<ZObjectiveEntity>& pObjectiveEntity);
	void UnregisterObjective(const TEntityRef<ZObjectiveEntity>& pObjectiveEntity);
	TArrayRef<TEntityRef<ZObjectiveEntity>> GetObjectiveList() const;
	void RegisterActiveObjective(const TEntityRef<ZObjectiveEntity>& pObjectiveEntity);
	void UnregisterActiveObjective(const TEntityRef<ZObjectiveEntity>& pObjectiveEntity);
	TArrayRef<TEntityRef<ZObjectiveEntity>> GetActiveObjectiveList() const;
	bool IsCurrentLevelInGameFlow() const;
	void SetNextLoadingscreenVideo(const SHM5TransitionMovieData& moviedata);
	void ClearNextLoadingscreenVideo();
	void GetNextLoadingscreenVideo(SHM5TransitionMovieData& moviedata) const;
	ZLeaderboard* GetLeaderboard() const;
	void IntroMovieFinished(bool bMovieWasSkipped);
	void StopAllHaptics() const;
	void OnFrameUpdate(const SGameUpdateEvent& updateEvent);
};
