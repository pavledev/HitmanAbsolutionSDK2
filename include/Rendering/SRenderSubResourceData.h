#pragma once

struct SRenderSubResourceData
{
	const void* pSysMem;
	unsigned int nSysMemPitch;
	unsigned int nSysMemSlicePitch;

	SRenderSubResourceData() = default;
	~SRenderSubResourceData() = default;
};
