#pragma once

#include "ZAnimationBoneData.h"
#include "TMap.h"
#include "ZChildNetworkEntry.h"
#include "SCutSequenceData.h"
#include "BoneIdSystem.h"

class SMorphemeData
{
public:
    ZAnimationBoneData* m_pBoneData;
    TArray<int>* m_pMeshIDToRigID;
    TMap<unsigned int, ZChildNetworkEntry>* m_pChildNetworks;
    ZMorphemeNetworkInstance* m_pParentNetwork;
    unsigned __int16* m_pGlobalToMeshId;
    unsigned int m_nGlobalToMeshIdSize;
    const SBoneConstraintsHeader* m_pBoneConstraintsHeader;
    unsigned int m_nBoneConstraintsBytes;
    BoneIdSystem m_BoneIdData;

    virtual ~SMorphemeData();
    virtual const SCutSequenceData* GetCutSequenceData(const char*);
    virtual unsigned int GetNumberOfDeformBones();
    virtual const TArrayRef<SQV>* GetMeshBindPose(const TArrayRef<SQV>* result);
    virtual int* GetMeshIDToRigIDMap();
    virtual int* GetMeshHierarchy();
    virtual const SBoneDefinition* GetBoneDefinitions();
};
