#pragma once

#include "ZHM5BaseController.h"
#include "ZMapPoly.h"

class ZHM5WeaponRecoil : public ZHM5BaseController
{
public:
    float m_fTime;
    float m_fRecoilDelay;
    float m_fRecoilTime;
    float m_fRecoilFraction;
    float m_fRecoilRecoverySpeed;
    float m_fRecoilDuration;
    float m_fRecoilMaxLength;
    float m_fRecoveryFraction;
    float m_fRecoveryDuration;
    float m_fRecoilTechniqueModifier;
    SVector2 m_vRecoil;
    SVector2 m_vAccumlatedRecoil;
    SVector2 m_vRecovery;
    ZMapPoly m_MapPoly;
    TEntityRef<ZHitman5> m_pHitman;
};
