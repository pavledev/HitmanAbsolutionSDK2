#pragma once

#include "ZCrowdEntity.h"
#include "SCrowdAnimData.h"
#include "ZMeshRig.h"

class ZCrowdAnimationState
{
public:
    ZCrowdEntity* m_pCrowd;
    bool m_bInitialized;
    unsigned int m_nMaxNumVisibleCharacters;
    unsigned int m_nRagdollPoolSize;
    unsigned int m_nMaxBoneCacheSize;
    TArray<unsigned char> m_aRagdollIndices;
    TArray<unsigned short> m_aPossessedAnimIndices;
    unsigned int m_nNumTotalRagdollBones;
    unsigned int m_nNumTotalPossessedBones;
    TArray<ZAnimationLibrary*> m_aAnimationLibraries;
    TArray<TPair<unsigned int, unsigned int> > m_aAnimationLibBufferLocation;
    TArray<SQV*> m_apRenderPoses;
    TArray<SCrowdAnimData> m_aCrowdAnimData;
    TArray<ZAnimationBoneData const*> m_aBoneData;
    TArray<int> m_aAnimLibIndex;
    TArray<ZMeshRig> m_aMeshRigs;
    TArray<ZAnimationBonePose*> m_aTemporaryBonePose;
    unsigned int m_nRagdollStorageBegin;
    unsigned int m_nPossessedAnimStorageBegin;
    TArray<SQV> m_aRenderPosesStorage;
    TArray<SQV> m_aUnitBones;
};
