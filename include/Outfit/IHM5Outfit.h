#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "STokenID.h"

class __declspec(novtable) IHM5Outfit : public IComponentInterface
{
public:
	~IHM5Outfit() override = default;
	virtual bool IsAllowedIn(const ZEntityRef& entityRef) const = 0;
	virtual int GetZoneMask() const = 0;
	virtual bool SupportsActor(const STokenID& tokenID) = 0;

	static void RegisterType();
	IHM5Outfit() = default;
};
