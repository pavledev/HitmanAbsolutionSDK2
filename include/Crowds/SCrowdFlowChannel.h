#pragma once

#include "TArray.h"

struct SCrowdFlowChannel
{
	TArray<unsigned char> m_aFlowVectorIndex;
	TArray<unsigned short> m_aFlowCost;

	SCrowdFlowChannel(const SCrowdFlowChannel& __that);
	SCrowdFlowChannel() = default;
	~SCrowdFlowChannel() = default;
	SCrowdFlowChannel& operator=(const SCrowdFlowChannel& __that);
};
