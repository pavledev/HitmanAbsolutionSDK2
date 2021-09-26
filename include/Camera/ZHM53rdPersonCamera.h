#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "ZHM5Spring.h"
#include "SCameraCollisionVariable.h"
#include "ZMapPieceWiseLinear.h"
#include "SHM5GameCamAngles.h"
#include "SHM5GameCamAngleLimits.h"
#include "SHM5GameCamControls.h"
#include "SCameraPOI.h"
#include "SSoftCollisionCache.h"
#include "ECameraOffset.h"
#include "SCameraUpdateEvent.h"
#include "SHM5GameCamParams.h"
#include "IFutureCameraState.h"
#include "ECameraMode.h"
#include "ECameraState.h"
#include "SMatrix.h"
#include "SVector2.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "ZGameTime.h"
#include "ZMapPoly.h"
#include "float4.h"

class ICharacterController;
class ZHM5MainCamera;
class ZHitman5;
class ZSpatialEntity;
struct SCameraUpdate;
struct SGameUpdateEvent;
struct SHM5GameCamTransition;

class ZHM53rdPersonCamera : public ZHM5CameraBaseFunc
{
public:
	bool m_bActivateCamera;
	ZHM5Spring m_CamSpring;
	ZHM5Spring m_PitchSpring;
	SCameraCollisionVariable m_CameraDistance;
	float m_fPullInFraction;
	ZMapPieceWiseLinear m_MapPLHor;
	ZMapPieceWiseLinear m_MapPLVer;
	ECameraState m_eCameraState;
	bool m_bInterpolateWhileMoving;
	bool m_bInterpolateSideWhileMoving;
	float m_fYawBuffer;
	float m_fPitchBuffer;
	ZGameTime m_LastCamVertMoveTime;
	ZGameTime m_LastHeroStandTime;
	ZGameTime m_LastHeroAimTime;
	ZMapPoly m_MapPoly;
	SMatrix m_mCameraGround;
	float m_fSideStart;
	float m_fSideBlendTime;
	float m_fSideBlendDuration;
	float m_fSideBlendFraction;
	float m_fSide;
	bool m_bRightSide;
	float m_fZoomStart;
	float m_fZoomBlendTime;
	float m_fZoom;
	bool m_bZoom;
	ECameraOffset m_eCameraOffset;
	float m_fOffsetStart;
	float m_fOffset;
	float m_fOffsetBlendTime;
	bool m_bAlignYawPitch;
	bool m_bAlignYaw;
	bool m_bAlignPitch;
	float m_fAngleBlendTime;
	float m_fAngleBlendDuration;
	float m_fYawBase;
	SHM5GameCamAngles m_EndAngles;
	SHM5GameCamAngles m_StartAngles;
	SHM5GameCamAngleLimits m_AngleLimitsBlended;
	SHM5GameCamAngleLimits m_AngleLimitsStart;
	SHM5GameCamAngleLimits m_AngleLimitsEnd;
	bool m_bMinigameAngleLimits;
	float m_fMinigameAngleLimitYawBase;
	SHM5GameCamAngleLimits m_MinigameAngleLimits;
	TEntityRef<ZSpatialEntity> m_rMinigameLookat;
	bool m_bSetResetOnActivation;
	float m_fBlendFraction;
	float m_fBlendTime;
	float m_fBlendDuration;
	SHM5GameCamParams m_GameCamParamsStart;
	SHM5GameCamParams m_GameCamParamsEnd;
	SHM5GameCamParams m_GameCamParamsBlended;
	float m_userInputWeight;
	SVector3 m_cameraDirectionHint;
	float m_fCameraHintWeight;
	SHM5GameCamControls m_GameCamControls;
	bool m_bPOIActive;
	SCameraPOI m_POIParams;
	float4 m_vPOIPos;
	float m_fPOITime;
	float m_fStickAtExtremeBlendInTime;
	float m_fStickAtExtremeDelay;
	SSoftCollisionCache m_SoftCollisionCache;
	SSoftCollisionCache m_SoftCollisionCacheObstacle;
	float m_fObstacleCollideTime;
	SVector3 m_vCameraGlobalOffsetStart;
	SVector3 m_vCameraGlobalOffsetEnd;
	SVector3 m_vCameraGlobalOffsetBlended;
	SCameraUpdateEvent m_CameraUpdateEvent;
	SVector2 m_vRelativeTurn;
	bool m_bCutToEndParams;
	bool m_bFirstCutsequenceInterpolationUpdate;

