#pragma once

#include "ZHM5Item.h"
#include "IHM5ItemAmmo.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"
#include "eAmmoType.h"

class ZComponentCreateInfo;
struct STypeID;

class ZHM5ItemAmmo : public ZHM5Item, public IHM5ItemAmmo
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nNumberOfAmmo;
	bool m_bInfiniteAmmo;
	eAmmoType m_AmmoType;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5ItemAmmo() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	int GetNumberOfAmmo() const override;
	void SetNumberOfAmmo(int nNumOfAmmo) override;
	bool IsInfinite() const override;
	eAmmoType GetAmmoType() const override;

	ZHM5ItemAmmo() = default;
	static void RegisterType();
	ZHM5ItemAmmo(ZComponentCreateInfo& pInfo);
};
