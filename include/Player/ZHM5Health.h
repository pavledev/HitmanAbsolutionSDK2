#pragma once

#include "SDamageHistory.h"
#include "TEntityRef.h"
#include "SHitIndicator.h"
#include "ZMapPoly.h"

class ZHitman5;

class alignas(8) ZHM5Health
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
};
