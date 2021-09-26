#pragma once

#include "ZRenderGraphNode.h"
#include "TArray.h"
#include "TArrayRef.h"

struct SRenderPrimitiveEntry;
class IJobChain;
class ZRenderGraphNodeMaterial;
class ZRenderPrimitiveInstance;
class ZRenderableEntity;

class ZRenderGraphNodePrimitiveContainer : public ZRenderGraphNode
{
public:
	enum
	{
		PRIMITIVE_FLAGS_UPDATE_PRIMS = 1,
		PRIMITIVE_FLAGS_UPDATE_PENDING = 2,
		PRIMITIVE_FLAGS_UPDATE_RUNTIME_DECALS_ONLY = 4
	};

	unsigned short m_nRuntimeDecal;
	TArray<ZRenderPrimitiveInstance> m_PrimitiveInstances;
	unsigned int m_nPrimitiveChangeCounter;
	unsigned char m_nPrimitiveFlags;
	unsigned char m_nMaxLODIndex;
	unsigned char m_nGlowType;
	unsigned char m_nGlowAmount;
	float m_fLODScale;
	float m_fLODOffset;
	TArray<ZRenderGraphNodeMaterial*> m_pMaterialModifiers;
	ZRenderGraphNodeMaterial* m_pOverrideMaterial;
	ZRenderGraphNodePrimitiveContainer* m_pNextPendingUpdate;

	static ZRenderGraphNodePrimitiveContainer* s_pPendingUpdatesHead;

	~ZRenderGraphNodePrimitiveContainer() override = default;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodePrimitiveContainer() = default;
	ZRenderGraphNodePrimitiveContainer(ZRenderGraphNode::TYPE eType);
	TArray<ZRenderPrimitiveInstance>& GetRenderPrimitiveInstances();
	void GetRenderPrimitiveInstances(TArray<SRenderPrimitiveEntry>& Entries, unsigned int nLayerMask, unsigned char nLODMask, unsigned char nDrawDestination, unsigned int nTransparencyMask, unsigned int nExclusionMask);
	TArrayRef<ZRenderGraphNodeMaterial*> GetMaterialModifiers();
	void OnRenderPrimitiveChanged();
	void AttachMaterialModifier(ZRenderGraphNodeMaterial* pMaterialModifier);
	const float* GetLODScalePtr() const;
	unsigned int GetMaxLODIndex() const;
	unsigned char GetGlowType() const;
	unsigned char GetGlowAmount() const;
	void SetGlowAmount(const unsigned char nGlowAmount);
	static void UpdatePending();
	void UpdatePrimitiveInstances();
	void PushUpdatePending();
};
