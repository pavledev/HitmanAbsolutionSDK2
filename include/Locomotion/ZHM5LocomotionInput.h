#pragma once

#include "ZEvent2.h"
#include "ENetworkControlParam.h"
#include "ZMapEaseToState.h"
#include "ZMapPoly.h"

struct float4;
class ZVariantRef;

class ZHM5LocomotionInput
{
public:
	ZEvent2<ENetworkControlParam, ZVariantRef const&> SetControlParameterEvent;
	float m_fSampleTime;
	float m_fMoveDirX;
	float m_fMoveDirY;
	float m_fStickAngle;
	float m_fMoveSpeed;
	float m_fDeltaSpeedStick;
	float m_fCamAngle;
	float m_fTargetFastWalkSpeedFraction;
	float m_fFastWalkSpeedFraction;
	float m_fMoveSpeedLocked;
	float m_fMoveAngleLocked;
	float m_fMoveAngle;
	float m_fWalkRunBlendWeight;
	float m_fWalkRunInput;
	float m_fLockMoveAngle;
	float m_fLockMoveAngleRange;
	bool m_bLockMoveAngle;
	bool m_bRunActivated;
	bool m_bRun;
	bool m_bSneaking;
	bool m_bStrafing;
	float m_fCapX;
	float m_fCapY;
	float m_flpX;
	float m_flpY;
	float m_fPrevRawInputX;
	float m_fPrevRawInputY;
	float m_fFlickTimer;
	bool m_bFirstUpdate;
	ZMapEaseToState m_RunMap;
	ZMapPoly m_RunMapFunction;

	ZHM5LocomotionInput() = default;
	~ZHM5LocomotionInput() = default;
	void Reset(float fCharAngle);
	void Update(float fDeltaTime, float fRawInputX, float fRawInputY, bool bActivateRun, bool bSneak, float fSneakWeight, bool bStrafe, bool bAllowFastWalk, const float4& vCamDir);
	float GetStickAngle() const;
	float GetMoveSpeed() const;
	float GetMoveSpeedLocked() const;
	float GetDeltaSpeedStick() const;
	float GetMoveAngle() const;
	float GetMoveAngleLocked() const;
	bool IsSneaking() const;
	bool IsStrafing() const;
	bool IsMoveAngleLocked() const;
	bool GetRunActivated() const;
	bool IsRunning() const;
	bool IsWalkingFast() const;
	float GetWalkRunBlendWeight() const;
	float GetCamAngle() const;
	void SetMoveAngle(float fMoveAngle);
	void ForceRunStop();
	void SetRun(bool bRun);
	void ResetMoveFastBlend();
	bool IsGoodToTurn(float fInputX, float fInputY);
	void ResetMoveAngleLocked();
	void LockMoveAngle(bool bLock, float fAngle, float fAngleRange);
	float Remap(float fValue, float fThreshold) const;
};
