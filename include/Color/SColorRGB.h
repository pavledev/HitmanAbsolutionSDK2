#pragma once

struct float4;
class ZString;

struct SColorRGB
{
	float r;
	float g;
	float b;

	SColorRGB() = default;
	~SColorRGB() = default;
	float4 GetAsfloat4() const;
	unsigned int GetAsUInt32() const;
	bool operator==(const SColorRGB& rhs) const;
	bool FromString(const ZString& sSrc);
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
};
