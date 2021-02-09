#pragma once

#include "SDecalInfo.h"
#include "ZBitAlloc.h"

class ZRuntimeDecalManager
{
    unsigned __int16 m_nDecalFree;
    unsigned __int16 m_nKillListHead;
    SDecalInfo* m_aObjects;

    class SDecalList
    {
    public:
        unsigned __int16 nHead;
        unsigned __int16 nNumDecals;
        unsigned int nNumTriangles;
        unsigned int nBytesUsed;
    } m_aList[2];

    class SDecalListGeomBuffer
    {
    public:
        ZRenderIndexBuffer* m_pIdxBuffer;
        ZRenderVertexBuffer* m_pVtxBuffer;
        ZBitAlloc m_IdxBufferAlloc;
        ZBitAlloc m_VtxBufferAlloc;
    } m_GeomBuffer;

    unsigned __int16 m_nNumNewDecals;

    struct SDecalConstruction
    {
        unsigned __int16 nSlot;
        unsigned __int16 nList;
        unsigned int nConsOffsIdx;
        unsigned int nConsOffsVtx;
        unsigned int nVtxInstallOffset;
        unsigned int nVtxSize;
    } m_aDecalCons[64];

    char* m_pDecalConstruction;
    unsigned int m_nConstructionOffs;
    unsigned __int64 m_aActiveTexScaling[2];
};
