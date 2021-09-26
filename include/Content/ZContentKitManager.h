#pragma once

#include "IComponentInterface.h"
#include "ZContentKitList.h"
#include "TArrayEnumerator.h"
#include "ZContentKitHelper.h"
#include "TMapValueEnumerator.h"
#include "ESaveLoadSlotStatus.h"
#include "STokenID.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "TMap.h"
#include "ZResourcePtr.h"
#include "ZShadowContentKitList.h"
#include "ZVariantRef.h"

class IHM5Item;
class ZContentKitDLCInfo;
class ZContentKitEntity;
class ZContentKitMenuSetup;
class ZDLCDescriptor;
class ZFireArmKitEntity;
class ZFireArmKitMenuSetup;
class ZGlobalItemKit;
class ZGlobalOutfitKit;
class ZOutfitKitEntity;
class ZOutfitKitMenuSetup;
class ZPropKitEntity;
class ZPropKitMenuSetup;
class ZRuntimeResourceID;
class ZString;
struct SComponentMapEntry;
struct SContentKitBaseState;
struct SFireArmKitSaveData;
struct SFireArmKitState;
struct SOutfitKitSaveData;
struct SOutfitKitState;
struct SPropKitSaveData;
struct SPropKitState;
struct STypeID;

class ZContentKitManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SRuntimeItemResource
	{
		ZResourcePtr pResource;
		unsigned int nRefCount;

		SRuntimeItemResource(const SRuntimeItemResource& __that);
		SRuntimeItemResource() = default;
		~SRuntimeItemResource() = default;
		SRuntimeItemResource& operator=(const SRuntimeItemResource& __that);
	};

	ZContentKitList<ZFireArmKitEntity, ZFireArmKitMenuSetup, SFireArmKitSaveData, SFireArmKitState> m_FireArms;
	ZContentKitList<ZOutfitKitEntity, ZOutfitKitMenuSetup, SOutfitKitSaveData, SOutfitKitState> m_Outfits;
	ZContentKitList<ZPropKitEntity, ZPropKitMenuSetup, SPropKitSaveData, SPropKitState> m_Props;
	TMap<STokenID const, TEntityRef<ZContentKitDLCInfo>> m_KitDLCInfos;
	TMap<STokenID const, SRuntimeItemResource> m_RuntimeItemResources;
	TMap<STokenID const, TEntityRef<ZGlobalOutfitKit>> m_GlobalOutfitKits;
	TMap<STokenID const, TEntityRef<ZGlobalItemKit>> m_GlobalItemKits;
	TArray<TEntityRef<ZDLCDescriptor>> m_DLCDescriptors;
	TArray<STokenID> m_DLCUnlocksGranted;

	~ZContentKitManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZContentKitManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	bool RegisterKit(const TEntityRef<ZContentKitEntity>& rKit, const TEntityRef<ZContentKitMenuSetup>& rMenu);
	bool UnregisterKit(const TEntityRef<ZContentKitEntity>& rKit);
	void RegisterDLCInfo(const TEntityRef<ZContentKitDLCInfo>& rDLCInfo);
	void UnregisterDLCInfo(const TEntityRef<ZContentKitDLCInfo>& rDLCInfo);
	void RegisterItemRuntimeResource(const STokenID& id, const ZResourcePtr& resourcePrt);
	void UnregisterItemRuntimeResource(const STokenID& id);
	ZResourcePtr GetItemRuntimeResource(const STokenID& id);
	int GetItemRuntimeResourceCount() const;
	void RegisterGlobalOutfitKit(const STokenID& id, const TEntityRef<ZGlobalOutfitKit>& pEntity);
	void UnregisterGlobalOutfitKit(const STokenID& id);
	TEntityRef<ZGlobalOutfitKit> GetGlobalOutfitKit(ZRuntimeResourceID resourceId);
	const TEntityRef<ZGlobalOutfitKit>& GetGlobalOutfitKit(const STokenID& id);
	void RegisterGlobalItemKit(const STokenID& id, const TEntityRef<ZGlobalItemKit>& pEntity);
	void UnregisterGlobalItemKit(const STokenID& id);
	const TEntityRef<ZGlobalItemKit>& GetGlobalItemKit(const STokenID& id);
	TArrayEnumerator<ZShadowContentKitList::SEntry const> GetFireArmEnumerator() const;
	int GetFireArmCount() const;
	TArrayEnumerator<ZShadowContentKitList::SEntry const> GetDisguiseEnumerator() const;
	int GetDisguiseCount() const;
	TArrayEnumerator<ZShadowContentKitList::SEntry const> GetPropEnumerator() const;
	int GetPropCount() const;
	TEntityRef<ZFireArmKitEntity> FindFireArmKitByID(const STokenID& id);
	TEntityRef<ZOutfitKitEntity> FindOutfitKitByID(const STokenID& id);
	TEntityRef<ZPropKitEntity> FindPropKitByID(const STokenID& id);
	TEntityRef<ZFireArmKitMenuSetup> FindFireArmKitMenuByID(const STokenID& id);
	TEntityRef<ZOutfitKitMenuSetup> FindOutfitKitMenuByID(const STokenID& id);
	TEntityRef<ZPropKitMenuSetup> FindPropKitMenuByID(const STokenID& id);
	SFireArmKitState* GetFireArmPersistentState(const STokenID& id);
	SOutfitKitState* GetOutfitPersistentState(const STokenID& id);
	SPropKitState* GetPropPersistentState(const STokenID& id);
	SContentKitBaseState* GetContentKitBaseState(const STokenID& id);
	void SaveFireArmPersistentState(const TEntityRef<ZFireArmKitEntity>& rFireArmKit);
	void SaveOutfitPersistentState(const TEntityRef<ZOutfitKitEntity>& rOutfitKit);
	bool AttemptMarkFireArmPickedUp(const TEntityRef<ZFireArmKitEntity>& rFireArmKit, int lvl, int cp);
	ZContentKitHelper::EUnlockStateReason UnlockOnPickupItem(const TEntityRef<IHM5Item>& rItem);
	ZContentKitHelper::EUnlockStateReason UnlockOnPurchaseItem(const TEntityRef<ZFireArmKitEntity>& rFireArmKit, bool bViewed, bool bSendMessageToServer);
	ZContentKitHelper::EUnlockStateReason UnlockDisguiseOnChangeClothes(const TEntityRef<ZOutfitKitEntity>& rOutfitKit);
	ZContentKitHelper::EUnlockStateReason UnlockDisguiseOnPurchase(const TEntityRef<ZOutfitKitEntity>& rOutfitKit, bool bViewed);
	ZContentKitHelper::EUnlockStateReason GenericUnlock(const STokenID& id);
	TMapValueEnumerator<STokenID const, TEntityRef<ZContentKitDLCInfo>> GetDLCInfoEnumerator();
	bool FindDLCInfo(const STokenID& tokenID, TEntityRef<ZContentKitDLCInfo>& rOut);
	void RegisterDLCDescriptor(const TEntityRef<ZDLCDescriptor>& pDescriptor);
	void UnregisterDLCDescriptor(const TEntityRef<ZDLCDescriptor>& pDescriptor);
	void RequestDLCDescriptorCreateForFrontend();
	void RequestDLCDescriptorDeleteForFrontend();
	TArrayEnumerator<TEntityRef<ZDLCDescriptor>> GetDLCDescriptorEnumerator();
	bool HasDLCUnlockBeenGranted(const STokenID& token) const;
	int GetTotalItemsCount();
	int GetPickedUpItemsCount(int eLevelIndex, int cp);
	void CheckStartsUnlocked();
	void RefreshCallFromMenu();
	void UnlockAllItems();
	void UnlockAllOutfits();
	void EmptyLists();
	void CheckUnlockAllAchievement();
	void CheckUnlockedAllWeaponUpgrades();
	void OnSavegameLoadDone(ESaveLoadSlotStatus eStatus);
	void OnActiveTextLocaleChanged();
	void OnStart(const ZString& sEvent, const ZVariantRef& val);
	void OnStop(const ZString& sEvent, const ZVariantRef& val);
	void RefreshFromSaveGame();
	void OnWalletSpendAsync_Callback(unsigned int iID, bool bSuccess, int nParam);
};
