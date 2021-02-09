#pragma once

#include "SQV.h"
#include "SBoneDefinition.h"
#include "SBoneConstraintsHeader.h"
#include "BoneIdSystem.h"

class alignas(4) SCalcDeformBoneData
{
    SQV* m_pBoneCache;
    unsigned int m_nBoneCacheSize;
    float4* m_pMinBound;
    float4* m_pMaxBound;
    const unsigned __int16* m_pGlobalToMeshId;
    unsigned int m_nGlobalToMeshIdSize;
    const SQV* m_pBindPose;
    unsigned int m_nBindPoseSize;
    const int* m_pHierarchy;
    const SBoneDefinition* m_pBoneDefinition;
    const SBoneConstraintsHeader* m_pBoneConstraintsHeader;
    unsigned int m_nBoneConstraintsBytes;
    __int8 m_bCalcTwistBones : 1;
    __int8 m_bCalcConstraintBones : 1;
    BoneIdSystem m_BoneIdData;
};
