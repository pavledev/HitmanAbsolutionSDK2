#pragma once

#include "sLedgeHangInfos.h"

class ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
	virtual void LedgeHangCallBack(sLedgeHangInfos*);
	virtual ~ZHitmanMorphemePostProcessorLedgeHangCallback();
};
