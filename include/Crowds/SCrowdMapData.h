#pragma once

#include "SVector4.h"
#include "TArray.h"
#include "ZCrowdGridPoint.h"
#include "SCrowdCells.h"
#include "SCrowdFlowChannel.h"
#include "SMatrix.h"

class SCrowdMapData
{
public:
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
};
