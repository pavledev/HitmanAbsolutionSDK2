#pragma once

class GFxResourceId
{
public:
    unsigned int Id;

    enum IdTypeConstants : __int32
    {
        IdType_Bit_IndexMask = 0xFFFF,
        IdType_Bit_TypeMask = 0xFFF0000,
        IdType_Bit_SWF = 0x0,
        IdType_Bit_Static = 0x10000,
        IdType_Bit_Export = 0x20000,
        IdType_Bit_GenMask = 0x30000,
        IdType_Bit_TypeShift = 0x12,
        InvalidId = 0x40000
    };

    enum IdType : __int32
    {
        IdType_None = 0x0,
        IdType_InternalConstant = 0x10000,
        IdType_GradientImage = 0x50000,
        IdType_DynFontImage = 0x90000,
        IdType_FontImage = 0x60000
    };
};
