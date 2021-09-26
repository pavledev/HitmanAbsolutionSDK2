#pragma once

#include "IComponentInterface.h"

class IBaseConstraint;

class __declspec(novtable) IFixedConstraint : public IComponentInterface
{
public:
	~IFixedConstraint() override = default;
	virtual IBaseConstraint* GetBaseConstraint() const = 0;

	static void RegisterType();
	IFixedConstraint() = default;
};
