#pragma once

struct sOTSAimFlags
{
    union
    {
        unsigned int m_nOTSFlags;
        
        struct
        {
            __int8 m_bOTSPressed : 1;
            __int8 m_bOTSReleased : 1;
            __int8 m_bOTSTap : 1;
            __int8 m_mOTSLastState : 1;
            __int8 m_bOTSBlocked : 1;
        };
    };
};
