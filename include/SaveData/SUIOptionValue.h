#pragma once

class SUIOptionValue
{
public:
    unsigned int key;
    unsigned __int8 type;
    
    union
    {
        int intValue;
        float floatValue;
        bool boolValue;
    };
};
