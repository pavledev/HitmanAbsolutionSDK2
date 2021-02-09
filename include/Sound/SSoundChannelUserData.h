#pragma once

#include "ESoundChannelType.h"
#include "ZEntityImpl.h"

struct SSoundChannelUserData
{
public:
    ESoundChannelType m_eType;
    void* m_pInstancePtr;
    ZEntityImpl* m_pOwnerEntityPtr;
};
