#pragma once

#include "TEntityRef.h"
#include "ZSpatialEntity.h"

class SBoneAttachment
{
public:
    unsigned int m_nBoneID;
    TEntityRef<ZSpatialEntity> m_Attachment;
};
