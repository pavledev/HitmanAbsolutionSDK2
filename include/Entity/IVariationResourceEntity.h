#pragma once

#include "IComponentInterface.h"

class ZEntityRef;
class ZEventNull;
class IVariationInstance;
template <class A, class B, class C, class D, class E> class ZEvent;

class __declspec(novtable) IVariationResourceEntity : public IComponentInterface
{
public:
	~IVariationResourceEntity() override = default;
	virtual bool IsReady() const = 0;
	virtual IVariationInstance* GetVariationInstance() = 0;
	virtual ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetVariationResourceStatusEvent() = 0;

	static void RegisterType();
	IVariationResourceEntity(const IVariationResourceEntity& __that);
	IVariationResourceEntity() = default;
	IVariationResourceEntity& operator=(const IVariationResourceEntity& __that);
};
