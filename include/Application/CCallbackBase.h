#pragma once

class __declspec(novtable) CCallbackBase
{
public:
	enum
	{
		k_ECallbackFlagsRegistered = 1,
		k_ECallbackFlagsGameServer = 2
	};

	unsigned char m_nCallbackFlags;
	int m_iCallback;

	virtual void Run(void* param1, bool param2, unsigned long long param3) = 0;
	virtual void Run(void* param1) = 0;
	virtual int GetCallbackSizeBytes() = 0;
	virtual ~CCallbackBase() = default;

	CCallbackBase() = default;
};
