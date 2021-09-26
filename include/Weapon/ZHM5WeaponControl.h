#pragma once

#include "SWeaponControlFlags.h"
#include "sOTSAimFlags.h"
#include "sAimFlags.h"
#include "ZGameTime.h"
#include "ZMapPoly.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "ZHM5WeaponControlInputRepeater.h"

class ZHM5WeaponControl
{
public:
	enum EPropAnimType
	{
		ePropAnim_1H = 0,
		ePropAnim_2H = 1,
		ePropAnim_NumTypes = 2
	};

	enum eWeaponAutoReloadState
	{
		eWAR_NotSet = 0,
		eWAR_ReloadQueued = 1
	};

	SWeaponControlFlags m_WeaponControlFlags;
	sOTSAimFlags m_OTSFlags;
	sAimFlags& m_AimFlagsRef;
	ZGameTime m_TriggerReleaseTime;
	ZGameTime m_PreciseAimStartHoldTime;
	bool m_bHapticsPlayed;
	bool m_bCompletedSignalPending;
	float m_fLastValidImpactFraction;
	float m_fPreciseAimPrct;
	bool m_bRightHandWeaponFire;
	ZMapPoly m_MapPoly;
	eWeaponAutoReloadState m_eAutoReloadState;
	bool m_bWaitForBlindFireBlend;
	bool m_bStartAimCalled;
	bool m_bFocusCrosshairAnimStarted;
	ZEntityRef m_rPrecisionTarget;
	float m_fPrecisionTargetDelay;
	TEntityRef<ZHitman5> m_pHitman;
	ZHM5WeaponControlInputRepeater* m_pShootRepeater;
	ZGameTime m_tTimeSinceLastShotFired;
	ZGameTime m_tLastAimReleased;
	float m_fLHIKWeight;
	bool m_bWaitForTriggerRelease;
	bool m_bProjectilePreciseShot;
	bool m_bUpdateWeaponFire;

	virtual ~ZHM5WeaponControl() = default;

	ZHM5WeaponControl() = default;
	ZHM5WeaponControl(const TEntityRef<ZHitman5>& pHitman, sAimFlags& AimFlags);
	void Init();
	void Update();
	void UpdatePostCam();
	TEntityRef<ZHitman5> Hitman() const;
	void StopAim();
	float GetPreciseAimPrct();
	void ResetOTSFlags();
	void SetOTSPressed(bool bVal);
	void SetOTSBlocked();
	bool GetOTSBlocked() const;
	void WaitForTriggerRelease();
	bool IsWaitingForTriggerRelease() const;
	void ResetDualWeaponFireSelector();
	float GetCrosshairScale();
	bool ShouldDisplayCrosshair() const;
	void AimCallBack_Set(bool bRightHand);
	void AimCallBack_Reset();
	void OnWeaponsChanged();
	void OnWeaponFiredDry();
	void OnWeaponReloaded();
	SMatrix CalcGetProjectileStartMatPos() const;
	const SWeaponControlFlags& GetControlFlags() const;
	bool IsProjectilePreciseShot() const;
	void ResetFlags();
	void UpdateFlags();
	void UpdateWeaponControl();
	void UpdateOTSControl();
	void UpdateAimControl();
	void UpdateWeaponFire();
	void UpdateWeaponRecoilAnim(const TEntityRef<IHM5ItemWeapon> rWeapon);
	bool UpdateWeaponFire_IsBlindFireReady(const TEntityRef<IHM5ItemWeapon>& rWeaponRight, const TEntityRef<IHM5ItemWeapon>& rWeaponLeft);
	void UpdateWeaponFire_SingleWeapon(const TEntityRef<IHM5ItemWeapon>& rWeaponRight);
	void UpdateWeaponFire_DualPistols(const TEntityRef<IHM5ItemWeapon>& rWeaponRight, const TEntityRef<IHM5ItemWeapon>& rWeaponLeft);
	void UpdateWeaponFire_DualSMGs(const TEntityRef<IHM5ItemWeapon>& rWeaponRight, const TEntityRef<IHM5ItemWeapon>& rWeaponLeft);
	void OnFireWeaponTap(bool bRight);
	void OnFireWeaponRelease();
	bool OnOTSTap();
	void OnOTSRelease();
	void OnPrecisionShootStart();
	void OnPrecisionShootRelease();
	void OnPressAim();
	void UpdateLeftHandPos();
	void QueueReload();
	float4 GetShootPos() const;
	float GetWeaponPrecision() const;
	void ResetPrecisionShoot();
};
