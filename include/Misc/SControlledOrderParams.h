#pragma once

#include "SOrderParamsBase.h"
#include "SActorHSState.h"
#include "ZString.h"

struct SControlledOrderParams : SOrderParamsBase
{
	SActorHSState::EHSEnterAnimation m_eEnterAnimation;
	ZString m_sStateMachineName;
	ZString m_sAnimName;

	~SControlledOrderParams() override = default;

	SControlledOrderParams() = default;
};
