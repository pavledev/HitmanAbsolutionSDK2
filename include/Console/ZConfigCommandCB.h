#pragma once

#include "ZConfigCommand.h"

class ZConfigCommandCB : public ZConfigCommand
{
public:
	void* m_pUserData;
	void (*m_pCallBack)(ZString string, const unsigned int param2, const char** param3, void* param4);

	void Execute(const unsigned int argc, const char** argv) override;
	virtual ~ZConfigCommandCB() = default;

	ZConfigCommandCB() = default;
	ZConfigCommandCB(const char* pszName, const char* pszDescription, void (*pCallBack)(ZString string, const unsigned int param2, const char** param3, void* param4), void* pUserData);
};
