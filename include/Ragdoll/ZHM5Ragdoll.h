#pragma once

#include "ZBipedRagdoll.h"
#include "SPowerSettings.h"

class alignas(16) ZHM5Ragdoll : public ZBipedRagdoll
{
public:
    bool m_bPowered;
    bool m_bDrivesEnabled;
    float m_fPoweredTime;
    float m_fPoweredSyncTime;
    float m_fLastTM;
    TArray<SMatrix43> m_TargetPose;
    TArray<SMatrix43> m_PreviousTargetPose;
    SPowerSettings m_powerSettings;
    int m_nRootBodyLowVelFrames;
    float4 m_aRootPosSamples[10];
    float m_aSimEndTimes[10];
    unsigned __int16 m_nCurRootPosIndex;

    enum UnkEnum : __int32
    {
        NUM_ROOT_POS_SAMLES = 0xA
    };

    virtual void FrameUpdate();
};
