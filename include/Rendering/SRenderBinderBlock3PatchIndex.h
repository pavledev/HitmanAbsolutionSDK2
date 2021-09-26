#pragma once

struct SRenderBinderBlock3PatchIndex
{
	unsigned short nId;

	union 
	{
		unsigned short nSize;
		unsigned short nTempIndex;
	};

	unsigned char nType;

	SRenderBinderBlock3PatchIndex() = default;
	~SRenderBinderBlock3PatchIndex() = default;
	bool operator<(const SRenderBinderBlock3PatchIndex& r);
};
