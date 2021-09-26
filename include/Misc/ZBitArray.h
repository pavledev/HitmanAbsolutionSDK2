#pragma once

#include "TArray.h"

class ZBitArray
{
public:
	class ZRef
	{
	};

	class ZBitRef
	{
	public:
		ZBitArray& m_Self;
		unsigned int m_nIndex;

		operator bool() const;
		ZBitRef(ZBitArray& self, unsigned int nIndex);
	};

	TArray<unsigned char> m_aBytes;
	unsigned int m_nSize;

	static void RegisterType();
	ZBitArray(const ZBitArray& rhs);
	ZBitArray() = default;
	ZBitArray& operator=(const ZBitArray& rhs);
	~ZBitArray() = default;
	void Resize(unsigned int nBits);
	void Zero();
	bool Get(unsigned int nBitIndex) const;
	void Set(unsigned int nBitIndex, bool bVal);
	ZBitRef operator[](unsigned int nIndex);
};
