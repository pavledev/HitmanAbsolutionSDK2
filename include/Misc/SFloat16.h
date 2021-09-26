#pragma once

struct SFloat16
{
	enum
	{
		SIGN32_BITS = 1,
		EXPONENT32_BITS = 8,
		MANTISSA32_BITS = 23,
		SIGN32_MASK = 2147483648,
		EXPONENT32_MASK = 2139095040,
		MANTISSA32_MASK = 8388607,
		SIGN16_BITS = 1,
		EXPONENT16_BITS = 5,
		MANTISSA16_BITS = 10,
		SIGN16_LSB = 15,
		EXPONENT16_LSB = 10,
		MANTISSA16_LSB = 0,
		SIGN16_MASK = 32768,
		EXPONENT16_MASK = 31744,
		MANTISSA16_MASK = 1023
	};

	unsigned short m_value;

	SFloat16(float rhs);
	SFloat16() = default;
	~SFloat16() = default;
	operator float() const;
	static unsigned short Pack(float value);
	static float Unpack(unsigned short value);
};
