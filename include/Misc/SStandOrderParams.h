#pragma once

#include "SOrderParamsBase.h"
#include "EBooleanOption.h"
#include "EStandRepositionStrategy.h"
#include "ZPositionTarget.h"

struct SStandOrderParams : SOrderParamsBase
{
	EBooleanOption m_bCrouch;
	EStandRepositionStrategy m_repositioningPolicy;

	~SStandOrderParams() override = default;

	SStandOrderParams(const SStandOrderParams& __that);
	SStandOrderParams() = default;
	SStandOrderParams& LookAt(const ZPositionTarget& target);
	SStandOrderParams& Face(const ZPositionTarget& target);
	SStandOrderParams& AimAndFace(const ZPositionTarget& target);
	SStandOrderParams& FaceAndLookAt(const ZPositionTarget& target);
	SStandOrderParams& PreventRepositioning();
	SStandOrderParams& Crouch(bool bCrouch);
	SStandOrderParams& FastStart(bool bFastStart);
	void ApplyDefaultValues();
};
