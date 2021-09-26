#pragma once

#include "ZConfigFloatBase.h"
#include "ZConfigCommand.h"

class ZConfigFloat : public ZConfigFloatBase
{
public:
	ZConfigCommand::ECLASSTYPE GetType() override;
	void Execute(const unsigned int argc, const char** argv) override;
	virtual ~ZConfigFloat() = default;

	ZConfigFloat() = default;
	ZConfigFloat(const char* pszName, const char* pszDescription, float DefaultValue);
	float GetVal() const;
	ZConfigFloat& operator=(const float& rhs);
	operator float() const;
};
