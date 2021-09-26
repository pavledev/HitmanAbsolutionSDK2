#pragma once

#include "ZContentKitEntity.h"
#include "SActorSoundDefs.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTokenIDEntity;
struct STokenID;
struct STypeID;
template <class T> class TEntityRef;

class ZOutfitKitEntity : public ZContentKitEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bIsNewPickup;
	SActorSoundDefs::EDefinition m_eSpeakSound;
	int m_nRatingAgainstSame;
	int m_nRating;
	int m_nArmorRating;
	bool m_bWeaponsAllowed;
	bool m_bAuthorityFigure;
	TArray<TEntityRef<ZTokenIDEntity>> m_aAllowedWeapons;
	ZRuntimeResourceID m_sHiResNotebookImage;

	static SComponentMapEntry s_componentMap[0];

	~ZOutfitKitEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool PickedUp(int lvl, int cp) override;
	bool WasPickedUp(int lvl, int cp) override;
	bool IsNewPickUp(int lvl, int cp) override;
	virtual int GetRatingAgainstSame() const;
	virtual int GetRatingAgainstOther() const;
	virtual int GetArmorRating() const;
	virtual bool IsWeaponAllowed(const STokenID& weaponToken) const;
	virtual bool IsAuthorityFigure() const;
	virtual SActorSoundDefs::EDefinition GetRespondHitmanSpeak() const;

	ZOutfitKitEntity() = default;
	static void RegisterType();
	ZOutfitKitEntity(ZComponentCreateInfo& Info);
	ZRuntimeResourceID GetLargeIconRID() const;
};
