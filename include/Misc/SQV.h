#pragma once

#include "SQuaternion.h"

class SQV
{
public:
    SQuaternion m_Rotation;
    float4 m_Translation;

    enum EIdentity : __int32
    {
        IDENTITY = 0x0
    };
};
