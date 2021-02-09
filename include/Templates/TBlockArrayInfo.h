#pragma once

#include "ZResourcePending.h"

template<class T>
struct TBlockArrayInfo
{
    unsigned int m_nOffset;
    unsigned int m_nSize;
    unsigned int m_nBlockCount;
    unsigned int m_nBlockSize;
    T** m_pBlockMap;
};
