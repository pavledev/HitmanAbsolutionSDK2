#pragma once

#include "SFacePoseDescriptor.h"

struct alignas(4) SRawFacePoseCollection
{
    SFacePoseDescriptor* m_pCollection;
    int* m_pFaceBonesIndexes;
    unsigned __int16 m_nCollectionSize;
    unsigned __int16 m_nNumFaceBones;
    unsigned __int16 m_nBlockCount;
};
