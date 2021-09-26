#pragma once

#include "SOrderParamsBase.h"
#include "ECoverPosition.h"

class ZHM5CoverPlane;

struct SPeekFromCoverParams : SOrderParamsBase
{
	ZHM5CoverPlane* m_pTargetCover;
	ECoverPosition m_eCoverPosition;

	~SPeekFromCoverParams() override = default;

	SPeekFromCoverParams() = default;
};
