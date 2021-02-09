#pragma once

#include "ESBHand.h"
#include "ESBRecoil.h"
#include "ESBWeaponType.h"
#include "ESBPose.h"

class SSBAnim
{
public:
    const char* m_pszStartPose;
    const char* m_pszEndPose;
    const char* m_pszWeaponAnimName;
    float m_fRotation;
    ESBHand m_eExecutingHand;
    ESBRecoil m_eRecoil;
    unsigned int m_nAnimNodeID;
    float m_fAnimationDuration;
    unsigned int m_nParentNodeID;
    bool m_bHipPose;
    bool m_bFromTagPose;
    bool m_bReloadAnim;
    bool m_bCamAnim1;
    bool m_bCamAnim2;
    ESBWeaponType m_eWeaponType;
    ESBPose m_eSBPose;
};
