#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "STokenID.h"
#include "TArray.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZDynamicResourceLibrary;
class ZGlobalItemKit;
class ZMetaContentAccessEntity;
class ZRuntimeResourceIDEntity;
class ZTextListData;
class ZTokenIDEntity;
struct STypeID;

class ZDLCDescriptor : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EWhenToShowDiscoverMessage
	{
		OnEveryDiscovery = 0,
		OnFirstDiscoveryOnly = 1,
		IgnoreDiscovery = 2
	};

	ZString m_sTitleID;
	ZString m_sDiscoveredDescriptionID;
	EWhenToShowDiscoverMessage m_eShowDiscoverMessage;
	TResourcePtr<ZTextListData> m_pTextListResource;
	TArray<TEntityRef<ZRuntimeResourceIDEntity>> m_MenuEntities2;
	TArray<TEntityRef<ZMetaContentAccessEntity>> m_MetaContent;
	TArray<TEntityRef<ZGlobalItemKit>> m_GlobalKits;
	TEntityRef<ZTokenIDEntity> m_TokenID;
	TArray<ZDynamicResourceLibrary*> m_aMenuEntityLibraries;

	static SComponentMapEntry s_componentMap[0];

	~ZDLCDescriptor() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZDLCDescriptor() = default;
	static void RegisterType();
	ZDLCDescriptor(ZComponentCreateInfo& Info);
	void RequestCreateForFrontend();
	void RequestDeleteForFrontend();
	void ExecuteMetaContent() const;
	bool IsValidInCurrentContext() const;
	ZString GetLocalizedTitle() const;
	ZString GetLocalizedDiscoveredMessage() const;
	const STokenID& GetTokenID() const;
	EWhenToShowDiscoverMessage GetWhenToShowDiscoveredMessage() const;
	bool HasDLCUnlockBeenGranted(const STokenID& token) const;
};
