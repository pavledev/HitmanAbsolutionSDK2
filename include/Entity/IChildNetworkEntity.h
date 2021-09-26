#pragma once

#include "IComponentInterface.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"

class IVariationInstance;

class __declspec(novtable) IChildNetworkEntity : public IComponentInterface
{
public:
	~IChildNetworkEntity() override = default;
	virtual unsigned int CreateNetworkInstance(IVariationInstance* variationInstance) const = 0;
	virtual ZString GetDebugName() const = 0;
	virtual ZRuntimeResourceID GetNetworkRuntimeResourceID() const = 0;

	static void RegisterType();
	IChildNetworkEntity() = default;
};
