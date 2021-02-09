#pragma once

#include "SSBCamHitmanProfile.h"
#include "ZLinkedEntity.h"

class ZHM5SBCameraProfileDatabase
{
public:
    SSBCamHitmanProfile m_aHitmanTargetView[64];
    unsigned int m_nNumHitmanTargetView;
    SSBCamHitmanProfile m_aHitmanView[64];
    unsigned int m_nNumHitmanView;
    ZLinkedEntity* m_pLinkedEntity;
};
