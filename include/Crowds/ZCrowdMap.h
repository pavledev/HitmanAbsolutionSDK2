#pragma once

#include "SCrowdMapData.h"
#include "CrowdMapImpl.h"
#include "TArray.h"
#include "float4.h"

class ZSphereVolumeEntity;
class ZCrowdActorGroupEntity;
class IBoxVolumeEntity;
class ZCrowdTeleportEntity;
struct SMatrix;
struct SVector3;
struct SVector4;
template <class T> class TEntityRef;

class ZCrowdMap : public SCrowdMapData
{
public:
	enum CellStatus
	{
		CELLS_UNKNOWN = 0,
		CELLS_CANDIDATE = 1,
		CELLS_KNOWN = 2
	};

	struct SCrowdMapFlowCostsTemp
	{
		TArray<TArray<float>> m_aFlowChannels;

		SCrowdMapFlowCostsTemp() = default;
		~SCrowdMapFlowCostsTemp() = default;
	};

	unsigned int GetNumGridPoints() const;
	unsigned int GetNumCells() const;
	unsigned int GetGridIndex(unsigned int x, unsigned int y) const;
	unsigned int GetCellIndex(unsigned int x, unsigned int y) const;
	void GetCellCoord(unsigned int nIdx, unsigned int* pX, unsigned int* pY) const;
	bool ValidCellCoord(unsigned int x, unsigned int y) const;
	unsigned int GetCellSizeX() const;
	unsigned int GetCellSizeY() const;
	unsigned int GetGridSizeX() const;
	unsigned int GetGridSizeY() const;
	float4 GetCellPackedConsts() const;
	const SVector4& GetCellConsts() const;
	unsigned char GetOnNavGridFromIndex(unsigned int nCellIndex) const;
	float GetHeightFromIndex(unsigned int nCellIndex) const;
	bool GetHeightFromLocalPos(const float4& vLocalPos, float* pHeight) const;
	unsigned char GetFlags(unsigned int nCellIndex) const;
	bool GetFlag(unsigned int nCellIndex, CrowdMapImpl::CellFlags nFlag) const;
	bool IsCellWalkable(unsigned int nCellIndex, unsigned char nAccessFlags) const;
	bool IsCellWalkable(unsigned int x, unsigned int y, unsigned char nAccessFlags) const;
	bool GetCellCoordFromLocalPos(const float4& vLocalPos, unsigned int* aCoord) const;
	float4 GetCellCoordFromLocalPosF4(const float4& vLocalPos) const;
	unsigned int GetCellIndexFromLocalPosF4(const float4& vLocalPos) const;
	unsigned int GetCellIndexF4(const float4& vCellCoord) const;
	float4 GetCrowdSpacePositionFromWorldSpace(const float4& vWorldPos) const;
	float4 GetWorldSpacePositionFromCrowdSpace(const float4& vCrowdSpace) const;
	float4 GetCrowdSpaceDirectionFromWorldSpace(const float4& vWorldDir) const;
	float4 GetWorldSpaceDirectionFromCrowdSpace(const float4& vCrowdDir) const;
	float4 GetGridPointWorldPos2D(unsigned int x, unsigned int y) const;
	float4 GetGridPointWorldPos(unsigned int x, unsigned int y) const;
	unsigned int GetNumFlowChannels() const;
	float4 GetFlowVector(unsigned int nCellIndex, unsigned int nFlowChannel) const;
	bool GetFlowTwoWay(unsigned int nCellIndex, unsigned int nFlowChannel) const;
	unsigned short GetFlowCost(unsigned int nCellIndex, unsigned int nFlowChannel) const;
	float GetCollisionTime(const float4& vRayStart, const float4& vRayEnd, float4* vCollisionNormal, bool bIgnoreCollisionIfTeleportOutCell, bool bSmoothCornerCollision, unsigned char nAccessFlags) const;
	static const ZCrowdMap* Create(const SMatrix& mObjectToWorld, float nGridCellSize, SVector3 vGlobalSize, float nGridGeneratorOffset, bool bSmoothenExitFlows, const TArray<TEntityRef<IBoxVolumeEntity>>& aCrowdExclusionBoxes, const TArray<TEntityRef<ZSphereVolumeEntity>>& aCrowdExclusionSpheres, const TArray<TEntityRef<IBoxVolumeEntity>>& aCrowdPanicOnlyBoxes, const TArray<TEntityRef<ZCrowdActorGroupEntity>>& aCrowdActorGroupBoxes, const TArray<TEntityRef<ZCrowdTeleportEntity>>& aCrowdTeleports, const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxes, const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxesTwoWay);
	void ClearAllFlags(unsigned int nCellIndex);
	void SetFlag(unsigned int nCellIndex, CrowdMapImpl::CellFlags nFlag);
	void SetFlowVector(unsigned int nCellIndex, unsigned int nFlowChannel, const float4& vFlow, bool bTwoWay);
	void SetFlowCost(unsigned int nCellIndex, unsigned int nFlowChannel, unsigned short nFlowCost);
	void Alloc(unsigned int nNumFlowChannels);
	void BuildGridMap(bool bSmoothenExitFlows, const TArray<TEntityRef<IBoxVolumeEntity>>& aCrowdExclusionBoxes, const TArray<TEntityRef<ZSphereVolumeEntity>>& aCrowdExclusionSpheres, const TArray<TEntityRef<IBoxVolumeEntity>>& aCrowdPanicOnlyBoxes, const TArray<TEntityRef<ZCrowdActorGroupEntity>>& aCrowdActorGroupBoxes, const TArray<TEntityRef<ZCrowdTeleportEntity>>& aCrowdTeleports, const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxes, const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxesTwoWay);
	void BuildAmbientFlow(const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxes, const TArray<TEntityRef<IBoxVolumeEntity>>& aFlowBoxesTwoWay, unsigned int nFlowChannel, SCrowdMapFlowCostsTemp& flowCosts);
	void InsertInCandidateList(TArray<unsigned int>& aCandidateList, unsigned int nIndex, float nCost, const TArray<float>& aCellCost, unsigned char* pCellStatus);
	void BuildPanicFlow(const TArray<unsigned int>& aGoalCells, unsigned int nChannel, bool bSmoothenFlow, SCrowdMapFlowCostsTemp& flowCosts);
	void CompressAndSaveFlowCosts(SCrowdMapFlowCostsTemp& flowCosts);
	ZCrowdMap(const ZCrowdMap& __that);
	ZCrowdMap() = default;
	~ZCrowdMap() = default;
	ZCrowdMap& operator=(const ZCrowdMap& __that);
};
