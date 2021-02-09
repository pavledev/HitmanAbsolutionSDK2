#pragma once

#include "SQV.h"

struct SRawFacePose
{
    SQV* m_pBones;
    int* m_pBoneToMeshIDs;
    char* m_pName;
    __int16 m_nCount;
    __int16 m_nBlockCount;
};
