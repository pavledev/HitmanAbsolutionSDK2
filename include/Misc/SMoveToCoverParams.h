#pragma once

#include "SOrderParamsBase.h"
#include "EMoveSpeed.h"
#include "ZPF5Location.h"
#include "TRefCountPtr.h"
#include "ZPositionTarget.h"

class ZHM5CoverPlane;
class ZPF5Path;

struct SMoveToCoverParams : SOrderParamsBase
{
	EMoveSpeed m_moveSpeed;
	ZPF5Location m_endLocation;
	ZPF5Location m_jumpLocation;
	TRefCountPtr<ZPF5Path> m_path;
	bool m_bJumpOver;
	ZHM5CoverPlane* m_pTargetCover;

	~SMoveToCoverParams() override = default;

	SMoveToCoverParams() = default;
	SMoveToCoverParams(const SMoveToCoverParams& __that);
	SMoveToCoverParams(const ZPF5Location& endLocation, const ZPF5Location& jumpLocation, const TRefCountPtr<ZPF5Path>& path, ZHM5CoverPlane* pCover);
	SMoveToCoverParams& Speed(EMoveSpeed speed);
	SMoveToCoverParams& JumpOverCover(bool jumpOver);
	SMoveToCoverParams& Aim(const ZPositionTarget& rTarget);
	SMoveToCoverParams& Face(const ZPositionTarget& rTarget);
};
