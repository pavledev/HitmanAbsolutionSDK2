#pragma once

#include "TArray.h"

class ZString;
struct SHeaderLibraryChunk;

struct SHeaderLibrary
{
	TArray<SHeaderLibraryChunk> chunks;
	TArray<ZString> externalResourceIds;
	long long ridSource;

	SHeaderLibrary() = default;
	~SHeaderLibrary() = default;
};
