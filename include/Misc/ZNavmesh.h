#pragma once

#include "SVector2.h"
#include "TArray.h"
#include "ERegionMask.h"

struct float4;
struct SVector3;
struct SVector4;
template <class T> class alignas(8) ZDelegate;

class ZNavmesh
{
public:
	unsigned int m_nPolygonCount;
	unsigned int m_nCornerCount;
	unsigned int m_nVertexCount;
	unsigned int m_nPlaneCount;
	const unsigned short* m_aPolygonOffsets;
	const unsigned short* m_aPolygonData;
	const SVector3* m_aVertices;
	const unsigned short* m_aAnnotation;
	const unsigned short* m_aPlaneIndices;
	const SVector4* m_aPlaneEquations;
	SVector2 m_vBoundsMin;
	SVector2 m_vBoundsMax;
	float m_fTileSize;
	int m_nTileCountX;
	int m_nTileCountY;
	TArray<TArray<unsigned short>> m_tiles;
	TArray<float> m_aCostMultipliers;
	TArray<ZDelegate<void __cdecl(ERegionMask, float, float)>> m_aRegionCostListeners;

	static const unsigned int NAVMESH_MAGIC;
	static const unsigned int NAVMESH_CURRENT_VERSION;

	ZNavmesh(const ZNavmesh& __that);
	ZNavmesh() = default;
	~ZNavmesh() = default;
	static ZNavmesh* Create(const unsigned char* pNavmeshData);
	float GetPolygonCostModifier(int iComponentID) const;
	void SetRegionCostModifier(ERegionMask eRegionMask, float fCostModifier);
	void SetPolygonCostModifier(unsigned int nPolygonID, float fCostModifier);
	bool DynamicCostAllowsCrossing(unsigned int nPolygonID, unsigned int nNeighborID) const;
	void ClearCostModification();
	void RegisterCostListener(ZDelegate<void __cdecl(ERegionMask, float, float)> pListener);
	void UnregisterCostListener(ZDelegate<void __cdecl(ERegionMask, float, float)> pListener);
	unsigned int GetPolygonCount() const;
	unsigned int GetVertexCount() const;
	unsigned int GetCornerCount(unsigned int nPolygonID) const;
	unsigned short GetAnnotation(unsigned int nPolygonID) const;
	unsigned int GetVertexID(unsigned int nPolygonID, unsigned int nCornerID) const;
	unsigned short GetNeighborID(unsigned int nPolygonID, unsigned int nCornerID) const;
	float4 GetPlaneEquation(unsigned int nPolygonID) const;
	float4 GetVertex(unsigned int nVertexID) const;
	unsigned int GetPolygonVertices(unsigned int nPolygonID, unsigned int nMaxVertices, float4* aVertices) const;
	void GetNavmeshBounds(SVector2& vMin, SVector2& vMax) const;
	bool MapPointToPolygon(float4& vMappedPos, const float4& vPoint, unsigned int nPolygonID) const;
	unsigned short GetNearestPolygon(const float4& vPos, float fAcceptance, float4& vMappedPos) const;
	unsigned short GetNearestPolygonVertically(const float4& vPos, float fAcceptance, float4& vMappedPos) const;
	void BuildTiles(float fTileSize);
	unsigned short GetNearestPolygonInArray(const TArray<unsigned short>& aPolygons, const float4& vPos, float4& vBestDistanceSq, float4& vMappedPos) const;
	ZNavmesh& operator=(const ZNavmesh& __that);
};
