#include "TTypeIDHelper.h"
#include "BaseAddresses.h"
#include "IHM5Item.h"
#include "ZHM5ItemWeapon.h"
#include "ZHM5ItemCCWeapon.h"
#include "ZHM5ItemAmmo.h"

template <>
unsigned int TTypeIDHelper<IHM5Item>::TypeIDOffset()
{
	return BaseAddresses::hitman5Dll + 0xA9670;
}

template <>
unsigned int TTypeIDHelper<ZHM5ItemWeapon>::TypeIDOffset()
{
	return BaseAddresses::hitman5Dll + 0x824C0;
}

template <>
unsigned int TTypeIDHelper<ZHM5ItemCCWeapon>::TypeIDOffset()
{
	return BaseAddresses::hitman5Dll + 0x13CC40;
}

template <>
unsigned int TTypeIDHelper<ZHM5ItemAmmo>::TypeIDOffset()
{
	return BaseAddresses::hitman5Dll + 0x3C5A50;
}
