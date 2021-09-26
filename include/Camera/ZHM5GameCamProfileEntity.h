#pragma once

#include "ZEntityImpl.h"
#include "ECameraState.h"
#include "ECameraControls.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZString;
struct SHM5GameCamAngleLimits;
struct SHM5GameCamAngles;
struct SHM5GameCamControls;
struct SHM5GameCamParams;
struct STypeID;

class ZHM5GameCamProfileEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bAlignYawPitch;
	float m_fPitchAngle;
	float m_fYawAngle;
	float m_fHeight;
	float m_fStickLength;
	float m_fRadius;
	float m_fRadiusLeft;
	float m_fRotationOffsetY;
	float m_fFOV;
	float m_fPrecisionShotFOV;
	float m_fBlendTime;
	float m_fProfileBlendTime;
	float m_fFacingOffsetX;
	ECameraState m_eState;
	TArray<ECameraState> m_aeStates;
	int m_nPriority;
	float m_fPitchMaxOffset;
	float m_fPitchMinOffset;
	float m_fYawOffset;
	float m_fYawBase;
	bool m_bEnableSmootingAtLimits;
	bool m_bYawBlendOutRadius;
	bool m_bYawAnimation;
	float m_fRotationOffsetYYaw;
	float m_fStickLengthYaw;
	float m_fYawAnimationRange;
	bool m_bPitchAnimation;
	float m_fHeightPitch;
	float m_fPitchAngle0;
	float m_fPitchAngle1;
	bool m_bEnablePitchLevelOut;
	bool m_bEnableSmoothing;
	bool m_bEnableAimAssist;
	ECameraControls m_eCameraControls;
	bool m_bUseCollisionHeight;
	float m_fCollisionHeight;
	bool m_bAimPushOut;
	bool m_bEnableSoftCollision;
	float m_fTossHeight;
	bool m_bActivated;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GameCamProfileEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZHM5GameCamProfileEntity() = default;
	static void RegisterType();
	ZHM5GameCamProfileEntity(ZComponentCreateInfo& pInfo);
	void GetGameCamParams(SHM5GameCamParams& Ret) const;
	float GetBlendTime() const;
	float GetProfileBlendtime() const;
	ECameraState GetCameraState() const;
	const TArray<ECameraState>& GetCameraStates() const;
	bool AlignYawPitch() const;
	ECameraControls GetCameraControls() const;
	void GetGameCamAlignAngles(SHM5GameCamAngles& Ret) const;
	void GetGameCamAngleLimits(SHM5GameCamAngleLimits& Ret) const;
	void GetGameCamControls(SHM5GameCamControls& Ret) const;
	int GetPriority() const;
	void OnBlendIn();
	void OnBlendOut();
};
