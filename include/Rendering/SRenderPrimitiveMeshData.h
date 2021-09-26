#pragma once

struct SRenderPrimitiveMeshData
{
	void* pVertexData[4];
	const unsigned short* pIndexData;

	SRenderPrimitiveMeshData() = default;
	~SRenderPrimitiveMeshData() = default;
};
