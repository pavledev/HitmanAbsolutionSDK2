#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "IBoxVolumeEntity.h"
#include "TeleportActionType.h"

class ZCrowdTeleportEntity : public ZEntityImpl
{
public:
    TEntityRef<IBoxVolumeEntity> m_rExitZone;
    TEntityRef<IBoxVolumeEntity> m_rEnterZone;
    TeleportActionType m_eExitActionAmbient;
    TeleportActionType m_eExitActionScared;
    bool m_bOnlyCulled;
    bool m_bEnabled;
    unsigned int m_nFlowIndex;
};
