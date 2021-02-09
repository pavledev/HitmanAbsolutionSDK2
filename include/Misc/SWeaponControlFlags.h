#pragma once

struct SWeaponControlFlags
{
    union
    {
        unsigned int m_nWeaponControlFlags;
        
        struct
        {
            __int8 m_bFireWeapon : 1;
            __int8 m_bFireWeaponRelease : 1;
            __int8 m_bFireWeaponTap : 1;
            __int8 m_bFireStartedRight : 1;
            __int8 m_bFireStartedLeft : 1;
            __int8 m_bLastFireWeaponRight : 1;
            __int8 m_bPrecisionShoot : 1;
            __int8 m_bPrecisionShootRelease : 1;
            __int8 m_bPrecisionShootDownedge : 1;
            __int8 m_bPrecisionShootAudioSignalsBlocked : 1;
            __int8 m_bLastAimWeaponRight : 1;
            __int8 m_bFireBlocked : 1;
        };
    };
};
