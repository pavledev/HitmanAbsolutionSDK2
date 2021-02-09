#pragma once

#include "SRawFacePose.h"

struct alignas(4) SFacePoseDescriptor
{
    unsigned int m_uid;
    SRawFacePose* m_pRawFacePose;
    unsigned __int16 m_nBlockCount;
};
