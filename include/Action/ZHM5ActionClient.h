#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "ZHM5ActionClientRayCaster.h"

class ZHitman5;
class IHM5ItemWeapon;
class ZHM5Action;

class ZHM5ActionClient
{
public:
	enum
	{
		MAX_NON_PICKUPS = 32,
		MAX_PICKUPS = 32,
		MAX_FAR_ACTIONS = 8
	};

	enum EActionFilterReason
	{
		eAFR_Movement = 0,
		eAFR_Instinct = 1,
		eAFR_ItemHandling = 2,
		eAFR_NUM = 3
	};

	enum eActionGroup
	{
		eAG_General = 0,
		eAG_Pickup = 1,
		eAG_DeadBody = 2,
		eAG_Disguise = 3,
		eAG_Automatic = 4,
		eAG_NUM = 5
	};

	enum ePersistentActions
	{
		ePersAct_DisguiseFromActor = 0,
		ePersAct_ContextSensitive = 1,
		ePersAct_DragBody = 2,
		ePersAct_NUM = 3
	};

	TArray<TEntityRef<ZHM5Action>> m_aCreatedActions;
	TArray<TEntityRef<IHM5ItemWeapon>> m_AmmoCollectorWeapons;
	ZHM5ActionClientRayCaster m_RayCaster;
	ZHM5Action* m_pActiveActions[5];
	ZHM5Action* m_pPersistentActions[3];
	ZHM5Action* m_pFarActions[8];
	TEntityRef<ZHitman5> m_pHitman;
	unsigned int m_nActionFilter[3];
	unsigned int m_iFarFeedbackPrompts;
	unsigned int m_iActiveActionsCount;
	bool m_bUseablePropAvailable;

	ZHM5ActionClient() = default;
	ZHM5ActionClient(TEntityRef<ZHitman5> pHitman);
	~ZHM5ActionClient() = default;
	void ResetActionFilterAll();
	void SetActionFilter(unsigned int nFilter, EActionFilterReason reason);
	bool IsTakeDisguisePossible() const;
	bool IsDragBodyPossible() const;
	const ZHM5Action* GetClosestPickupAction() const;
	bool GetUseablePropAvailable() const;
	bool IsGeneralActionAvailable() const;
	bool IsDoorActionAvailable() const;
	void CollectActions();
	void ExecuteActions();
	void DeactivateCheckPoint();
	const ZHM5Action** GetFarActions() const;
	TEntityRef<ZHitman5> Hitman() const;
	bool ActionClientEnabled() const;
	void Init();
	unsigned int GetActionFilter() const;
	void ProcessAmmoSucking();
	void FilterPickups(ZHM5Action** pPickups, unsigned int& iNumPickups);
	void SortWeaponsAndAmmoPickups(ZHM5Action** pPickups, unsigned int& iNumPickups);
	bool PickupOrSwap(ZHM5Action* pActionToCheck);
	ZHM5Action* UpdateClosestDisguise(ZHM5Action** pOtherActions, unsigned int iNumOtherActions);
	ZHM5Action* UpdateDragBodyAction();
	void UpdateDeadBodyFarFeedback();
	void UpdateContextSensAction(ZHM5Action** pOtherActions, unsigned int& iNumOtherActions);
	void FilterActions(ZHM5Action** pOtherActions, unsigned int& iNumOtherActions);
	void SwapActions(ZHM5Action** pOtherActions, unsigned int& iNumOtherActions);
	bool IsAbortAction(unsigned int iType) const;
	void PushFarFeedback(ZHM5Action* pAction);
	void CallExecuteOnAction(eActionGroup actionGroup, bool bAlternativeActivated);
};
