#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "ZEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"
#include "float4.h"

struct SGameUpdateEvent;
class ZCameraEntity;
class ZComponentCreateInfo;
class ZSpatialEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZFreeCameraControlEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEntityRef m_cameraEntity;
	bool m_bActive;
	bool m_bIsGameControlActive;
	ZCameraEntity* m_pControlledCameraEntity;
	float m_fMoveSpeed;
	float m_fTurnSpeed;
	float m_fMovementSpeedMultiplier;
	float m_fRotationSpeedMultiplier;
	float m_fMoveX;
	float m_fMoveY;
	float m_fMoveZ;
	bool m_bMoveInWorldSpace;
	bool m_bResetRoll;
	float m_fPitch;
	float m_fDeltaPitch;
	float m_fRoll;
	float m_fDeltaRoll;
	float m_fDeltaYaw;
	float m_fInitialFov;
	float m_fFov;
	float m_fDeltaFov;
	int m_nControllerId;

	static SComponentMapEntry s_componentMap[0];

	~ZFreeCameraControlEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZFreeCameraControlEntity() = default;
	static void RegisterType();
	ZFreeCameraControlEntity(const ZFreeCameraControlEntity& __that);
	ZFreeCameraControlEntity(ZComponentCreateInfo& Info);
	bool IsActive();
	void SetActive(bool bActive);
	bool IsGameControlActive();
	void SetCameraEntity(const TEntityRef<ZCameraEntity>& cameraEntity);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	ZString GenerateActionBindingString(int nControllerId);
	float CalcCurrentPitch(ZSpatialEntity* pSpatialEntity);
	void HandleFreeCamControls(float dt);
	void UpdateInputBindings();
	void UpdateMovementFromInput();
	void ResetMovement();
	void UpdateCamera(float dt);
	void UpdateFov(float dt);
	float UpdateRollFromDelta(float fDeltaRoll);
	float UpdatePitchFromDelta(float fDeltaPitch);
	float4 GetUpdatedCameraPosition(float fMoveX, float fMoveY, float fMoveZ, const SMatrix& mCurrentCameraToWorld);
	SMatrix GetUpdatedCameraRotation(float fDeltaRoll, float fDeltaPitch, float fDeltaYaw, const SMatrix& mCurrentCameraToWorld);
	void HandleLegacyFreeCamControls(float dt);
	void OnCameraEntityChanged();
	void OnActiveChanged();
	ZFreeCameraControlEntity& operator=(const ZFreeCameraControlEntity& __that);
};
