#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SHM5GameCamParams.h"
#include "ZMapPoly.h"
#include "ECameraControls.h"
#include "ECameraState.h"
#include "SComponentMapEntry.h"
#include "SHM5GameCamAngleLimits.h"
#include "SHM5GameCamControls.h"
#include "SHM5GameCamTransition.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZHitman5;
class ZComponentCreateInfo;
class ZHM5GameCamControlsEntity;
class ZHM5GameCamProfileEntity;
class ZHM5GameCamTransition;
struct SHM5GameCamAngles;
struct STypeID;

class ZHM5CameraProfileBlendDatabase : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EBlendNodeStatus
	{
		eBlendNodeStatus_Inactive = 0,
		eBlendNodeStatus_BlendIn = 1,
		eBlendNodeStatus_BlendOut = 2
	};

	struct SBlendNode
	{
		EBlendNodeStatus m_eStatus;
		float m_fBlendTime;
		float m_fBlendDuration;
		TEntityRef<ZHM5GameCamProfileEntity> m_rGameGamProfile;

		float GetBlendFraction() const;
		SBlendNode(const SBlendNode& __that);
		SBlendNode() = default;
		~SBlendNode() = default;
		SBlendNode& operator=(const SBlendNode& __that);
	};

	TArray<TEntityRef<ZHM5GameCamProfileEntity>> m_GameCamProfiles;
	TArray<TEntityRef<ZHM5GameCamTransition>> m_GameCamTransitions;
	TArray<TEntityRef<ZHM5GameCamControlsEntity>> m_GameCamControls;
	bool m_abUpdateParams[49];
	SHM5GameCamParams m_aBlendedGameCamParams[49];
	SBlendNode m_aBlendNodes[49][4];
	ZMapPoly m_BlendMap;
	TEntityRef<ZHitman5> m_rHitman;

	static SComponentMapEntry s_componentMap[0];
	static const unsigned int NUM_BLEND_NODES;

	~ZHM5CameraProfileBlendDatabase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZHM5CameraProfileBlendDatabase() = default;
	static void RegisterType();
	ZHM5CameraProfileBlendDatabase(ZComponentCreateInfo& Info);
	SHM5GameCamParams GetGameCamParams(ECameraState eCameraState);
	SHM5GameCamAngleLimits GetGameCamAngleLimits(ECameraState eCameraState) const;
	SHM5GameCamControls GetCameCamControls(ECameraState eCameraState) const;
	SHM5GameCamTransition GetGameCamTransition(ECameraState eCameraStateCurrent, ECameraState eCameraStateNext) const;
	void SetTransitionWhileMoving(bool bTransitionWhileMoving, ECameraState eFrom, ECameraState eTo);
	float GetTransitionTime(ECameraState eCameraState) const;
	bool AlignYawPitch(ECameraState eCameraState, SHM5GameCamAngles& Ret) const;
	void UpdateBlends(float fDeltaTime, bool bForceEndBlends);
	void InsertBlend(const TEntityRef<ZHM5GameCamProfileEntity>& rGameCamProfile, ECameraState eCamState);
	void InsertBlend(const TEntityRef<ZHM5GameCamProfileEntity>& rGameCamProfile);
	void RemoveBlend(const TEntityRef<ZHM5GameCamProfileEntity>& rGameCamProfile, ECameraState eCamState, const bool bInstant);
	void RemoveBlend(const TEntityRef<ZHM5GameCamProfileEntity>& rGameCamProfile, const bool bInstant);
	void Reset();
	void RegisterHitman(const TEntityRef<ZHitman5>& rHitman);
	void UpdateGameCamParams(ECameraState eCameraState);
	void UpdateLocomotion();
	void UpdateCrowdLocomotion();
	void UpdateFiberWire();
	void UpdateOTS();
	void UpdateScope();
	void UpdateUnAimedShooting();
	void GetControls(SHM5GameCamParams& Params, ECameraControls eCameraControls) const;
};
