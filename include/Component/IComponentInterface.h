#pragma once

#include "ZVariantRef.h"

struct STypeID;

class __declspec(novtable) IComponentInterface
{
public:
	virtual ~IComponentInterface() = default;
	virtual ZVariantRef GetVariantRef() const = 0;
	virtual int AddRef() = 0;
	virtual int Release() = 0;
	virtual void* QueryInterface(STypeID* typeID) = 0;

	static void RegisterType();
	IComponentInterface(const IComponentInterface& __that);
	IComponentInterface() = default;
	IComponentInterface& operator=(const IComponentInterface& __that);
};
