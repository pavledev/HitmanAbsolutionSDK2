#pragma once

#include "ZWin32ApplicationStub.h"
#include "ZMutex.h"

class IIniFile;

class __declspec(novtable) ZWin32ApplicationBase : public ZWin32ApplicationStub
{
public:
	ZMutex m_exceptionMutex;

	~ZWin32ApplicationBase() override = default;
	bool IsNonInteractiveMode() override;
	void GetErrorMailSenderName(char* defFromBuf) override;
	void AddApplicationSpecificOptions(IIniFile* pIniFile) override;
	virtual int Main(int param1, char** param2) = 0;

	ZWin32ApplicationBase() = default;
	ZWin32ApplicationBase(int argc, char** argv);
	int Run();
	int RunInternal();
};
