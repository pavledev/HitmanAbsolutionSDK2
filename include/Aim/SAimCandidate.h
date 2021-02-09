#pragma once

#include "EAimCandidateType.h"
#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"
#include "SMatrix.h"
#include "float1.h"
#include "ZActor.h"

class SAimCandidate
{
public:
    EAimCandidateType m_eType;
    alignas(16) ZRayQueryInput m_ColiIn;
    ZRayQueryOutput m_ColiOut;
    SMatrix m_mvMatCen;
    float4 m_vHalfSize;
    float m_fZ;
    float m_fDistSq;
    float m_fDistMult;
    float1 m_fDist;

    union
    {
        unsigned __int8 m_nFlags;
        
        struct
        {
            __int8 m_bExcluded : 1;
            __int8 m_bRayCast : 1;
            __int8 m_bExcludeFromSlowdown : 1;
        };
    };


    TEntityRef<ZActor> m_Actor;
    unsigned int m_nBoneId;
    TEntityRef<ZSpatialEntity> m_rPropEntity;
};
