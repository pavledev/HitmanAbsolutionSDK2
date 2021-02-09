#pragma once

#include "IComponentInterface.h"
#include "SSceneParameters.h"
#include "TResourcePtr.h"
#include "SPackageListData.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "ZFocusConfig.h"
#include "ZShootingBalletConfig.h"
#include "ZOutfitManagerEntity.h"
#include "ZHM5TutorialEventsEntity.h"
#include "ZInvestigateRoomSetup.h"
#include "ELevelIndex.h"
#include "ZObjectiveEntity.h"
#include "SHM5TransitionMovieData.h"
#include "ZLeaderboard.h"
#include "IIniFile.h"

class ZLevelManager : public IComponentInterface
{
public:
    SSceneParameters m_SceneTransitionData;
    bool m_bInSceneTransition;
    TResourcePtr<SPackageListData> m_pLoadingPackageList;
    ZString m_PreloadedSceneID;
    TEntityRef<ZHitman5> m_rHitman;
    TEntityRef<ZFocusConfig> m_rFocusConfig;
    TEntityRef<ZShootingBalletConfig> m_rShootingBalletConfig;
    TEntityRef<ZOutfitManagerEntity> m_pOutfitManager;
    TEntityRef<ZHM5TutorialEventsEntity> m_pTutorialEntity;
    __int8 m_bIsSceneResetting : 1;
    __int8 m_bPendingReset : 1;
    __int8 m_bResetLevel : 1;
    __int8 m_bMoreThanOneHitmanInTheScene : 1;
    __int8 m_bHitmanInScene : 1;
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
    long double m_fBenchmarkTotalFrametime;
    unsigned int m_fBenchmarkFrames;
    float m_fBenchmarkResultsTime;
    unsigned int m_benchmarkUpdateTotalTC;
    unsigned int m_benchmarkUpdateFrameCount;
    float m_benchmarkUpdateLastFps;
    unsigned int m_benchmarkUpdateLastFrameTC;
    int m_iBenchmarkSceneIndex;
    bool m_iBenchmarkSequencePlaying;
    bool m_bFinishedBenchmark;
    __int16 m_iBenchmarkSequence;
    __int16 m_iBenchmarkTextID;
    bool m_iBenchmarkTextIDMenu;
    TArray<ZString> m_aBenchmarkScenes;
    TArray<TArray<int>> m_aBenchmarkSceneCheckpoints;
    TArray<TArray<bool>> m_aBenchmarkSceneCheckpointsTriggered;
};
