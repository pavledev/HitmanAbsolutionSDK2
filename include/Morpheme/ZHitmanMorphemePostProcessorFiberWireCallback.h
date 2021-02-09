#pragma once

#include "sFiberWireInfos.h"

class ZHitmanMorphemePostProcessorFiberWireCallback
{
public:
	virtual void FiberWireCallBack(sFiberWireInfos*);
	virtual ~ZHitmanMorphemePostProcessorFiberWireCallback();
};
