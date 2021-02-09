#pragma once

#include "ZHM5BaseController.h"
#include "SAimCandidate.h"
#include "EAimAssistMode.h"

class alignas(16) ZHM5AimAssist : public ZHM5BaseController
{
public:
    float4 m_vClipPlanes[6];
    float4 m_vSlowDownClipPlanes[6];
    TArray<SAimCandidate> m_TargetCandidates;
    SMatrix m_mvInvFrustumBase;
    SAimCandidate m_BestCandidate;
    SAimCandidate m_BestSlowDownCandidate;
    float m_fSlowDownFactor;
    TEntityRef<ZHitman5> m_pHitman;
    bool m_bActorNearbyCrosshair;
    bool m_AAEnabled;
    EAimAssistMode m_eAimAssistMode;
};
