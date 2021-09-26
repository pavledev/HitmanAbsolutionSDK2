#pragma once

#include "ZDelegate.h"
#include "ZString.h"

class ZThread
{
public:
	ZDelegate<unsigned int __cdecl(void*)> m_function;
	int m_handle;
	ZString m_sName;
	unsigned int m_nExitCode;
	int m_nStackSize;
	unsigned char m_nJoinState;

	ZThread() = default;
	ZThread(const ZDelegate<unsigned int __cdecl(void*)>& function, const ZString& sName, bool bJoinable);
	ZThread(bool bJoinable);
	~ZThread() = default;
	void SetFunction(const ZDelegate<unsigned int __cdecl(void*)>& function, const ZString& sName);
	void SetJoinable(bool bJoinable);
	void SetStackSize(const int nSizeInBytes);
	void Start(void* pParam);
	void Join();
	static int GetCurrentThreadHandle();
	static int GetCurrentThreadID();
	//static void Yield();
	static void Sleep(unsigned int nMsecs);
	bool IsRunning() const;
	static void Terminate(unsigned int nExitCode);
	static void Suspend(int nThreadHandle);
	static void Resume(int nThreadHandle);
	static void SetCPU(int nThreadHandle, unsigned int nCPU);
	static unsigned int GetCPUCount();
	bool IsCurrent() const;
	unsigned int GetExitCode() const;
	static unsigned int AllocateDataSlot();
	static void FreeDataSlot(unsigned int nSlot);
	static void SetData(unsigned int nSlot, void* pData);
	static void* GetData(unsigned int nSlot);
	int GetThreadHandle() const;
	ZThread& operator=(const ZThread& __that);
};
