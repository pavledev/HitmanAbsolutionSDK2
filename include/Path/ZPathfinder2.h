#pragma once

#include "IComponentInterface.h"
#include "ZPathfinderSearchState.h"
#include "TQueue.h"
#include "TRefCountPtr.h"
#include "ZEvent.h"
#include "ERegionMask.h"
#include "TMaxArray.h"
#include "ZPF5Location.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZElementMarker;
class ZEventNull;
class ZNavmesh;
class ZPF5AsynchPathRequest;
class ZPF5LineHitInfo;
class ZPF5Path;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct STypeID;
template <class T> class alignas(8) ZDelegate;

class ZPathfinder2 : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZPathfinderSearchState m_immediateSearchState;
	ZPathfinderSearchState m_persistentSearchState;
	ZElementMarker* m_pImmediateMarker;
	ZElementMarker* m_pPersistentMarker;
	ZNavmesh* m_pNavmesh;
	TQueue<TRefCountPtr<ZPF5AsynchPathRequest>, TMaxArray<TRefCountPtr<ZPF5AsynchPathRequest>, 64>> m_pathRequests;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_NavmeshChangedEvent;

	~ZPathfinder2() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZPathfinder2() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetNavmeshChangedEvent();
	void SetNavmeshData(const unsigned char* pNavmeshData);
	bool IsDataLoaded() const;
	void Update(const SGameUpdateEvent& updateEvent);
	void ReleaseData();
	void Clear();
	ZPF5Location MapLocation(const float4& vPos, float fAcceptance) const;
	bool MapLocation(const float4& vPos, ZPF5Location& lMapped) const;
	bool MapLocationWithin(const float4& vPos, ZPF5Location& lMapped, float fHeight, float fRadius) const;
	bool MapLocationWithin(const float4& vPos, ZPF5Location& lMapped, float fAcceptance) const;
	ZPF5Location MapLocationVertically(const float4& vPos, float fAcceptance) const;
	bool TraceLine(ZPF5Location& lFinal, const ZPF5Location& lFrom, const float4& vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned short nAllowedRegionMask) const;
	int TraceLine(const ZPF5Location& lFrom, float4& vEndPoint) const;
	bool MoveLocationConstrained(ZPF5Location& lMoved, const float4& vWantedPos) const;
	bool IsLineBlocked(const ZPF5Location& lFrom, const ZPF5Location& lTo) const;
	bool LineBlocked(const ZPF5Location& lFrom, const ZPF5Location& lTo) const;
	bool LineBlocked(const ZPF5Location& startLocation, const float4& endPoint2d, unsigned short nCollisionMask, ZPF5LineHitInfo& lineHitInfo) const;
	bool LineBlocked(const ZPF5Location& startLocation, const float4& endPoint2d, ZPF5Location* endLocation) const;
	TRefCountPtr<ZPF5Path> FindPath(const ZPF5Location& lFrom, const ZPF5Location& lTo, float fMaxCost);
	float GetPathCost(const ZPF5Location& lFrom, const ZPF5Location& lTo, float fMaxCost);
	float GetPathCost(const float4& vFrom, const float4& vTo, float fMaxCost);
	TRefCountPtr<ZPF5AsynchPathRequest> RequestPath(const ZPF5Location& lFrom, const ZPF5Location& lTo, float fMaxCost);
	bool AbortAsyncPathRequest(TRefCountPtr<ZPF5AsynchPathRequest>& request);
	void GetCompCenter(int nPolygonID, ZPF5Location& lCenter) const;
	float4 GetPlaneEquation(int nPolygonID) const;
	int GetCornerCount(int nComponentID) const;
	int GetNeighborID(int nComponentID, int nCorner) const;
	ERegionMask GetRegionMask(int nComponentID) const;
	void SetRegionCostModifier(ERegionMask eRegionMask, float fCostModifier);
	void SetPolygonCostModifier(unsigned int nPolygonID, float fCostModifier);
	float GetPolygonCostModifier(unsigned int nPolygonID) const;
	bool NearestOuterEdge(const ZPF5Location& lFrom, float fRadius, float4& vResult, float4& vNormal) const;
	bool GetNearestOuterEdgeInPolygon(const ZPF5Location& lFrom, float4& vEdgeVert1, float4& vEdgeVert2) const;
	const ZNavmesh* GetNavmesh() const;
	void GetVerticesForEdge(unsigned int nPolygonID, unsigned int nCornerID, float4& v0, float4& v1) const;
	float4 GetPolygonCenter(unsigned int nPolygonID) const;
	unsigned int GetOppositeCorner(unsigned short nPolygonID, unsigned int nCornerID) const;
	unsigned int GetRegionMaskWithinRadius(const ZPF5Location& lPosition, const float fRadius) const;
	bool RegisterCostListener(ZDelegate<void __cdecl(ERegionMask, float, float)> pListener);
	bool UnregisterCostListener(ZDelegate<void __cdecl(ERegionMask, float, float)> pListener);
	float4 SearchNode_GetPosition(const ZPathfinderSearchState& searchState, unsigned int nNodeKey) const;
	void SearchNode_UpdateCost(unsigned int nNodeKey, unsigned short nPolygonID, const ZPathfinderSearchState::SSearchNode* pCameFrom, float fAccumulatedCost, ZPathfinderSearchState& searchState);
	int SearchNode_UpdateNeighbors(const ZPathfinderSearchState::SSearchNode* pSearchNode, ZPathfinderSearchState& searchState);
	ZPathfinderSearchState::SSearchNode* SearchNode_Dequeue(ZPathfinderSearchState& searchState, int nMaxCost);
	int SearchNode_Find(const ZPathfinderSearchState& searchState, unsigned int nNodeKey);
	void FindPathIterate(TRefCountPtr<ZPF5AsynchPathRequest>& request, int& nRemainingUpdateCalls);
	int BuildPath(TRefCountPtr<ZPF5Path>& path, const ZPathfinderSearchState::SSearchNode* pSearchNode, const ZPathfinderSearchState& searchState, const ZPF5Location& lFrom, const ZPF5Location& lTo) const;
	void AssignLeftRight(float4& v0, float4& v1, const float4& vApex) const;
	void PushPathFromCorners(TRefCountPtr<ZPF5Path>& path) const;
	void RemoveRedundantPoints(TRefCountPtr<ZPF5Path>& path) const;
	void InjectInclinePoints(TRefCountPtr<ZPF5Path>& path) const;
	bool TraceLineRobust(ZPF5Location& lFinal, const ZPF5Location& lFrom, const float4& vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned short nAllowedRegionMask) const;
};
