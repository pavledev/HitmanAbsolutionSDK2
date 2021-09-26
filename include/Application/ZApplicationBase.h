#pragma once

#include "IApplication.h"
#include "THashMap.h"
#include "ERunMode.h"
#include "ZString.h"

template <class A, class B> class TDefaultHashMapPolicy;

class ZApplicationBase : public IApplication
{
public:
	THashMap<ZString, ZString, TDefaultHashMapPolicy<ZString, ZString>> m_debugContextMap;

	~ZApplicationBase() override = default;
	ERunMode GetRunMode() override;
	void SetDebugContextInfo(const ZString& sKey, const ZString& sValue) override;
	ZString GetDebugContextInfo(const ZString& sKey) override;
	bool IsNonInteractiveMode() override;
	void SendErrorMail(const ZString& sChannel, const ZString& sMsg) override;

	ZApplicationBase() = default;
};
