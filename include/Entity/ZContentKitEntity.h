#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTextListData;
class ZTokenIDEntity;
struct STokenID;
struct STypeID;

class __declspec(novtable) ZContentKitEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EShowContent
	{
		YES = 0,
		NO = 1,
		ONLY_WHEN_UNLOCKED = 2
	};

	TEntityRef<ZTokenIDEntity> m_Token;
	ZString m_TitleLoganID;
	ZString m_DescriptionLoganID;
	TResourcePtr<ZTextListData> m_pTextListResource;
	ZString m_sCachedTitle;
	ZString m_sCachedDescription;
	EShowContent m_eShowInNotebook;
	EShowContent m_eShowOnCampaignEndScreen;
	EShowContent m_eShowOnContractsEndScreen;
	EShowContent m_eShowInSafeHouse;
	EShowContent m_eShowInGearSelection;
	bool m_bStartsLocked;
	int m_iUnlockPrice;

	static SComponentMapEntry s_componentMap[0];

	~ZContentKitEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual bool PickedUp(int param1, int param2) = 0;
	virtual bool WasPickedUp(int param1, int param2) = 0;
	virtual bool IsNewPickUp(int param1, int param2) = 0;

	ZContentKitEntity() = default;
	static void RegisterType();
	ZContentKitEntity(ZComponentCreateInfo& Info);
	void ParseAllLocalized();
	const TEntityRef<ZTokenIDEntity>& GetToken() const;
	const STokenID& GetTokenID() const;
	const ZString& GetLocalizedTitle() const;
	const ZString& GetLocalizedDescription() const;
	int GetUnlockPrice() const;
	bool StartsLocked() const;
	bool ShowInNotebook() const;
	bool ShowOnCampaignEndScreen() const;
	bool ShowOnContractsEndScreen() const;
	bool ShowInSafeHouse() const;
	bool ShowInGearSelection() const;
	void OnTitleChanged();
	void OnDescriptionChanged();
	void OnTextListChanged();
};
