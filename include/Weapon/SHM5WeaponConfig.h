#pragma once

class alignas(4) SHM5WeaponConfig
{
public:
    float m_fDamageMultiplier;
    float m_fInitialMagazines;
    float m_fPrecisionMinDegree;
    float m_fPrecisionMaxDegree;
    float m_fRecoilX;
    float m_fRecoilZ;
    float m_fDamageClose;
    float m_fDamageNear;
    float m_fDamageMedium;
    float m_fDamageFar;
    float m_fRangeClose;
    float m_fRangeNear;
    float m_fRangeMedium;
    float m_fRangeFar;
    float m_fReloadSpeedFactor;
    int m_iBulletsPerMagazine;
    __int16 m_iShotsPerMinute;
    char m_iPrecisionNumBullets;
    unsigned __int8 m_iOperModes;
    
    union
    {
        unsigned __int8 m_nBools;
        
        struct
        {
            __int8 m_bInitialized : 1;
            __int8 m_bIsSilenced : 1;
            __int8 m_bIsRedDot : 1;
            __int8 m_bStartDualWield : 1;
        };
    };
};
