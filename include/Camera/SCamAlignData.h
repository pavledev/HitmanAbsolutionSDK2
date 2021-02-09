#pragma once

#include "SQV.h"

class alignas(16) SCamAlignData
{
public:
    SQV mObjectToWorld;
    SQV mViewToWorld;
    unsigned __int8 numBones;
    unsigned __int8* pBonesStart;
};
