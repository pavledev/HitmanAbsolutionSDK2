#pragma once

class ZResourceStub;

struct SResourceLibraryEntry
{
	ZResourceStub* pStub;
	unsigned int nDataSize;

	SResourceLibraryEntry() = default;
	~SResourceLibraryEntry() = default;
};
