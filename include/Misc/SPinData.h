#pragma once

#include "SPinInfo.h"

struct SPinData
{
    unsigned int m_nPinID;
    int m_nOffsetToThisPtr;
    SPinInfo* m_pInfo;
};
