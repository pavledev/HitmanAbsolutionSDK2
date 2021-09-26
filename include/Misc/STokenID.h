#pragma once

class ZString;

struct STokenID
{
	unsigned int m_iValue;
	bool m_bValid;

	static STokenID InvalidToken;

	STokenID(unsigned int iValue);
	STokenID() = default;
	~STokenID() = default;
	bool operator==(const STokenID& a) const;
	bool operator!=(const STokenID& a) const;
	bool operator<(const STokenID& a) const;
	ZString ToString() const;
	unsigned int Get() const;
};
