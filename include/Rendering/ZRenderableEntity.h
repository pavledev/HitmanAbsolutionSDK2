#pragma once

#include "ZBoundedEntity.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZRenderGraphNode;
class ZSpatialEntity;
struct STypeID;
template <class T> class TArray;

class ZRenderableEntity : public ZBoundedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EChangeFlags
	{
		CHANGE_SPATIAL = 1,
		CHANGE_OTHER = 2,
		CHANGE_FULL = 3,
		CHANGE_USE_POST_REFLECT = 128
	};

	unsigned char m_nChangedFlag;
	bool m_bIgnoreRooms : 1;
	bool m_bPerformVisibilityTest : 1;
	bool m_bNotifyVisibleOnScreenChanged : 1;
	bool m_bDontDraw : 1;
	bool m_bActiveRenderGraphNode : 1;
	ZRenderGraphNode* m_pRenderGraphData;

	static SComponentMapEntry s_componentMap[0];

	~ZRenderableEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void OnSpatialChange() override;
	virtual void OnVisibleOnScreenChanged(bool bVisibleOnScreen);

	ZRenderableEntity() = default;
	static void RegisterType();
	ZRenderableEntity(const ZRenderableEntity& __that);
	ZRenderableEntity(ZComponentCreateInfo& Info);
	void ActivateGeom();
	void DeactivateGeom();
	ZRenderGraphNode* GetRenderGraphData() const;
	void SetRenderGraphData(ZRenderGraphNode* pData);
	void SetChangedFlag(unsigned int nChangedFlag);
	void ClearChangedFlag();
	unsigned int GetChangedFlag() const;
	void SetUsePostReflect();
	void SetNotifyOnVisibleOnScreenChanged();
	bool WantVisibleOnScreenChangedUpdate() const;
	void SetPerformVisibilityTest(bool bPerformVisibilityTest);
	bool GetPerformVisibilityTest() const;
	void SetDontDraw(bool bDontDraw);
	bool GetDontDraw() const;
	bool GetIgnoreRooms() const;
	void SetIgnoreRooms();
	void SetSpatialChangeFlag();
	static const ZRenderableEntity* Query(const ZSpatialEntity* pSpatial);
	static ZRenderableEntity* Query(ZSpatialEntity* pSpatial);
	static void AddNodesRecursive(const ZSpatialEntity* pSpatial, TArray<ZRenderGraphNode*>& pNodesList, unsigned int nRGNTag);
	static bool PatchClientsRecursive(const ZSpatialEntity* pSpatial, TArray<ZRenderGraphNode*>& pNodesList, int& indexInNodesList, const int indexStart, const int nodeCount);
	bool IsActiveRenderGraphNode() const;
	ZRenderableEntity& operator=(const ZRenderableEntity& __that);
};
