#pragma once

#include "HM5Utils.h"

class ZHM5LocomotionNetwork;

class PullToAngle
{
public:
	bool m_bInit;
	float m_fTurnAccel;
	float m_fTurnSpeed;
	float m_fPrevMoveAngle;
	float m_fReverseSpeedReset;
	float m_fZeroThreshold;
	float m_fInitSpeed;
	float m_fInitAccel;
	float m_fMaxSpeed;
	float m_fPrevDelta;
	float m_fMaxSpeedMult;
	float m_fAllSpeedMult;
	bool m_bDisableCameraCompensation;
	bool m_bUseAnimBlends;
	HM5Utils::SAnimBlend m_TurnBlendLeft90;
	HM5Utils::SAnimBlend m_TurnBlendLeft180;
	HM5Utils::SAnimBlend m_TurnBlendRight90;
	HM5Utils::SAnimBlend m_TurnBlendRight180;
	HM5Utils::SAnimBlend m_TurnBlendLeft90s;
	HM5Utils::SAnimBlend m_TurnBlendLeft180s;
	HM5Utils::SAnimBlend m_TurnBlendRight90s;
	HM5Utils::SAnimBlend m_TurnBlendRight180s;
	HM5Utils::SAnimBlend* m_pCurrentBlend;
	SMatrix m_BlendStartMtx;
	SMatrix m_BlendEndMtx;
	SMatrix m_BlendPrevMtx;
	ZHM5LocomotionNetwork* m_pLocomotionNetwork;

	PullToAngle() = default;
	PullToAngle(float _reverse_speed_reset, float _init_speed, float _init_accel, float _max_speed, bool disable_cam_compensation);
	~PullToAngle() = default;
	void InitAnimBlends(ZHM5LocomotionNetwork* locoNetwork);
	void Reset();
	float AlignTurnAngleToCamera(float fDeltaAngle, float from, float to);
	float Update(float deltaTime, float from, float to, bool forceDirection, float direction, bool turnactive, float animfraction);
	void SetMaxSpeed(float v);
	void SetInitSpeed(float v);
	void SetReverseSpeed(float v);
};
