#pragma once

#include "SFacePoseChannelInfo.h"
#include "SFacePoseSectionInfo.h"

struct SFacePoseFloatChannelCollection
{
    SFacePoseChannelInfo* m_pFacePoseChannels;
    SFacePoseSectionInfo* m_pFacePoseSectionInfos;
    unsigned int m_nSizeExcludingSections;
    unsigned __int16 m_nFacePoseChannelCount;
    unsigned __int16 m_nUncompressedPoseChannelSize;
    unsigned int m_nCompleteMemoryRequirements;
};
