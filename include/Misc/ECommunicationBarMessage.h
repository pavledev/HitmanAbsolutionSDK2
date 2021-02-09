#pragma once

enum ECommunicationBarMessage : __int32
{
    ECBM_Unknown = 0x0,
    ECBM_Clear = 0x1,
    ECBM_Searching = 0x2,
    ECBM_Alerted = 0x3,
    ECBM_Hunting = 0x4,
    ECBM_Hostile = 0x5,
    ECBM_Suspicious = 0x6
};
