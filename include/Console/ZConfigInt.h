#pragma once

#include "ZConfigIntBase.h"
#include "ZConfigCommand.h"

class ZConfigInt : public ZConfigIntBase
{
public:
	ZConfigCommand::ECLASSTYPE GetType() override;
	void Execute(const unsigned int argc, const char** argv) override;
	virtual ~ZConfigInt() = default;

	ZConfigInt() = default;
	ZConfigInt(const char* pszName, const char* pszDescription, int DefaultValue);
	int GetVal() const;
	ZConfigInt& operator=(const int& rhs);
	operator int() const;
};
