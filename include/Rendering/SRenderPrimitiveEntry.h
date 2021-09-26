#pragma once

class IRenderPrimitive;
class ZRenderGraphNode;
class ZRenderMaterialInstance;
class ZRenderPrimitiveInstance;

struct SRenderPrimitiveEntry
{
	ZRenderPrimitiveInstance* m_pPrimitiveInstance;
	IRenderPrimitive* m_pRenderPrimitive;
	ZRenderGraphNode* m_pRenderGraphNode;
	unsigned int nSortValue;

	SRenderPrimitiveEntry() = default;
	SRenderPrimitiveEntry(ZRenderPrimitiveInstance* pPrimitiveInstance, IRenderPrimitive* pRenderPrimitive, ZRenderGraphNode* pRenderGraphNode, ZRenderMaterialInstance* pMaterialInstance, unsigned char nLODFade, bool bUseFade, bool bSimpleShader);
	~SRenderPrimitiveEntry() = default;
	ZRenderGraphNode* GetRenderGraphNode();
	IRenderPrimitive* GetRenderPrimitive();
	void GetFadeParams(unsigned char& nLODFade, bool& bUseFade, bool& bSimpleShader);
	bool operator<(const SRenderPrimitiveEntry& other);
};
