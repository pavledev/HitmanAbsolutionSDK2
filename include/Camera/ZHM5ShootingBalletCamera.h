#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "ESBView.h"
#include "SSBCamTargetProfile.h"
#include "SCameraCollisionVariable.h"
#include "SSoftCollisionCache.h"
#include "ECameraMode.h"
#include "ESBCamProfileBone.h"
#include "IFutureCameraState.h"
#include "SMatrix.h"
#include "SSBCamHitmanProfile.h"
#include "TEntityRef.h"
#include "ZMapPoly.h"
#include "float4.h"

class ZHM5MainCamera;
class ZHM5SBCamProfiles;
class ZHitman5;
struct SGameUpdateEvent;
struct SHM5SBShared;
struct SSBAnim;

class ZHM5ShootingBalletCamera : public ZHM5CameraBaseFunc
{
public:
	struct SSBCamUpdate
	{
		float4 m_vCollisionFrom;
		float4 m_vCollisionTo;
		float4 m_vCamDir;
		float4 m_vLookAtPoint;
		bool m_bLookAtPoint;
		bool m_bUpdateCam;
		float m_fRoll;
		float m_fFovY;

		SSBCamUpdate() = default;
	};

	class AutoRotationOnZoom
	{
	public:
		float rotation;
		bool enabled;
		float yawAtPreviousStep;

		AutoRotationOnZoom() = default;
		void Reset(float rotation);
		void Disable();
		void DisableIfYawHasntChanged(float fYaw);
	};

	ESBView m_eCurrentView;
	SHM5SBShared* m_pSBShared;
	ZMapPoly m_MapPoly;
	ZMapPoly m_MapPolyZoom;
	unsigned int m_nLookAtTag;
	float4 m_vPointOfInterest;
	float4 m_vCamPos;
	float m_fUserPitch;
	float m_fCameraYaw;
	float m_fYawBuffer;
	float m_fPitchBuffer;
	float m_fCameraPitch;
	bool m_bAnimIsTargetView;
	SMatrix m_mCamEnd;
	unsigned int m_nZoomTag;
	unsigned int m_nZoomBoneId;
	bool m_bDetached;
	bool m_bAreaClear;
	SSBCamHitmanProfile m_StartProfile;
	float m_fYawToLastTag;
	float m_fPitchToLastTag;
	float m_fLastTagLength;
	float4 m_vLookAtPos;
	float m_fLookAtTagStartFraction;
	bool m_bInterpolateLookAtPos;
	const SSBAnim* m_pCurrentAnim;
	unsigned int m_nAnimationTag;
	int m_nCamAnimBone;
	float m_fImpactViewZoomTime;
	float m_fImpactViewFraction;
	float m_fZoomBoneTime;
	float4 m_vZoomStartCam;
	float m_fZoomDeltaYaw;
	float m_fZoomDeltaPitch;
	float m_fZoomFovStart;
	bool m_bEndStartInterpolation;
	bool m_bOverwriteListenerPos;
	bool m_bPitchFlip;
	float m_fImpactViewRollAngle;
	float m_fImpactViewDist;
	float m_fImpactViewSpeedYaw;
	float m_fImpactViewSpeedPitch;
	SSBCamHitmanProfile m_HitmanTargetProfile;
	SSBCamTargetProfile m_TargetProfile;
	unsigned int m_nTargetProfileIndex;
	SSBCamHitmanProfile m_HitmanViewProfile;
	TEntityRef<ZHM5SBCamProfiles> m_rSBCamProfiles;
	bool m_bZoomComplete;
	bool m_bBehindNPC;
	SCameraCollisionVariable m_CameraCollision;
	SSoftCollisionCache m_SoftCollisionCache;
	SSoftCollisionCache m_SoftCollisionObstacleCache;
	float m_fStickLengthPullIn;
	float m_fObstacleCollideTime;
	AutoRotationOnZoom m_autoRotate;

	~ZHM5ShootingBalletCamera() override = default;
	void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera) override;
	void DeactivateCamera() override;
	void UpdateCamera(const SGameUpdateEvent& updateEvent) override;
	IFutureCameraState::SCameraState GetFutureCameraState() override;

	ZHM5ShootingBalletCamera() = default;
	ZHM5ShootingBalletCamera(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	void SetSBShared(SHM5SBShared* pSBShared);
	bool IsZoomComplete() const;
	bool IsImpactView() const;
	float GetImpactViewTime() const;
	float GetImpactViewFraction() const;
	bool CreateZoomView(unsigned int nTag, bool bBehindNPC);
	bool GetBehindNPC() const;
	bool IsAreaClear(const float4& vPos) const;
	bool IsAreaClear() const;
	void AnimationChanged(const SSBAnim* pCurrentAnim, const SMatrix& mvTo);
	ESBView GetView() const;
	bool AnimIsTargetView() const;
	bool Transition(ESBView eView, const unsigned int nTag);
	void DoTransition(ESBView eNextView);
	void SetCamMatrix(const float4& vPos, const float4& vDir, float fRollAngle, const float4& vListenerPos);
	void UpdateView(ESBView eView);
	bool UpdateImpactView(bool bUpdateInput, float4& vCamDir, float4& vCamPos);
	void UpdateShoulderView(SSBCamUpdate& SBCamUpdate);
	void UpdateAnimationView(SSBCamUpdate& SBCamUpdate);
	void SelectTargetProfile();
	bool IsViewBlocked(const float4& vCamPos, unsigned int nTag);
	void ResetLookAtPos(const unsigned int nTag);
	void UpdateLookAtPos(bool bForceInterpolation);
	float4 GetLookAtPos() const;
	bool FindDeltaRotation(float* afImpactFractions, float4* avFrom, float4* avTo, unsigned int* anIndex, float& fDeltaRotion, const float4& vRotationPlaneNormal);
	bool IsTagInView(unsigned int nTag) const;
	float4 GetImpactLookAtPos(unsigned int nTag, float fBoneZoomFraction, unsigned int nBoneId) const;
	SMatrix GetCollisionCorrectedCam() const;
	float4 GetCamZoomPos(float fYawAngle, float fPitchAngle, float fOffset, const float4& vPointOfInterest) const;
	bool UpdateSpherePos(float fDeltaTime, float fMaxVelocity, float4& vSpherePos, const float4& vDestination);
	void CalculateDeltaYawPitch(float& fYaw, float& fPitch, const float4& vVec1, const float4& vVec2) const;
	void CalculateDeltaYawPitch(float& fYaw, float& fPitch, const float4& vCenter, const float4& vP1, const float4& vP2) const;
	unsigned int GetGlobalBone(const SSBAnim* pAnim, ESBCamProfileBone eCamProfileBone) const;
};
