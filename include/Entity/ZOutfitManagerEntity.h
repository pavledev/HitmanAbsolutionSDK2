#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "STokenID.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZHM5Outfit;
class ZString;
struct STypeID;

class ZOutfitManagerEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZHM5Outfit>> m_Outfits;

	static SComponentMapEntry s_componentMap[0];

	~ZOutfitManagerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZOutfitManagerEntity() = default;
	static void RegisterType();
	ZOutfitManagerEntity(ZComponentCreateInfo& pInfo);
	TEntityRef<ZHM5Outfit> GetOutfit(STokenID outfitToken);
};
