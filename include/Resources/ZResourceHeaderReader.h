#pragma once

#include "SResourceHeaderHeader.h"
#include "EResourceReferenceFlags.h"

class ZRuntimeResourceID;

class ZResourceHeaderReader
{
public:
	enum
	{
		INTEGER_RESOURCEID_BIT = 2147483648
	};

	SResourceHeaderHeader m_HeaderHeader;
	const unsigned char* m_pReferencesChunk;

	ZResourceHeaderReader() = default;
	ZResourceHeaderReader(SResourceHeaderHeader headerHeader, const unsigned char* pReferencesChunk);
	~ZResourceHeaderReader() = default;
	unsigned int GetResourceType() const;
	unsigned int GetNumResourceIdentifiers() const;
	ZRuntimeResourceID GetResourceIdentifier(unsigned int lResourceIdentifierIndex) const;
	EResourceReferenceFlags GetResourceFlags(unsigned int lResourceIdentifierIndex) const;
	bool HasIntegerFormat() const;
};
