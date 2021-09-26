#pragma once

#include "IRenderPrimitiveMesh.h"

struct SRenderPrimitiveMeshInit;
class IRenderPrimitiveBuffer;
class ZRenderContext;
class ZRenderInputLayout;
struct SColiBoxHeader;
struct SRenderPrimitiveMeshDesc;
struct SRenderRecordedDrawCmdBuffer;

class ZRenderPrimitiveMeshDecal : public IRenderPrimitiveMesh
{
public:
	unsigned short m_nDecalSlot;
	IRenderPrimitiveMesh* m_pAttachedTo;

	~ZRenderPrimitiveMeshDecal() override = default;
	unsigned int Release() override;
	void DrawNew(ZRenderContext* pRenderContext) override;
	IRenderPrimitiveBuffer* GetVertexBuffer(unsigned int nIndex) const override;
	IRenderPrimitiveBuffer* GetIndexBuffer() const override;
	void SetCopyBones(unsigned int nNumCopyBoneBlocks, const unsigned int* pCopyBonesList) override;
	void GetCopyBones(unsigned int& nNumCopyBoneBlocks, const unsigned int*& pCopyBonesList) override;
	void SetBoneIndices(const unsigned short* pBoneIndices) override;
	bool GetIndicesForBone(unsigned int nMeshBoneID, const unsigned short** pBoneIndices, unsigned int* nNumIndicesForBone, IRenderPrimitiveBuffer** ppIndexBuffer, const SColiBoxHeader** ppColiHeader) override;

	ZRenderPrimitiveMeshDecal(const SRenderPrimitiveMeshDesc* pDesc, const SRenderPrimitiveMeshInit* pInit);
	ZRenderPrimitiveMeshDecal() = default;
	void Init(IRenderPrimitiveMesh* pPrimitive, unsigned short nDecalSlot);
	void RecordDraw(SRenderRecordedDrawCmdBuffer& DrawCmds, ZRenderInputLayout* pInputLayout);
};
