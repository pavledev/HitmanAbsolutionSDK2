#pragma once

#include "ZEntityImpl.h"
#include "STokenID.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;

class ZGlobalOutfitKit : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	STokenID m_TokenId;
	TResourcePtr<ZEntityRef> m_TokenResource;
	ZRuntimeResourceID m_OutfitResource1;
	ZRuntimeResourceID m_OutfitResource2;
	ZRuntimeResourceID m_OutfitResource3;
	ZRuntimeResourceID m_OutfitResource4;
	ZRuntimeResourceID m_OutfitResource5;
	ZRuntimeResourceID m_OutfitResource6;
	ZRuntimeResourceID m_OutfitResource7;
	ZRuntimeResourceID m_OutfitResource8;
	ZRuntimeResourceID m_OutfitResource9;
	ZRuntimeResourceID m_OutfitResource10;
	ZRuntimeResourceID m_OutfitResource11;
	ZRuntimeResourceID m_OutfitResource12;

	static SComponentMapEntry s_componentMap[0];

	~ZGlobalOutfitKit() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual const STokenID& GetTokenID() const;

	ZGlobalOutfitKit() = default;
	static void RegisterType();
	ZGlobalOutfitKit(ZComponentCreateInfo& info);
	ZRuntimeResourceID GetVariationResource(int nVariation);
	int GetVariationIndex(ZRuntimeResourceID resourceId);
	void OnTokenResourceChanged();
};
