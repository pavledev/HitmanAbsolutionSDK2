#pragma once

#include "ZAnimationBoneHierarchy.h"
#include "ZAnimationBonePose.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "THashMap.h"
#include "TDefaultHashMapPolicy.h"
#include "SMatrix43.h"
#include "SQV.h"

class alignas(4) ZAnimationRig
{
public:
    ZAnimationBoneHierarchy m_boneHierarchy;
    ZAnimationBonePose m_bindPose;
    TArray<ZString> m_boneNames;
    TArray<int> m_aMeshIDtoGlobalID;
    unsigned __int16* m_pGlobalToMeshID;
    TArrayRef<unsigned short> m_aGlobalToMeshID;
    THashMap<int, int, TDefaultHashMapPolicy<int, int> > m_globalIDToMeshID;
    SMatrix43* m_pObjectSpaceToBindPoseSpace;
    TArrayRef<SMatrix43> m_aObjectSpaceToBindPoseSpace;
    SQV* m_pObjectSpaceToBindPoseSpaceSQV;
    TArrayRef<SQV> m_aObjectSpaceToBindPoseSpaceSQV;
    SQV* m_pBindPoseSpaceToObjectSpaceSQV;
    TArrayRef<SQV> m_aBindPoseSpaceToObjectSpaceSQV;
    bool m_bGlobalDirty;

    virtual ~ZAnimationRig();
};
