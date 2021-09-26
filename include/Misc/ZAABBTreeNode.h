#pragma once

#include "TList.h"
#include "float4.h"
#include "TListIterator.h"
#include "IEnumeratorImpl.h"

class IAABBTreeVisitor;

class ZAABBTreeNode
{
public:
	enum ETreeType
	{
		TREE_TYPE_KDTREE = 2,
		TREE_TYPE_OCTREE = 8,
		TREE_TYPE_ICOSEPTREE = 27
	};

	struct SObjectNode
	{
		void* m_pObject;
		ZAABBTreeNode* m_pTreeNode;
		float4 m_vMin;
		float4 m_vMax;
	};

	class ZAABBTreeNodeEnumeratorImpl : public IEnumeratorImpl
	{
	public:
		ZAABBTreeNode* m_pNode;
		TListIterator<SObjectNode*> m_itNode;
		unsigned int m_nChildIndex;

		void* GetNext(const void* pCurrent) override;
		void Release() override;
		~ZAABBTreeNodeEnumeratorImpl() override = default;

		ZAABBTreeNodeEnumeratorImpl(ZAABBTreeNode* pNode);
		ZAABBTreeNode* GetNextNode(ZAABBTreeNode* pNode);
	};

	ZAABBTreeNode* m_pParent;
	ZAABBTreeNode** m_apChildren;
	TList<SObjectNode*> m_Nodes;
	float4 m_vSplit;
	float4 m_vMin;
	float4 m_vMax;
	unsigned int m_nExtentsCorrect : 1;
	unsigned int m_nIsSplit : 1;
	unsigned int m_nSplitAxis : 2;
	unsigned int m_nExpandable : 1;
	unsigned int m_nSplitLimit;
	unsigned int m_nLeafCount;

	virtual ~ZAABBTreeNode() = default;

	ZAABBTreeNode() = default;
	ZAABBTreeNode(const ZAABBTreeNode& __that);
	ZAABBTreeNode(ZAABBTreeNode* pParent, ETreeType eTreeType, unsigned int nSplitLimit);
	bool ExtentsValid() const;
	void GetExtents(float4& vMin, float4& vMax, bool bSplit);
	void GetExtents(float4& vMin, float4& vMax);
	void* AttachNode(void* pObject, const float4& vMin, const float4& vMax);
	void DetachNode(void* pSceneGraphData);
	void UpdateNode(SObjectNode* pObjectNode, const float4& vOldMin, const float4& vOldMax, const float4& vNewMin, const float4& vNewMax);
	void UpdateNode(void* pSceneGraphData, const float4& vMin, const float4& vMax);
	void Visit(IAABBTreeVisitor& collector, ZAABBTreeNode* pNode);
	void Visit(IAABBTreeVisitor& collector);
	IEnumeratorImpl* CreateEnumeratorImpl();
	unsigned int GetMaxChildCount() const;
	ZAABBTreeNode** GetChildList();
	TList<SObjectNode*>& GetNodes();
	ZAABBTreeNode* AddNode(SObjectNode* pObjectNode);
	ZAABBTreeNode* FindNode(const float4& vMin, const float4& vMax);
	ZAABBTreeNode* FindNode(SObjectNode* pObjectNode);
	void RemoveNode(SObjectNode* pObjectNode, const float4& vMin, const float4& vMax);
	void RemoveNode(SObjectNode* pObjectNode);
	void InsertNode(SObjectNode* pObjectNode);
	bool HasNodes() const;
	ZAABBTreeNode* GetChild(int nIndex);
	int WhichChild(const float4& vMin, const float4& vMax) const;
	void RemoveChild(ZAABBTreeNode* pChild);
	void Split();
	void UnSplit();
	void TestDestroy();
	void GrowExtents(const float4& vMin, const float4& vMax);
	void ShrinkExtents(const float4& vMin, const float4& vMax);
	void UpdateExtents();
	bool Contains(const float4& vMin, const float4& vMax);
	ZAABBTreeNode& operator=(const ZAABBTreeNode& __that);
};
