#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZHM5SBCamHitmanProfile.h"
#include "ZHM5SBCamTargetProfile.h"
#include "ZHM5SBConfiguration.h"

class ZHM5SBCamProfiles : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZHM5SBCamHitmanProfile>> m_SBCamHitmanTargetProfiles;
    TArray<TEntityRef<ZHM5SBCamHitmanProfile>> m_SBCamHitmanViewProfiles;
    TArray<TEntityRef<ZHM5SBCamTargetProfile>> m_SBCamTargetProfiles;
    TEntityRef<ZHM5SBConfiguration> m_SBConfigurationShot;
    TEntityRef<ZHM5SBConfiguration> m_SBConfigurationBulletImpactPre;
    TEntityRef<ZHM5SBConfiguration> m_SBConfigurationBulletImpact;
    TEntityRef<ZHM5SBConfiguration> m_SBConfigurationHitmanView;
    TEntityRef<ZHM5SBConfiguration> m_SBConfigurationLastKill;
    float m_fMinTimeForHitmanView;
};
