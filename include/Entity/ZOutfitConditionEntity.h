#pragma once

#include "ZBaseConditionEntity.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class IHM5Outfit;
class ZComponentCreateInfo;
class ZHM5Outfit;
class ZString;
struct STypeID;
template <class T> class TEntityRef;

class ZOutfitConditionEntity : public ZBaseConditionEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZHM5Outfit>> m_OutfitList;

	static SComponentMapEntry s_componentMap[0];

	~ZOutfitConditionEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZOutfitConditionEntity() = default;
	static void RegisterType();
	ZOutfitConditionEntity(ZComponentCreateInfo& info);
	void OutfitChangedEventHandler(TEntityRef<IHM5Outfit> pOldOutfit, TEntityRef<IHM5Outfit> pNewOutfit);
};
