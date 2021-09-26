#pragma once

#include "ERenderPrimitiveType.h"
#include "ERenderPrimitiveTopology.h"

struct SRenderPrimitiveMeshDesc
{
	enum EDescMeshFlags
	{
		DESC_MESH_UNCOMPRESSED = 1,
		DESC_MESH_PS3EDGE = 2,
		DESC_MESH_COL1 = 4,
		DESC_MESH_ISNOPHYSICSPROP = 8
	};

	unsigned int nNumVertices;
	unsigned int nNumIndices;
	unsigned short nColorDataSize;
	ERenderPrimitiveType ePrimitiveType : 8;
	ERenderPrimitiveTopology eRenderPrimitiveTopology : 8;
	unsigned char nFlags;
	unsigned char nColorOffset;
	unsigned char nNumStreams;
	unsigned char anStreamStride[3];

	SRenderPrimitiveMeshDesc() = default;
	~SRenderPrimitiveMeshDesc() = default;
};