	~ZHM53rdPersonCamera() override = default;
	void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera) override;
	void DeactivateCamera() override;
	void UpdateCamera(const SGameUpdateEvent& updateEvent) override;
	IFutureCameraState::SCameraState GetFutureCameraState() override;

	ZHM53rdPersonCamera() = default;
	ZHM53rdPersonCamera(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	void ActivateCamera();
	void UpdateCamera(SCameraUpdate& Ret, const SGameUpdateEvent& updateEvent, const bool bUpdateInput);
	void CalcYawPitchFromTargetPosition(float& fYaw, float& fPitch, const float4& vTarget) const;
	void SetCameraSide(bool bRightSide);
	bool GetCameraSide() const;
	float GetCameraSideMultiplier() const;
	void SetResetOnActivation(bool bSetResetOnActivation);
	void SetCameraDirection(const float4& vnLookTo);
	void HintCameraDirection(const float4& vLookTo);
	void SetUserInputWeight(float fWeight);
	void SetZoom(bool bZoom);
	bool CalculateCurrentSide() const;
	bool IsAimAssistActive() const;
	void SetPOIPos(const float4& vPOIPos);
	void SetPOIParams(const SCameraPOI& POIParams);
	void SetPOIActive(bool bActive);
	void Reset(const bool bResetPOI);
	const SHM5GameCamAngleLimits& GetCameraAngleLimits() const;
	float GetSideBlendFraction() const;
	ECameraOffset GetCameraOffset() const;
	void SetMinigameAngleLimits(bool bEnableLimits, float yawBase, float yawLimit, float pitchMin, float pitchMax);
	void SetMinigameLookatEntity(TEntityRef<ZSpatialEntity>& entity);
	float GetProfileBlendFraction() const;
	SVector2 GetRelativeTurn() const;
	void SetInitialCameraMatrix();
	void GetCameraUpdateEvent(SCameraUpdateEvent& CameraUpdateEvent) const;
	const SCameraUpdateEvent& GetCameraUpdateEvent() const;
	bool InterruptPOI() const;
	SMatrix CalculateCameraMatrix(float fYawAngle, float fPitchAngle, const SMatrix& mCameraGround, ECameraState eCameraState, ECameraOffset eCameraOffset, bool bRightSide) const;
	void SetCutToEndParams(bool bCutToEndParams);
	float GetCollisionHeight() const;
	void ResetInterpolateWhileMoving();
	bool EnableOTS() const;
	void CutSequenceChangedCamera();
	void CutSequenceStarted();
	void CalculateCamParameters();
	void UpdateCameraEvent();
	void UpdateInput(const SGameUpdateEvent& updateEvent, const SCameraUpdateEvent& CameraUpdateEvent);
	bool UpdateProfileBlend(float fDeltaTime, const SMatrix& mPrevCameraGround, const SCameraUpdateEvent& CameraUpdateEvent, const SCameraCollisionVariable& CameraDistance);
	void UpdatePOI(float fDeltaTime);
	void UpdateCameraPitch(const SGameUpdateEvent& updateEvent);
	SMatrix SphereCollision(float fDeltaTime, bool bBlendingProfile, float fYawAngle, float fPitchAngle, const SHM5GameCamParams& GameCamParams, const SMatrix& mCameraGround, SCameraCollisionVariable& CameraCollisionDistance, SSoftCollisionCache& SoftCollisionCache, SSoftCollisionCache& SoftCollisionCacheObstacle, float& fObstacleCollideTime, const SVector3& vCameraGlobalOffset, float fAimWeight, float& fPullInFraction, bool bEnableCollision, ICharacterController* pPlayerCollision, const float fNearZ, const float fAspect) const;
	SMatrix CalculateCollisionCamMatrix(float fRadius, float fStickLength, const float4& vFrom, float fYaw, float fPitch, float fPitchFraction) const;
	float4 CalcRotationPoint(const SHM5GameCamParams& GameCamParams, const SMatrix& mCameraGround, const SVector3& vGlobalOffset) const;
	float4 CalcCollisionPointFrom(const SHM5GameCamParams& GameCamParams, const SMatrix& mCameraGround) const;
	void AllignInitialCamAngleToHeroDir();
	float GetCameraOffsetTarget(ECameraOffset eCameraOffset) const;
	void SetupAlignYawPitch(ECameraState ePrevCamState, ECameraState eNextCamState, const SHM5GameCamTransition& Transition, const SCameraUpdateEvent& CameraUpdateEvent);
	SHM5GameCamParams CalculateGameCamParams(const SMatrix& mCam, const SMatrix& mGround, const float4& vRotationPoint, bool bCalculateRotationOffsets, float fFovY) const;
	bool CalculateSide(const SMatrix& mCam, const SMatrix& mGround) const;
	void CutToEndParams();
	void AnimateParams(SHM5GameCamParams& GameCamParams, float fYawAngle, float fYawBase, float fPitchAngle, float fOffset, float fZoom, float fPrecisionFraction, float fSide) const;
	float GetYawFraction(const SHM5GameCamParams& GameCamParams, float fYawAngle, float fYawBase) const;
};
