#pragma once

#include "IComponentInterface.h"

class ZEntityRef;
struct float4;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) ITriggerVolume : public IComponentInterface
{
public:
	~ITriggerVolume() override = default;
	virtual bool ContainsPoint(const float4& param1) const = 0;
	virtual void GetAxisAlignedBox(float4& param1, float4& param2) = 0;
	virtual void RegisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& param1) = 0;
	virtual void UnregisterForChanges(const ZDelegate<void __cdecl(ZEntityRef const&)>& param1) = 0;

	static void RegisterType();
	ITriggerVolume(const ITriggerVolume& __that);
	ITriggerVolume() = default;
	ITriggerVolume& operator=(const ITriggerVolume& __that);
};
