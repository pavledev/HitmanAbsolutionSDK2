#pragma once

class SFloat16
{
public:
    unsigned __int16 m_value;

    enum UnkEnum : unsigned __int32
    {
        SIGN32_BITS = 0x1,
        EXPONENT32_BITS = 0x8,
        MANTISSA32_BITS = 0x17,
        SIGN32_MASK = 0x80000000,
        EXPONENT32_MASK = 0x7F800000,
        MANTISSA32_MASK = 0x7FFFFF,
        SIGN16_BITS = 0x1,
        EXPONENT16_BITS = 0x5,
        MANTISSA16_BITS = 0xA,
        SIGN16_LSB = 0xF,
        EXPONENT16_LSB = 0xA,
        MANTISSA16_LSB = 0x0,
        SIGN16_MASK = 0x8000,
        EXPONENT16_MASK = 0x7C00,
        MANTISSA16_MASK = 0x3FF,
    };
};
