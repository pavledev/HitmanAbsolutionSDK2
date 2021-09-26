#pragma once

struct SRenderMappedTexture3D
{
	void* pData;
	unsigned int nRowPitch;
	unsigned int nSlicePitch;

	SRenderMappedTexture3D() = default;
	~SRenderMappedTexture3D() = default;
};
