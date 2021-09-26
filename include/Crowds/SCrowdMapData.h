#pragma once

#include "SVector4.h"
#include "TArray.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "float4.h"

class ZCrowdGridPoint;
struct SCrowdCells;
struct SCrowdFlowChannel;

struct SCrowdMapData
{
	unsigned int m_nVersion;
	SVector4 m_vCellConsts;
	unsigned int m_nGridSizeX;
	unsigned int m_nGridSizeY;
	unsigned int m_nCellSizeX;
	unsigned int m_nCellSizeY;
	TArray<ZCrowdGridPoint> m_GridMap;
	float m_fGridMapHeightOffsetsScale;
	float m_fGridMapHeightOffsetsBias;
	TArray<SCrowdCells> m_CellFlags;
	TArray<SCrowdFlowChannel> m_aFlowChannels;
	float m_nGridCellSize;
	SMatrix m_mObjectToWorld;
	SVector3 m_vGlobalSize;
	float m_nGridGeneratorOffset;

	static const unsigned int UNIT_CIRCLE_SPLITS_COUNT;
	static float UnitCircleSplits[121][2];

	unsigned char* GetCellFlags();
	const unsigned char* GetCellFlags() const;
	static float4 GetFlowFloat4FromIndex(unsigned char nIndex);
	static unsigned char GetIndexFromFlowFloat4(const float4& vFlow);
	SCrowdMapData(const SCrowdMapData& __that);
	SCrowdMapData() = default;
	~SCrowdMapData() = default;
	SCrowdMapData& operator=(const SCrowdMapData& __that);
};
