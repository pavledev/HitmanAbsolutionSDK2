#pragma once

enum ERegionMask : __int32
{
    eRM_None = 0x1,
    eRM_LowCover = 0x2,
    eRM_HighCover = 0x4,
    eRM_Stairs = 0x8,
    eRM_Separator = 0x10,
    eRM_User_1 = 0x20,
    eRM_User_2 = 0x40,
    eRM_User_3 = 0x80,
    eRM_User_4 = 0x100,
    eRM_User_5 = 0x200,
    eRM_User_6 = 0x400,
    eRM_User_7 = 0x800,
    eRM_User_8 = 0x1000
};
