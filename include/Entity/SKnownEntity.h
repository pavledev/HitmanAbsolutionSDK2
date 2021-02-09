#pragma once

#include "ZEntityRef.h"
#include "ZSharedKnowledgeRef.h"
#include "EKnownEntityPoseType.h"
#include "ZGameTime.h"

class SKnownEntity
{
public:
    ZEntityRef m_pActor;
    unsigned int m_nRefCount;
    ZSharedKnowledgeRef m_pSharedKnowledge;
    unsigned int m_nBooleanEvents;
    unsigned int m_nBooleanEventsHandled;
    TMaxArray<unsigned short, 16> m_events;
    EKnownEntityPoseType m_knownPose;
    SMatrix m_knownWorldMatrix;
    float4 m_vKnownVelocity;
    float4 m_vLastVelocityReferencePosition;
    ZGameTime m_tLastWorldMatrixUpdate;
    ZGameTime m_tLastVelocityUpdate;
};
