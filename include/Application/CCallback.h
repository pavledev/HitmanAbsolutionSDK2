#pragma once

#include "CCallbackBase.h"

template <class A, class B, int C>
class CCallback : public CCallbackBase
{
public:
	A* m_pObj;
	void (*m_Func)(B* param1);

	void Run(void* pvParam, bool __formal, unsigned long long __formal2) override;
	void Run(void* pvParam) override;
	int GetCallbackSizeBytes() override;
	virtual ~CCallback() = default;

	CCallback() = default;
	CCallback(A* pObj, void (*func)(B* param1));
	void Register(A* pObj, void (*func)(B* param1));
	void Unregister();
};
