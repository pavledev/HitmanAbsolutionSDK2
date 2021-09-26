#pragma once

#include "ZHM5BaseController.h"
#include "ZMapPoly.h"
#include "ZHM5ItemWeapon.h"

class ZHM5WeaponRecoil : public ZHM5BaseController
{
public:
	float m_fTime;
	float m_fRecoilDelay;
	float m_fRecoilTime;
	float m_fRecoilFraction;
	float m_fRecoilRecoverySpeed;
	float m_fRecoilDuration;
	float m_fRecoilMaxLength;
	float m_fRecoveryFraction;
	float m_fRecoveryDuration;
	float m_fRecoilTechniqueModifier;
	SVector2 m_vRecoil;
	SVector2 m_vAccumlatedRecoil;
	SVector2 m_vRecovery;
	ZMapPoly m_MapPoly;
	TEntityRef<ZHitman5> m_pHitman;

	~ZHM5WeaponRecoil() override = default;
	void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent) override;
	void Reset(EHM5ResetReason eResetReason) override;

	ZHM5WeaponRecoil() = default;
	ZHM5WeaponRecoil(const TEntityRef<ZHitman5>& pHitman, EHM5BaseControllerType eBaseControllerType);
	void RecoilWeapon(const TEntityRef<ZHM5ItemWeapon>& rWeapon);
	void SetRecoilTechniqueModifier(float fVal);
	SVector2 GetWeaponRecoil() const;
	SVector2 GetRecoil(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	void ResetInternal();
};
