#pragma once

#include "ZEntityImpl.h"

class ZShootingBalletConfig : public ZEntityImpl
{
public:
    float m_fSBEnemyRadius;
    int m_iSBMaxNumTags;
    float m_fSBTagSequenceTimeMultiplier;
    float m_fSBTagTime;
    float m_fSBTagTimeRampUpFraction;
    float m_fSBTagTimeRampUpFocus;
    float m_fSBTagRampUpMultiplier;
    float m_fSBExecutionMultiplier;
    float m_fSBExecutionGameTime;
    float m_fSBImpulseMultiplier;
    float m_fSBDamageMultiplier;
    float m_fSBMinTagDistance;
    float m_fSBRushZoomTimeMul;
    int m_iSBTagSlots;
    float m_fSBTagSlotTime;
    float m_fSBTagSlotBonus;
    float m_fSBExecutionTimeMultiplier;
};
