#pragma once

#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"
#include "ZLinkedEntity.h"
#include "ESlowDownState.h"
#include "ZHitman5.h"
#include "ZMapPoly.h"

class ZHM5SniperController
{
public:
	enum ESlowDownState
	{
		eSlowDownState_Normal = 0,
		eSlowDownState_Slow = 1,
		eSlowDownState_SlowingDown = 2,
		eSlowDownState_SpeedingUp = 3
	};

	TEntityRef<IHM5ItemWeapon> m_rSniper;
	TEntityRef<ZLinkedEntity> m_pReplica;
	int m_nCurScopeZoomIndex;
	float m_fBobingAngleX;
	float m_fBobingAngleY;
	bool m_bModelSwitched;
	SVector2 m_vDrag;
	float4 m_vSniperShootDir;
	bool m_bUpdateCamera;
	bool m_bResetCameraCollision;
	bool m_bActive;
	bool m_bEnableSlowdown;
	float m_fSlowDownTime;
	float m_fPrecisionAimTimer;
	ESlowDownState m_eSlowDownState;
	TEntityRef<ZHitman5> m_pHitman;
	float m_fMainCamFPSFovBefore;
	SHM5ScopeParameters m_ScopeParameters;
	float m_fRecoilTime;
	ZMapPoly m_MapPoly;
	float m_fZoomInTime;
	float m_fPrecisionAim;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnHairtriggerStart;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnHairtriggerStop;

	ZHM5SniperController() = default;
	ZHM5SniperController(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5SniperController() = default;
	void ActivateSniperMode(const TEntityRef<IHM5ItemWeapon>& rSniper);
	void DeactivateSniperMode();
	void UpdateSniperMode(const SGameUpdateEvent& updateEvent);
	void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile);
	void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const;
	float4 GetSniperShootDir() const;
	float GetPulseIncreaseOnShooting() const;
	void SetEnableSlowDown(bool bEnableSlowDown);
	bool GetEnableSlowDown() const;
	void WeaponFired();
	bool UpdateCamera() const;
	bool SniperModelActive() const;
	bool IsActive() const;
	int GetScopeZoomIndex() const;
	void UpdateSlowDown(float fDeltaTime, float fPrecisionAim);
};
