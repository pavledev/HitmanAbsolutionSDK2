#pragma once

#include "SEffectParameters.h"
#include "ZResourcePtr.h"

class SEffectResourceLoader
{
public:
	SEffectParameters* m_pEffectParameters;
	unsigned int m_LastRebindFrame;
	unsigned int m_LastChangeFrame;
	ZResourcePtr m_pEffectResourcePtr;

	virtual ~SEffectResourceLoader() = default;

	void Init(SEffectParameters* pEffectParameters, ZResourcePtr resPtr);
	void RebindEffectResource();
	void EffectChanged(const ZRuntimeResourceID& args);
	SEffectResourceLoader() = default;
};
