#pragma once

struct sLedgeHangInfos;

class __declspec(novtable) ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
	virtual void LedgeHangCallBack(sLedgeHangInfos* param1) = 0;
	virtual ~ZHitmanMorphemePostProcessorLedgeHangCallback() = default;

	static void RegisterType();
	ZHitmanMorphemePostProcessorLedgeHangCallback() = default;
};
