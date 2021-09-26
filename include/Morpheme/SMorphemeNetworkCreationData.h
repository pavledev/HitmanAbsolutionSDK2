#pragma once

#include "ZString.h"
#include "MR.h"
#include "IVariationInstance.h"

struct SMorphemeNetworkCreationData
{
	ZString sDebugName;
	MR::NetworkDef* pNetworkDef;
	IVariationInstance* pVariationInstance;
	ZEntityRef pOwnerEntity;

	SMorphemeNetworkCreationData() = default;
	~SMorphemeNetworkCreationData() = default;
};
