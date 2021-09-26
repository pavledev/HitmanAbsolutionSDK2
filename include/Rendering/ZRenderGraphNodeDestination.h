#pragma once

#include "ZRenderableEntity.h"
#include "ZRenderGraphNode.h"
#include "IJobChain.h"
#include "ZRenderTraversalContext.h"
#include "ZRenderDestination.h"
#include "ZRenderContext.h"

class ZRenderGraphTraversal;

class ZRenderGraphNodeDestination : public ZRenderGraphNode
{
public:
	ZRenderGraphNode* m_pSource;
	ZRenderDestination* m_pRenderDestination;
	bool m_bActive;
	bool m_bEditorExclusive;

	~ZRenderGraphNodeDestination() override = default;
	void Traverse(ZRenderGraphNode* pParent, ZRenderGraphTraversal* pRenderGraphTraversal, ZRenderTraversalContext* pParentTraversalContext, ZRenderContext* pRenderContext) override;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;
	void CleanUp() override;

	ZRenderGraphNodeDestination() = default;
	bool IsValid() const;
	bool GetEditorExclusive() const;
	bool IsScreen() const;
	ZRenderDestination* GetRenderDestination() const;
	ZRenderGraphNode* GetSource() const;
	void OnSourceDeleted(ZRenderGraphNode* pNode);
};
