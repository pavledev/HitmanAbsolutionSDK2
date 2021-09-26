#pragma once

#include "ZHM5LocomotionState.h"
#include "ZHM5LocomotionTurnAnimDatabase.h"

class ZHM5LocomotionTurnState : public ZHM5LocomotionState
{
public:
	bool m_bExitTurn;
	float m_fRotationScale;
	float m_fFraction;
	float m_fTime;
	ZHM5LocomotionTurnAnimDatabase m_TurnAnimationDatabase;
	const STurnAnim* m_pTurnAnim;

	~ZHM5LocomotionTurnState() override = default;
	void Activate() override;
	void Update(float fDeltaTime) override;
	void Deactivate() override;

	ZHM5LocomotionTurnState() = default;
	void FindAnimations(unsigned int nTurnNode);
	const STurnAnim* SelectTurnAnimation(float fRotation, ETurnAnimType eTurnAnimType, bool bRightLeg, bool bHalfStep);
	bool OppositeTurnPriority() const;
};
