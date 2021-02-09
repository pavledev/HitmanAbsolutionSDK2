#pragma once

enum EGameTension : __int32
{
    EGT_Undefined = 0x0,
    EGT_Ambient = 0x1,
    EGT_Agitated = 0x2,
    EGT_Searching = 0x3,
    EGT_AlertedLow = 0x4,
    EGT_AlertedHigh = 0x5,
    EGT_Hunting = 0x6,
    EGT_Arrest = 0x7,
    EGT_Combat = 0x8
};
