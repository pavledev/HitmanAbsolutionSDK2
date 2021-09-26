#pragma once

#include "ZHM5LocomotionState.h"
#include "ETurnToMoveDataState.h"
#include "STurnToMoveData.h"
#include "ZString.h"

class ZHM5LocomotionTurnToMoveState : public ZHM5LocomotionState
{
public:
	ETurnToMoveDataState m_eSelectedState;
	float m_fAnimFraction;
	float m_fRotationScale;
	STurnToMoveData m_TurnToMoveData;

	~ZHM5LocomotionTurnToMoveState() override = default;
	void Activate() override;
	void Update(float fDeltaTime) override;
	virtual void FindTurnOnSpotData(const ZString& sRootNode);

	ZHM5LocomotionTurnToMoveState() = default;
	float GetDeltaRotation(float fFractionFrom, float fFractionTo, unsigned int nAnimNode) const;
};
