#pragma once

class ZString;

class ZGameTime
{
public:
	enum
	{
		FRACTION_BITS = 20
	};

	long long m_nTicks;

	static const long long FOREVER;
	static const long long SEC;

	static void RegisterType();
	ZGameTime(long long nTicks);
	ZGameTime(int nSeconds);
	ZGameTime(double fSeconds);
	ZGameTime(float fSeconds);
	~ZGameTime() = default;
	ZGameTime(const ZGameTime& tGameTime) = default;
	ZGameTime() = default;
	ZGameTime& operator=(const ZGameTime& lhs);
	operator float() const;
	operator long long() const;
	ZGameTime& operator+=(float rhs);
	ZGameTime& operator+=(const ZGameTime& rhs);
	ZGameTime& operator-=(float rhs);
	ZGameTime& operator-=(const ZGameTime& rhs);
	ZGameTime& operator*=(const ZGameTime& rhs);
	ZGameTime& operator/=(const ZGameTime& rhs);
	float ToFloat32() const;
	bool FromString(const ZString& sSrc);
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	void HumanReadableTime(unsigned int& hours, unsigned int& mins, unsigned int& secs, unsigned int& mili) const;
	ZString GetHumanReadableString() const;
	bool IsForever() const;
	static long long GetTicksFromSeconds(const double fSeconds);
	static long long GetTicksFromSeconds(const float fSeconds);
};
