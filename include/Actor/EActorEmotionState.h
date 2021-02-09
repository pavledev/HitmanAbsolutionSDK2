#pragma once

enum EActorEmotionState : unsigned __int32
{
    AES_Ambient = 0x0,
    AES_Alerted = 0x1,
    AES_Scared = 0x2,
    AES_Hunt = 0x3,
    AES_Combat = 0x4,
    AES_None = 0xFFFFFFFF
};
