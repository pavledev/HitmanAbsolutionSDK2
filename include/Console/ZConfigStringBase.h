#pragma once

#include "ZConfigCommand.h"

class ZConfigStringBase : public ZConfigCommand
{
public:
	char m_szValue[256];

	ZConfigStringBase() = default;
	~ZConfigStringBase() = default;
	ZConfigStringBase(const char* pszName, const char* DefaultValue);
};
