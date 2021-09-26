#pragma once

class ZFilterGroupMask
{
public:
	unsigned int m_nBits0;
	unsigned int m_nBits1;
	unsigned int m_nBits2;
	unsigned int m_nBits3;

	static ZFilterGroupMask m_snAllBitsOne;
	static ZFilterGroupMask m_snAllBitsZero;

	ZFilterGroupMask() = default;
	~ZFilterGroupMask() = default;
};
