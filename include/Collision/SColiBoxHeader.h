#pragma once

struct SColiBoxHeader
{
	unsigned short nNumChunks;
	unsigned short nTriPerChunk;

	SColiBoxHeader() = default;
	~SColiBoxHeader() = default;
};
