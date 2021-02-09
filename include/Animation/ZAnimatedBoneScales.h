#pragma once

#include "SVector3.h"

class ZAnimatedBoneScales
{
public:
    SVector3* m_pBoneScales;
    int m_nNumberOfFrames;
    int m_nNumberOfChannels;
    int m_nFramesPerSecond;
};