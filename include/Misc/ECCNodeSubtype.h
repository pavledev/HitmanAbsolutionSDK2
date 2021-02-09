#pragma once

enum ECCNodeSubtype : __int32
{
    eCCNodeSubtype_Left = 0x0,
    eCCNodeSubtype_Right = 0x1,
    eCCNodeSubtype_Front = 0x2,
    eCCNodeSubtype_Back = 0x3,
    eCCNodeSubtype_StairsAbove = 0x4,
    eCCNodeSubtype_StairsBelow = 0x5,
    eCCNodeSubtype_StairsAbove_Back = 0x6,
    eCCNodeSubtype_StairsBelow_Back = 0x7,
    eCCNodeSubtype_Front_Back = 0x8,
    eCCNodeSubtype_Count = 0x9
};
