#pragma once

#include "ZBitAlloc.h"

class IRenderPrimitiveMesh;
class ZDecalControllerEntity;
class ZRenderGraphNodePrimitiveContainer;
class ZRenderIndexBuffer;
class ZRenderPrimitiveInstance;
class ZRenderVertexBuffer;
struct SDecalInfo;
struct SRenderPrimitiveMeshDesc;
struct SRenderPrimitiveMeshInit;
struct float4;

class ZRuntimeDecalManager
{
public:
	struct SDecalList
	{
		unsigned short nHead;
		unsigned short nNumDecals;
		unsigned int nNumTriangles;
		unsigned int nBytesUsed;

		SDecalList() = default;
	};

	struct SDecalListGeomBuffer
	{
		ZRenderIndexBuffer* m_pIdxBuffer;
		ZRenderVertexBuffer* m_pVtxBuffer;
		ZBitAlloc m_IdxBufferAlloc;
		ZBitAlloc m_VtxBufferAlloc;

		SDecalListGeomBuffer() = default;
		~SDecalListGeomBuffer() = default;
	};

	struct SDecalConstruction
	{
		unsigned short nSlot;
		unsigned short nList;
		unsigned int nConsOffsIdx;
		unsigned int nConsOffsVtx;
		unsigned int nVtxInstallOffset;
		unsigned int nVtxSize;
	};

	unsigned short m_nDecalFree;
	unsigned short m_nKillListHead;
	SDecalInfo* m_aObjects;
	SDecalList m_aList[2];
	SDecalListGeomBuffer m_GeomBuffer;
	unsigned short m_nNumNewDecals;
	SDecalConstruction m_aDecalCons[64];
	unsigned char* m_pDecalConstruction;
	unsigned int m_nConstructionOffs;
	unsigned long long m_aActiveTexScaling[2];

	ZRuntimeDecalManager() = default;
	~ZRuntimeDecalManager() = default;
	void AllocateBuffers();
	unsigned short AllocateSlot(ZDecalControllerEntity* pDecalController, IRenderPrimitiveMesh* pRenderPrimitiveAttachTo, const float4& vBaseColor, unsigned short nSlot, unsigned short* pnNewHandle);
	unsigned short GetPrimInstance(unsigned short nSlot, ZRenderPrimitiveInstance** ppDecalPrimInstance);
	void GetDrawData(unsigned short nSlot, ZRenderIndexBuffer** ppIdxBuffer, ZRenderVertexBuffer** ppVtxBuffer, unsigned int* pnIdxOffset, unsigned int* pnVtxOffset, unsigned int* pnNumIndices);
	void RemoveDecalsFromController(ZDecalControllerEntity* pDecalController);
	void RemoveDecalsFromContainer(unsigned short nSlot);
	void RemoveDecalsFromRGN(unsigned short nSlot);
	unsigned short OnReflect(ZRenderGraphNodePrimitiveContainer* pRGN, unsigned short nCurrentDecals, unsigned short nNewDecals);
	void Update();
	bool AllocateGeometryForDecal(unsigned short nSlot, unsigned short** pDecalIndices, unsigned char** pDecalVertices, unsigned int nNumDecalIndices, unsigned int nVtxSize, unsigned int nStride);
	void InitDecal(SRenderPrimitiveMeshDesc* pMeshDesc, SRenderPrimitiveMeshInit* pMeshInit, unsigned short nSlot);
	void UpdateDecalBuffers();
	void FreeGeometryForSlot(unsigned short nSlot);
	void SatisfyConstraints(unsigned int nList);
	void HandleFading(unsigned int nList);
	void HandleTexScale();
	unsigned short Free(unsigned short nSlot);
	void SetTexScale(unsigned short nSlot);
	void ClearTexScale(unsigned short nSlot);
};
