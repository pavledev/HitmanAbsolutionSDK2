#pragma once

#include "TEntityRef.h"
#include "EWeaponSetLocation.h"

class IHM5Item;

class ZHM5WeaponSet
{
public:
	TEntityRef<IHM5Item> m_rItems[2];

	union
	{
		unsigned char m_unionInt;

		struct
		{
			bool m_bCanDualWield : 1;
			bool m_bDualWieldMode : 1;
		};
	};

	ZHM5WeaponSet(const ZHM5WeaponSet& __that);
	ZHM5WeaponSet() = default;
	~ZHM5WeaponSet() = default;
	void Reset();
	TEntityRef<IHM5Item> GetItem(EWeaponSetLocation eLoc) const;
	TEntityRef<IHM5Item> GetItem_WithoutChecks(EWeaponSetLocation eLoc) const;
	void SetItem(EWeaponSetLocation eLoc, const TEntityRef<IHM5Item>& rItem);
	void SetDualWieldMode(bool bVal);
	bool InDualWieldMode() const;
	bool CanDualWield() const;
	ZHM5WeaponSet& operator=(const ZHM5WeaponSet& __that);
};
