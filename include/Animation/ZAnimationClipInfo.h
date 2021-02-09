#pragma once

#include "ZAnimationClipEntity.h"

class ZAnimationClipInfo
{
public:
    ZAnimationClipEntity* m_clip;
    unsigned __int16 m_clipIndex;
    unsigned int m_numFrames;
    unsigned int m_usedCount;
    unsigned int m_keyframeOffset;
};
