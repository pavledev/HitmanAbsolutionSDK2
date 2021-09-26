#pragma once

#include "ECameraState.h"
#include "ECameraOffset.h"
#include "SMatrix.h"
#include "SVector3.h"

struct SCameraUpdateEvent
{
	ECameraState m_eCameraState;
	bool m_bControlCameraStateBlend;
	float m_fCameraStateFraction;
	bool m_bResetPitchAngleAtStateChange;
	bool m_bResetYawAngleAtStateChange;
	bool m_bAlignYawAngleInWorldSpace;
	float m_fResetPitchAngle;
	float m_fResetYawAngle;
	bool m_bControlCameraOffsetBlend;
	ECameraOffset m_eCameraOffset;
	float m_fCameraOffsetFraction;
	bool m_bControlCameraSideBlend;
	bool m_bControlCameraSide;
	bool m_bCameraRightSide;
	bool m_bResetCollision;
	bool m_bResetInterpolateWhileMoving;
	float m_fCameraSideFraction;
	bool m_bUpdateYawBase;
	SMatrix m_mCameraGround;
	float m_fTurnModifier;
	SVector3 m_vCameraGlobalOffset;
	float m_fAimFraction;
	bool m_bEnableCollision;

	SCameraUpdateEvent() = default;
	~SCameraUpdateEvent() = default;
	void Reset();
};
