#pragma once

class ZFireArmKitEntity;
class ZOutfitKitEntity;
template <class T> class TEntityRef;

class ZContentKitHelper
{
public:
	enum EUnlockStateReason
	{
		UNKNOWN_KIT = 0,
		ALREADY_UNLOCKED = 1,
		SUCCESSFUL_UNLOCK = 2
	};

	ZContentKitHelper() = default;
	~ZContentKitHelper() = default;
	static void StoreLastUnlocked(const TEntityRef<ZOutfitKitEntity>& rKit);
	static void StoreLastUnlocked(const TEntityRef<ZFireArmKitEntity>& rKit);
};
