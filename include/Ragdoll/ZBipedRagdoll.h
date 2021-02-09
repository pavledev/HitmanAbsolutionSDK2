#pragma once

#include "ZBaseRagdoll.h"
#include "ZAnimationBoneData.h"
#include "SPhysBone.h"

class ZBipedRagdoll
{
public:
    ZBaseRagdoll* m_pRagdoll;
    const ZAnimationBoneData* m_pBoneData;
    TArray<SPhysBone> m_aBoneMapping;
    unsigned int m_iRootId;
    bool m_bResetHead;
    unsigned int m_nForceMovingFrames;

    virtual ~ZBipedRagdoll();
    virtual void FrameUpdate();
};
