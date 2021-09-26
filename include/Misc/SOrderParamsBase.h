#pragma once

#include "EActorAnimationOrder.h"
#include "ZPositionTarget.h"

struct SOrderParamsBase
{
	EActorAnimationOrder m_type;
	ZPositionTarget m_aimTarget;
	ZPositionTarget m_lookTarget;
	ZPositionTarget m_facingTarget;
	bool m_bFastStart;

	virtual ~SOrderParamsBase() = default;

	SOrderParamsBase() = default;
	SOrderParamsBase(const SOrderParamsBase& __that);
	SOrderParamsBase(EActorAnimationOrder type);
	void SetAimTarget(const ZPositionTarget& aimTarget, bool bUpdateFacing);
	void ClearAimTarget();
	bool IsAimTargetSet() const;
	SOrderParamsBase& operator=(const SOrderParamsBase& __that);
};
