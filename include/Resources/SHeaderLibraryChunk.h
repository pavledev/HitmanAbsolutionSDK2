#pragma once

#include "ZString.h"
#include "TArray.h"

struct SHeaderLibraryChunk
{
	ZString sLibraryID;
	unsigned int nOffset;
	char nFlags;
	unsigned int localizationCategory;
	TArray<ZString> sLanguages;
	TArray<int> states;
	TArray<TArray<unsigned char>> resourceHeaders;
	TArray<unsigned int> ridMappingIndices;
	TArray<unsigned __int64> ridMappingIDs;

	SHeaderLibraryChunk() = default;
	~SHeaderLibraryChunk() = default;
};
