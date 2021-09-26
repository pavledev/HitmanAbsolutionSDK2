#pragma once

#include "TSharedPointer.h"

class ZResourceReader;

class ZUnsafeResourceReader
{
public:
	struct SPointer
	{
		const void* m_p;

		SPointer(const void* p);
	};

	TSharedPointer<ZResourceReader> m_pResourceReader;
	unsigned int m_nPrimaryOffset;

	ZUnsafeResourceReader() = default;
	ZUnsafeResourceReader(const TSharedPointer<ZResourceReader>& pResourceReader, unsigned int nPrimaryOffset);
	ZUnsafeResourceReader(const ZUnsafeResourceReader& PrimReader, unsigned int nPrimaryOffset);
	SPointer operator[](unsigned int nOffset) const;
	const TSharedPointer<ZResourceReader>& GetResourceReader() const;
	~ZUnsafeResourceReader() = default;
};
