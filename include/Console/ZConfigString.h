#pragma once

#include "ZConfigStringBase.h"

class ZConfigString : public ZConfigStringBase
{
public:
	ZConfigCommand::ECLASSTYPE GetType() override;
	void Execute(const unsigned int argc, const char** argv) override;
	virtual ~ZConfigString() = default;

	ZConfigString() = default;
	ZConfigString(const char* pszName, const char* pszDescription, const char* DefaultValue);
	const char* GetVal() const;
};
