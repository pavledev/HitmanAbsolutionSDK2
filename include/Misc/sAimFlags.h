#pragma once

struct sAimFlags
{
    union
    {
        unsigned int m_nAimFlags;
        
        struct
        {
            __int8 m_bRightHandAimInPlace : 1;
            __int8 m_bLeftHandAimInPlace : 1;
            __int8 m_bAimRight : 1;
            __int8 m_bAimLeft : 1;
        };
    };
};
