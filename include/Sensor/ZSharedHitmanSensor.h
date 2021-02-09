#pragma once

#include "TMaxArray.h"
#include "SShotRecord.h"
#include "ZSharedKnowledgeRef.h"
#include "EGameTension.h"
#include "IAsyncRayHandle.h"
#include "ShitmanSensorRadarBlip.h"

class alignas(8) ZSharedHitmanSensor
{
    TMaxArray<SShotRecord, 32> m_aShotHistory;
    ZSharedKnowledgeRef m_pCurrentHitman;
    EGameTension m_eGameTension;
    ZGameTime m_NextFootstepSoundTime;
    unsigned int m_nShotAccuracyCacheFrame;
    float m_fShotAccuracy;
    bool m_bHitmanIsInCombat;
    bool m_bDisguiseBroken;
    bool m_bDisguiseTrespassing;
    bool m_bDisguiseIllegalAction;
    bool m_bDisguiseAttentionBoostForCombatChange;
    bool m_bIsRecievingHuntAttention;
    int m_nSoundDistanceUpdateIndex;
    IAsyncRayHandle* m_pRayCastHandle;
    TMaxArray<ShitmanSensorRadarBlip, 128> m_aRadarblips;
};
