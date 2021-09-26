#pragma once

struct SRenderMappedTexture2D
{
	void* pData;
	unsigned int nRowPitch;

	SRenderMappedTexture2D() = default;
	~SRenderMappedTexture2D() = default;
};
