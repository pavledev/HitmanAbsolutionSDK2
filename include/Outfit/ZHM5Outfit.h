#pragma once

#include "ZEntityImpl.h"
#include "IHM5Outfit.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "STokenID.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTokenIDEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZHM5Outfit : public ZEntityImpl, public IHM5Outfit
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_iZoneMask;
	bool m_bZoneDefault;
	bool m_bZoneA;
	bool m_bZoneB;
	bool m_bZoneC;
	bool m_bZoneD;
	bool m_bZoneE;
	bool m_bZoneF;
	bool m_bZoneG;
	bool m_bZoneH;
	TArray<TEntityRef<ZTokenIDEntity>> m_aOutfitTokens;
	TResourcePtr<ZEntityRef> m_ContentKitEntity;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5Outfit() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	bool IsAllowedIn(const ZEntityRef& zone) const override;
	int GetZoneMask() const override;
	bool SupportsActor(const STokenID& token) override;

	ZHM5Outfit() = default;
	static void RegisterType();
	ZHM5Outfit(ZComponentCreateInfo& pInfo);
	void Setup(int iZoneMask, bool bWeaponsAllowed);
	TArrayRef<TEntityRef<ZTokenIDEntity>> GetOutfitTokens();
	void OnContentKitEntityChanged();
};
