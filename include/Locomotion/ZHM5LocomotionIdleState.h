#pragma once

#include "ZHM5LocomotionState.h"

class ZHM5LocomotionIdleState : public ZHM5LocomotionState
{
public:
	struct SIdleAnimType
	{
		bool m_bSupportsRifle;
		bool m_bSupportsDual;
		bool m_bSupportsUnarmed;

		SIdleAnimType() = default;
	};

	bool m_bPlayIdleAnims;
	float m_fIdleTime;
	int m_nIdleAnimIndex;
	SIdleAnimType m_aIdleAnimInfo[7];

	~ZHM5LocomotionIdleState() override = default;
	void Activate() override;
	void Update(float fDeltaTime) override;

	ZHM5LocomotionIdleState() = default;
	void SetPlayIdleAnims(bool bPlayIdleAnims);
	void UpdateIdleAnimIndex();
	void InitIdleAnimInfo();
};
