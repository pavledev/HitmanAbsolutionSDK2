#pragma once

#include "ZEntityImpl.h"
#include "SVisibilitySetting.h"
#include "SVector2.h"

class ZSharedSensorDef : public ZEntityImpl
{
public:
    TArray<SVisibilitySetting> m_VisibilitySetting;
    float m_fDisguiseAttractionDistanceNear;
    float m_fDisguiseAttractionDistanceMid;
    float m_fDisguiseAttractionDistanceFar;
    float m_fDisguiseAttractionDistanceInCrowdFactor;
    float m_fDisguiseAttentionTimeNear;
    float m_fDisguiseAttentionTimeMid;
    float m_fDisguiseAttentionTimeFar;
    float m_fDisguiseAttractionTimeInCrowdFactor;
    float m_fDisguiseFollowTime;
    float m_fTrespassingPeripheralAngle;
    float m_fTrespassingAttractionRunPenalty;
    float m_fTrespassingAttractionHumanShieldPenalty;
    float m_fTrespassingSoftSpottingTime;
    float m_fTrespassingSoftSpottingTimeCrowd;
    TArray<SVector2> m_TrespassingAttentionDuration;
    TArray<SVector2> m_TrespassingPeripheralAttentionDuration;
    float m_fHuntedPeripheralAngle;
    float m_fHuntedAttractionRunPenalty;
    float m_fHuntedAttractionHumanShieldPenalty;
    TArray<SVector2> m_HuntedAttentionDuration;
    TArray<SVector2> m_HuntedPeripheralAttentionDuration;
    float m_fAttentionDecreaseTime;
    float m_fLookAtMinAttention;
    float m_fTurnLookAtMinAttention;
    float m_nCrowdAttentionModifier[4];
    float m_nCrowdAttentionRangeModifier[4];
};
