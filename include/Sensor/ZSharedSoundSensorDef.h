#pragma once

#include "ZEntityImpl.h"

class ZSharedSoundSensorDef : public ZEntityImpl
{
public:
    float m_fHearRangeFootstep;
    float m_fHearRangeLoudFootstep;
    float m_fHearRangeBulletImpact;
    float m_fHearRangeBark;
    float m_fHearRangePain;
    float m_fHearRangeScream;
    float m_fHearRangeAlarm;
    float m_fHearRangeAccident;
    float m_fHearRangeExplosion;
    float m_fHearRangeGunShot;
    float m_fHearRangeGunSilenced;
    float m_fHearRangeEmptyGun;
    float m_fHearRangeCloseCombat;
    float m_fHearRangeCCBreakNeck;
    float m_fHearRangeCCFiberWire;
    float m_fHearRangeCCChoke;
    float m_fHearRangeCCHitFromBehind;
    float m_fHearRangeRadio;
    float m_fHearThrownItemCollision;
    float m_fHearRangeFootstepLimitVisionAreaRun;
    float m_fHearRangeFootstepLimitVisionAreaWalk;
    float m_fHearRangeFootstepLimitVisionAreaSneakWalk;
};
