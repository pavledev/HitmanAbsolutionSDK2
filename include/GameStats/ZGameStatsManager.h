#pragma once

#include "IComponentInterface.h"
#include "SGameStats.h"
#include "ELevelIndex.h"
#include "ZGameTime.h"
#include "IGameStatsListener.h"
#include "IReusableProp.h"
#include "ELastSoundTension.h"
#include "SForwardSpawnTempData.h"
#include "ZAIGameState.h"
#include "ZAIEventEmitterEntity.h"
#include "EAchievement40State.h"

class alignas(8) ZGameStatsManager : public IComponentInterface
{
public:
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
    ZEvent<enum EGameTension, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_GameTensionChangedEvent;
    EAchievement40State m_eAchievement40State;
    float m_fAchievement40Timer;
    bool m_bTrackAchievement31;
    int m_nTrackAchievement31NumKills;
};
