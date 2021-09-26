#pragma once

#include "ZGameTime.h"

class ZFiber
{
public:
	enum EFiberState
	{
		FS_INITIALIZED = 0,
		FS_RUNNING = 1,
		FS_TERMINATING = 2,
		FS_COMPLETED = 3
	};

	enum EFiberType
	{
		FT_NORMAL = 0,
		FT_BIG = 1
	};

	struct SFiberState
	{
		int execMain[16];
		ZFiber* pFiber;

		SFiberState() = default;
	};

	int m_ExecFunction[16];
	ZGameTime m_sleepUntil;
	EFiberState m_nFiberState;
	void* m_pData;
	void (*m_pFunction)(void* param1);
	void* m_pStackData;
	unsigned int m_nStackStart;
	unsigned int m_nStackSize;
	unsigned int m_nStackAllocated;

	static SFiberState s_pPrimaryFiber;
	static SFiberState s_pSecondaryFiber;

	virtual ~ZFiber() = default;

	ZFiber() = default;
	ZFiber(void (*pFunction)(void* param1), void* pData);
	bool IsSleeping();
	void Wake();
	bool Resume(EFiberType inType);
	bool Terminate();
	static void Sleep(float seconds);
	static bool IsTerminating();
	void CallInternal(EFiberType inType);
	static SFiberState* GetCurrentState();
};
