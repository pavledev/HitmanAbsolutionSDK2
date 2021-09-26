#pragma once

#include "ZConfigCommand.h"

class ZConfigIntBase : public ZConfigCommand
{
public:
	int m_Value;

	ZConfigIntBase() = default;
	~ZConfigIntBase() = default;
	ZConfigIntBase(const char* pszName, int DefaultValue);
};
