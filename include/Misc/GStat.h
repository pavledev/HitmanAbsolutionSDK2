#pragma once

class GStat
{
public:
    enum StatType : __int32
    {
        Stat_LogicalGroup = 0x0,
        Stat_Memory = 0x1,
        Stat_Timer = 0x2,
        Stat_Counter = 0x3,
        Stat_TypeCount = 0x4
    };

    class StatValue
    {
    public:
        enum ValueType : __int32
        {
            VT_None = 0x0,
            VT_Int = 0x1,
            VT_Int64 = 0x2,
            VT_Float = 0x3
        } Type;

        const char* pName;
        
        union
        {
            unsigned int IValue;
            unsigned __int64 I64Value;
            float FValue;
        };
    };
};
