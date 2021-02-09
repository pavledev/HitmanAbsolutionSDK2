#pragma once

#include "TArrayRef.h"
#include "SQV.h"

class ZMeshRig
{
public:
    TArrayRef<int> m_meshIDToRigID;
    TArrayRef<int> m_meshHierarchy;
    TArrayRef<SQV const> m_meshBindPose;
    TArrayRef<unsigned short> m_globalIDToMeshID;
    TArrayRef<SQV> m_aObjectSpaceToBindPoseSpace;
    TArrayRef<SQV> m_aBindPoseSpaceToObjectSpace;
};
