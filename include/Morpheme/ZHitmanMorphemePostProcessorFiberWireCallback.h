#pragma once

struct sFiberWireInfos;

class __declspec(novtable) ZHitmanMorphemePostProcessorFiberWireCallback
{
public:
	virtual void FiberWireCallBack(sFiberWireInfos* param1) = 0;
	virtual ~ZHitmanMorphemePostProcessorFiberWireCallback() = default;

	static void RegisterType();
	ZHitmanMorphemePostProcessorFiberWireCallback() = default;
};
