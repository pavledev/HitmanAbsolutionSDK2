#pragma once

#include "ZSoundChannelGroupBase.h"
#include "ESoundChannelGroup.h"

class ZSoundChannelGroup : public ZSoundChannelGroupBase
{
public:
    ZString m_sGroupName;
    TEntityRef<ISoundChannelGroup> m_pParentGroup;
    ESoundChannelGroup m_eParentMapping;
    ESoundChannelGroup m_eMapping;
};
