#pragma once

#include "ZConfigCommand.h"

class ZConfigFloatBase : public ZConfigCommand
{
public:
	float m_Value;

	ZConfigFloatBase() = default;
	~ZConfigFloatBase() = default;
	ZConfigFloatBase(const char* pszName, float DefaultValue);
};
