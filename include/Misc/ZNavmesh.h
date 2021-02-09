#pragma once

#include "SVector3.h"
#include "SVector4.h"
#include "SVector2.h"
#include "TArray.h"
#include "ZDelegate.h"
#include "ERegionMask.h"

class ZNavmesh
{
public:
    unsigned int m_nPolygonCount;
    unsigned int m_nCornerCount;
    unsigned int m_nVertexCount;
    unsigned int m_nPlaneCount;
    const unsigned __int16* m_aPolygonOffsets;
    const unsigned __int16* m_aPolygonData;
    const SVector3* m_aVertices;
    const unsigned __int16* m_aAnnotation;
    const unsigned __int16* m_aPlaneIndices;
    const SVector4* m_aPlaneEquations;
    SVector2 m_vBoundsMin;
    SVector2 m_vBoundsMax;
    float m_fTileSize;
    int m_nTileCountX;
    int m_nTileCountY;
    TArray<TArray<unsigned short> > m_tiles;
    TArray<float> m_aCostMultipliers;
    TArray<ZDelegate<void __cdecl(ERegionMask, float, float)> > m_aRegionCostListeners;
};
