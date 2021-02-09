#pragma once

enum ValueType : __int32
{
    VT_Undefined = 0x0,
    VT_Null = 0x1,
    VT_Boolean = 0x2,
    VT_Number = 0x3,
    VT_String = 0x4,
    VT_StringW = 0x5,
    VT_Object = 0x6,
    VT_Array = 0x7,
    VT_DisplayObject = 0x8,
    VT_ConvertBoolean = 0x82,
    VT_ConvertNumber = 0x83,
    VT_ConvertString = 0x84,
    VT_ConvertStringW = 0x85
};
