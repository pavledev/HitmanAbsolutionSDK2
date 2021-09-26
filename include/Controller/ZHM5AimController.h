#pragma once

#include "ZHM5BaseController.h"
#include "ZMapPoly.h"
#include "eItemType.h"
#include "EBaseMovementType.h"
#include "EHM5BaseControllerType.h"
#include "EHM5ResetReason.h"
#include "SHM5AimInfo.h"
#include "SHM5LookAtInfo.h"
#include "SVector2.h"
#include "TEntityRef.h"

class ZHitman5;
class ZMorphemeNetworkInstance;
struct SHM5ControllerUpdateEvent;

class ZHM5AimController : public ZHM5BaseController
{
public:
	TEntityRef<ZHitman5> m_pHitman;
	SHM5AimInfo m_AimInfo;
	SHM5LookAtInfo m_LookAtInfo;
	ZMapPoly m_MapPoly;
	ZMapPoly m_MapPolyLag;
	eItemType m_aeItems[2];
	EBaseMovementType m_eMovementType;
	float m_fGripPoseBlendTime;
	float m_fPreviousMovementAimWeight;
	float m_fPreviousMovementHandLayerWeight;
	float m_fPreviousMovementArmLayerWeight;
	float m_fPoseBlendTime;
	float m_afGripBlendInTime[2];
	float m_afItemChangedTime[2];
	float m_fPreviousMmovementLookAtWeight;
	float m_fLookAtPoseTime;
	SVector2 m_vAimLag;
	SVector2 m_vHeadLead;
	float m_LeadTimer;
	float m_fFireTimer;

	~ZHM5AimController() override = default;
	void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent) override;
	void Reset(EHM5ResetReason eResetReason) override;

	ZHM5AimController() = default;
	ZHM5AimController(const TEntityRef<ZHitman5>& pHitman, EHM5BaseControllerType eType);
	const SHM5AimInfo& GetAimInfo() const;
	const SHM5LookAtInfo& GetLookAtInfo() const;
	void UpdateAim(SHM5AimInfo& AimInfo, const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	void UpdateLayers(float fHandLayerWeight, float fArmLayerWeight, bool bSwapLayerWeights, const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent, ZMorphemeNetworkInstance* pNetwork, bool bForceGrip);
};
