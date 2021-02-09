#pragma once

class SRenderPrimitiveMeshDesc
{
public:
    unsigned int nNumVertices;
    unsigned int nNumIndices;
    unsigned __int16 nColorDataSize;
    __int32 ePrimitiveType : 8;
    __int32 eRenderPrimitiveTopology : 8;
    unsigned __int8 nFlags;
    unsigned __int8 nColorOffset;
    unsigned __int8 nNumStreams;
    unsigned __int8 anStreamStride[3];
};
