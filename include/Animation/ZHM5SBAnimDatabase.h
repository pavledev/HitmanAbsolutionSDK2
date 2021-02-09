#pragma once

#include "SSBAnim.h"
#include "SHM5SBShared.h"

class ZHM5SBAnimDatabase
{
public:
    char m_szPoseBuffer[1024];
    char* m_pBufferEnd;
    SSBAnim m_aSBAnim[96];
    unsigned int m_nNumAnims;
    const SHM5SBShared* m_SBShared;
    unsigned int m_nTagNode;
    unsigned int m_nExecutionNode;
    SBWeaponNodes m_aWeaponNodes[4];
    ESBWeaponType m_eCurrentSBWeapon;

    struct GetNextAnim
    {
        struct __l4
        {
            struct SSBAnimDifference
            {
                const SSBAnim* m_pAnimation;
                float m_fDifference;
                float m_fScale;
            };
        };
    };

    struct VerifySBWeaponType
    {
        struct __l50
        {
            struct SPoseConstrain
            {
                unsigned int m_nBoneID0;
                unsigned int m_nBoneID1;
                float m_fDistance;
            };
        };
    };

    struct FindAnimations
    {
        struct __l31
        {
            struct SSBPose
            {
                ESBPose m_eSBPose;
                ESBWeaponType m_eWeaponType;
                const char* m_pszPose;
            };
        };
    };
};
