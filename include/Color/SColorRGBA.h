#pragma once

#include "ZString.h"

struct SColorRGBA
{
	float r;
	float g;
	float b;
	float a;

	static const SColorRGBA BLACK;
	static const SColorRGBA WHITE;

	SColorRGBA() = default;
	~SColorRGBA() = default;
	unsigned int GetAsUInt32() const;
	bool FromString(const ZString& sSrc);
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
};
