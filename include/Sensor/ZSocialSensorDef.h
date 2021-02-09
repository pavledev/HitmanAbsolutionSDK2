#pragma once

#include "ZEntityImpl.h"

class ZSocialSensorDef : public ZEntityImpl
{
public:
    float m_fDistLookAt;
    float m_fDistLookAtAttention;
    float m_fCooldownLookAt;
    float m_fLookAtTimeMin;
    float m_fLookAtTimeMax;
    float m_fDistGreeting;
    float m_fCooldownGreeting;
    float m_fCooldownHitmanGreeting;
    float m_fCooldownGreetingLastSpeak;
    float m_fCooldownGreetingSequence;
    float m_fCooldownGreetingAlertLevel;
    float m_fDistSilly;
    float m_fCooldownSilly;
    float m_fCondSillyTime;
    float m_fDistRunning;
    float m_fCooldownRunning;
    float m_fDistStanding;
    float m_fDistCollision;
    float m_fCondStandingTime;
    float m_fCooldownStanding;
};
