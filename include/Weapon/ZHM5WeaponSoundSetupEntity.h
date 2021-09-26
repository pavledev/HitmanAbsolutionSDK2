#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IHM5ItemWeapon;
class ZComponentCreateInfo;
struct STypeID;
template <class T> class TEntityRef;

class ZHM5WeaponSoundSetupEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EWeaponSoundSetupSignal
	{
		eWSSS_OwnedByNPC = 0,
		eWSSS_EmptyShot = 1,
		eWSSS_EndFire = 2,
		eWSSS_HM_EndFire = 3,
		eWSSS_HM_WeaponEquipped = 4,
		eWSSS_HM_WeaponUnequipped = 5,
		eWSSS_HM_WeaponSwapped = 6,
		eWSSS_TriggerRelease = 7,
		eWSSS_Hitman_AllShots = 8,
		eWSSS_NPC_AllShots = 9
	};

	int m_iLastShotsPerMinuteFired;

	static SComponentMapEntry s_componentMap[0];
	static const unsigned int m_snTriggerRelease;
	static const unsigned int m_snEmptyShot;
	static const unsigned int m_snHM_EndBurstShot;
	static const unsigned int m_snNPC_EndBurstShot;
	static const unsigned int m_snHM_BurstShot;
	static const unsigned int m_snHM_BurstShotSilenced;
	static const unsigned int m_snHM_SingleShot;
	static const unsigned int m_snHM_SingleShotSilenced;
	static const unsigned int m_snHM_WeaponEquipped;
	static const unsigned int m_snHM_WeaponUnequipped;
	static const unsigned int m_snHM_WeaponSwapped;
	static const unsigned int m_snOwnedByNPC;
	static const unsigned int m_snNPC_BurstShot;
	static const unsigned int m_snNPC_BurstShotSilenced;
	static const unsigned int m_snNPC_SingleShot;
	static const unsigned int m_snNPC_SingleShotSilenced;
	static const unsigned int m_snShotsPerMinute;
	static const unsigned int m_snShotInterval;

	~ZHM5WeaponSoundSetupEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5WeaponSoundSetupEntity() = default;
	static void RegisterType();
	ZHM5WeaponSoundSetupEntity(ZComponentCreateInfo& Info);
	void FireSignal(const TEntityRef<IHM5ItemWeapon>& rWeaponOwner, EWeaponSoundSetupSignal eSignal);
	void FireShotsPerMinutePins(const int iShotsPerMinute, bool bForce);
};
