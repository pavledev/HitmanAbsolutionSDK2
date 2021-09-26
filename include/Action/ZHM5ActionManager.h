#pragma once

#include "IComponentInterface.h"
#include "TSList.h"
#include "TSListIterator.h"
#include "ZGameTime.h"
#include "ZVariantRef.h"

class ZAABBTreeNode;
class ZHM5Action;
struct SComponentMapEntry;
struct STypeID;
struct float4;

class ZHM5ActionManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SActionTreeEntry
	{
		ZHM5Action* m_pNodeAction;
		void* m_pObjectNode;
	};

	TSList<SActionTreeEntry> m_Actions;
	ZAABBTreeNode* m_pAABBActionTree;
	TSList<ZHM5Action*> m_ObjectlessActions;
	ZGameTime m_LastUpdate;

	static ZHM5ActionManager* s_pActionManager;

	~ZHM5ActionManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5ActionManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Init();
	void Update();
	unsigned int GetActionsOfType(const float4& vAABBMin, const float4& vAABBMax, ZHM5Action** aActions, int nMaxActionCount, int nActionType);
	unsigned int GetActionsOfType(ZHM5Action** aActions, int nMaxActionCount, int nActionType);
	void GetNearActions(const unsigned int iActionFilter, const float4& vAABBMin, const float4& vAABBMax, ZHM5Action** pPickups, ZHM5Action** pActions, unsigned int iMaxPickupSize, unsigned int iMaxActionSize, unsigned int& iNumPickups, unsigned int& iNumActions);
	void UpdateActionPositions();
	void RegisterAction(ZHM5Action* pAction);
	void UnregisterAction(ZHM5Action* pAction);
	void AttachActionToActionAABBTree(ZHM5Action* pAction);
	void DetachActionFromActionAABBTree(ZHM5Action* pAction);
	void RemoveAllActions();
	TSListIterator<SActionTreeEntry> FindActionEntry(const ZHM5Action* pAction);
	void AddObjectlessAction(ZHM5Action* pAction);
	void RemoveObjectlessAction(ZHM5Action* pAction);
};
