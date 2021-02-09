#pragma once

#include "TResourcePtr.h"
#include "ZTextListData.h"

class SSubtitleRef
{
public:
    TResourcePtr<ZTextListData> m_TextlistResource;
    unsigned int m_nHashedLoganID;
};
