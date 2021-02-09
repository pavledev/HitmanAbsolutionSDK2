#pragma once

#include "TBag.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "IAsyncRayHandle.h"
#include "ZSharedKnowledgeRef.h"
#include "ZAIVisionBlockerPlane.h"
#include "SVisibilitySetting.h"

class ZActor;

//class alignas(16) SActorInfo
//{
//public:
//    TEntityRef<ZActor> pActor;
//    SMatrix mActorTransform;
//    SMatrix mHead;
//    EGameTension eTension;
//    EActorPerceptionSensitivity eSensitivity;
//    const SVisibilitySetting* pVisibilitySettings;
//};

enum EVisibilityVolume : __int32
{
    VV_NONE = 0x0,
    VV_CLOSE = 0x1,
    VV_PERIPHERAL = 0x2,
    VV_FOCUS = 0x3
};

class ZSharedVisibilitySensor
{
public:
    class SRayCast
    {
    public:
        IAsyncRayHandle* m_pCollisionHandle;
        TEntityRef<ZActor> m_pActor;
        ZSharedKnowledgeRef m_rObject;
        float4 m_vFrom;
        float4 m_vTo;
    };

    TBag<SRayCast, TMaxArray<SRayCast, 128>> m_rays;
    int m_nActorIndex;
    int m_nObjectIndex;
    char m_nBoneIndex;
    TMaxArray<TEntityRef<ZAIVisionBlockerPlane>, 32> m_visionBlockerPlanes;
};
