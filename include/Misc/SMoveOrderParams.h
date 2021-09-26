#pragma once

#include "SOrderParamsBase.h"
#include "SMoveSpeedConfiguration.h"
#include "EBooleanOption.h"
#include "EMoveEndState.h"
#include "EMoveSpeed.h"
#include "TMaxArray.h"
#include "ZEntityRef.h"
#include "ZPositionTarget.h"
#include "float4.h"

class ZPF5Location;

struct SMoveOrderParams : SOrderParamsBase
{
	SMoveSpeedConfiguration m_moveSpeedConfiguration;
	float m_fStopMoveDistance;
	EBooleanOption m_bAllowStrafe;
	EBooleanOption m_bCrouch;
	EMoveSpeed m_speed;
	EMoveSpeed m_minSpeed;
	bool m_bPrecisePositioning;
	bool m_bIgnoreEndCollision;
	float4 m_wsFinalFacingDirection;
	TMaxArray<ZPF5Location, 8> m_waypointList;
	bool m_bEndInCrouch : 1;
	bool m_bOnlyUseReposition : 1;
	bool m_bDisableTurnInPlaceReposition : 1;
	EMoveEndState m_endState;
	ZEntityRef m_rApproachLookAtEntity;
	float m_fApproachLookAtDistance;
	float4 m_vApproachLookAtPosition;

	static const unsigned int MAX_NUMBER_OF_WAYPOINTS;

	~SMoveOrderParams() override = default;

	SMoveOrderParams(const SMoveOrderParams& __that);
	SMoveOrderParams() = default;
	SMoveOrderParams(const TMaxArray<ZPF5Location, 8>& waypoints);
	SMoveOrderParams(const ZPF5Location& endLocation, EMoveSpeed speed);
	SMoveOrderParams& MoveSpeed(EMoveSpeed moveSpeed);
	SMoveOrderParams& EndState(EMoveEndState endState);
	SMoveOrderParams& ApproachLookAt(const ZEntityRef& pEntity, float fDistance);
	SMoveOrderParams& ApproachLookAt(const float4& vPosition, float fDistance);
	SMoveOrderParams& PrecisePositioning(bool bPrecise);
	SMoveOrderParams& Strafe(bool bAllowStrafe);
	SMoveOrderParams& Crouch(bool bCrouch);
	SMoveOrderParams& EndInCrouch(bool bEndInCrouch);
	SMoveOrderParams& Aim(const ZPositionTarget& target);
	SMoveOrderParams& Face(const ZPositionTarget& target);
	SMoveOrderParams& AimAndFace(const ZPositionTarget& target);
	SMoveOrderParams& LookAt(const ZPositionTarget& target);
	SMoveOrderParams& ClearLookAt();
	SMoveOrderParams& FaceAndLookAt(const ZPositionTarget& target);
	SMoveOrderParams& FinalFacingDirection(const float4& wsEndDirection);
	SMoveOrderParams& RepositionOnly(bool bEnable);
	SMoveOrderParams& StopMoveDistance(float fStopMoveDistance);
	SMoveOrderParams& MoveSpeedConfiguration(const SMoveSpeedConfiguration speedConfig);
	SMoveOrderParams& IgnoreEndCollision();
	float GetPositionThreshold() const;
	bool HasPreciseOrientation() const;
	float4 GetFinalFacingDirection(const float4& wsPosition, const float4& wsCurrentFacing) const;
	float4 GetIntermediateFacingDirection(const float4& wsPosition, const float4& wsCurrentFacing) const;
	void ApplyDefaultValues();
	ZPF5Location& EndLocation();
	SMoveOrderParams& operator=(const SMoveOrderParams& __that);
};
