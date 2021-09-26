#pragma once

class IRenderPrimitive;
class ZRenderGraphNode;
class ZRenderGraphNodeMaterial;

class ZRenderPrimitiveInstance
{
public:
	IRenderPrimitive* m_pRenderPrimitive;
	ZRenderGraphNodeMaterial* m_pOverrideMaterial;
	unsigned int m_nLayerMask;
	unsigned char m_nLODMask;
	unsigned short m_nTransparencyMask;

	ZRenderPrimitiveInstance(const ZRenderPrimitiveInstance& other);
	ZRenderPrimitiveInstance() = default;
	~ZRenderPrimitiveInstance() = default;
	ZRenderPrimitiveInstance& operator=(const ZRenderPrimitiveInstance& other);
	void Init(ZRenderPrimitiveInstance& other, IRenderPrimitive* pRenderPrimitive);
	void Init(IRenderPrimitive* pRenderPrimitive);
	void InitDecal(IRenderPrimitive* pRenderPrimitive);
	void Clear();
	bool Matches(unsigned int nLayerMask, unsigned char nLODMask, unsigned char nDrawDestination, unsigned int nTransparencyMask, unsigned int nExclusionMask);
	bool MatchesLOD(unsigned char nLODMask);
	IRenderPrimitive* GetRenderPrimitive() const;
	unsigned short GetTransparencyMask() const;
	unsigned char GetLODMask() const;
	void SetOverrideMaterial(ZRenderGraphNodeMaterial* pMaterial);
	ZRenderGraphNodeMaterial* GetOverrideMaterial();
	void Update(ZRenderGraphNode* pRenderGraphNode);
};
