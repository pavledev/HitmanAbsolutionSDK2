#pragma once

#include "SOrderParamsBase.h"
#include "ECoverPosition.h"
#include "ZPositionTarget.h"

class ZHM5CoverPlane;

struct SShootFromCoverParams : SOrderParamsBase
{
	ZHM5CoverPlane* m_pTargetCover;
	ECoverPosition m_eCoverPosition;
	bool m_bBlindfire;
	bool m_bDisableShooting;

	~SShootFromCoverParams() override = default;

	SShootFromCoverParams() = default;
	SShootFromCoverParams(ZHM5CoverPlane* pCover, ECoverPosition eCoverPosition, bool bBlindfire, const ZPositionTarget& rAimTarget, bool bDisableShoot);
};
