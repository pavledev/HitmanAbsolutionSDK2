#pragma once

#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"
#include "STokenID.h"

class ZHM5ProjectileDamageProperties
{
public:
	float m_fMuzzleVelocity;
	float m_fCloseRange;
	float m_fNearRange;
	float m_fMediumRange;
	float m_fFarRange;
	float m_fDamageMultiplier;
	float m_fMuzzleEnergyMultiplier;
	ZEntityRef m_rOwner;
	TEntityRef<IHM5ItemWeapon> m_rWeapon;
	IHM5AmmoProperties* m_pAmmoProperties;
	eWeaponType m_eWeaponType;
	eItemType m_eItemType;
	EHM5SoundBulletType m_eSoundBulletType;
	float4 m_vMuzzleExitPos;
	float4 m_vTracerStartPos;
	bool m_bTracerRound;
	STokenID m_ItemTypeToken;

	ZHM5ProjectileDamageProperties(const TEntityRef<IHM5ItemWeapon>& rWeapon, IHM5AmmoProperties* pAmmoProperties);
	ZHM5ProjectileDamageProperties() = default;
	void Init(const TEntityRef<IHM5ItemWeapon>& rWeapon, IHM5AmmoProperties* pAmmoProperties);
	void SetDamageMultipier(float fValue);
	void SetTracerRound(bool bIsTracerRound);
	void SetTracerStartPos(const float4& vPos);
	float GetMuzzleVelocity() const;
	float GetCloseRange() const;
	float GetNearRange() const;
	float GetMediumRange() const;
	float GetFarRange() const;
	float GetDamageMultiplier() const;
	const ZEntityRef& GetOwner() const;
	const TEntityRef<IHM5ItemWeapon>& GetWeapon() const;
	IHM5AmmoProperties* GetAmmoProperties() const;
	float GetMuzzleEnergyMultiplier() const;
	EHM5SoundBulletType GetSoundBulletType() const;
	bool GetTracerRound() const;
	float4 GetTracerStartPos() const;
	eWeaponType GetWeaponType() const;
	eItemType GetItemType() const;
	float CalculateProjectileDamage(float fRange);
	const STokenID& GetItemTypeToken() const;
	~ZHM5ProjectileDamageProperties() = default;
	ZHM5ProjectileDamageProperties& operator=(const ZHM5ProjectileDamageProperties& __that);
};
