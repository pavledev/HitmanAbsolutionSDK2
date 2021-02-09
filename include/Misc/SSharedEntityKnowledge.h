#pragma once

#include "EKnownEntityType.h"
#include "SMatrix.h"
#include "ZEntityRef.h"
#include "TMaxArray.h"
#include "SAISharedEvent.h"
#include "EAISharedEventType.h"
#include "EActorType.h"
#include "EActorRank.h"

class alignas(16) SSharedEntityKnowledge
{
public:
    EKnownEntityType m_type;
    SMatrix m_actualWorldMatrix;
    bool m_bPerceptible;
    ZEntityRef m_pEntity;

    union
    {
        struct
        {
            __int32 m_actorType : 16;
            __int32 m_actorRank : 16;
        };

        float m_fWalkingDistance;
        float m_radius;
    };

    unsigned __int16 m_room;
    struct ZSituationInstance* m_pCurrentSituation;
    TMaxArray<unsigned short, 64> m_sharedEvents;
    TMaxArray<unsigned char, 64> m_sharedEventTypes;
    ZEntityRef m_pOutfit;
    int m_nRefCount;

    EKnownEntityType GetType();
    static SAISharedEvent* GetEventFromIndex(unsigned __int16 index);
    SAISharedEvent* GetSharedEvent(EAISharedEventType type);
    bool IsCurrent(EAISharedEventType type);
    int ExpireSharedEvent(EAISharedEventType type, float fDelay);
    bool RemoveExpiredSharedEvents();
    SAISharedEvent* CreateSharedEvent(EAISharedEventType type);
    bool NewSharedEvent(EAISharedEventType type, float duration);
    bool RenewSharedEvent(EAISharedEventType type, float duration);
    bool MinSharedEventAge(EAISharedEventType type, float fSeconds);
    bool MaxSharedEventAge(EAISharedEventType type, float fSeconds);
    void IncRefCount(unsigned int nMemDebugID);
    void DecRefCount(unsigned int nMemDebugID);
    float4* ActualPosition(float4* result);
    bool MaxSharedEventExpired(EAISharedEventType type, float fSeconds);
    bool MinSharedEventExpired(EAISharedEventType type, float fSeconds);
    ZEntityRef* GetOutfit(ZEntityRef* result);
    void SetOutfit(ZEntityRef pOutfit);
    ~SSharedEntityKnowledge();
    SSharedEntityKnowledge();
    EActorType GetActorType();
    EActorRank GetActorRank();
};
