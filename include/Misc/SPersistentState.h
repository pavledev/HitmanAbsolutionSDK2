#pragma once

struct SPersistentState
{
    union
    {
        unsigned int m_unionInt;
        
        struct
        {
            __int8 m_bMappingsInitialized : 1;
            __int8 m_bOptionTriggersForShoot : 1;
            __int8 m_bOptionLeftHanded : 1;
            __int8 m_bOptionSwitchSticks : 1;
            __int8 m_bReInit : 1;
            __int8 m_bRemoveCameraControl : 1;
            __int8 m_bRemoveMovementControl : 1;
            __int8 m_bRemoveAimControl : 1;
        };
    };
};
