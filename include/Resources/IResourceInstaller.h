#pragma once

#include "IComponentInterface.h"

class ZResourcePending;
class ZRuntimeResourceID;

class __declspec(novtable) IResourceInstaller : public IComponentInterface
{
public:
	~IResourceInstaller() override = default;
	virtual void Release(const ZRuntimeResourceID& runtimeResourceID, void* param2, unsigned int param3) = 0;
	virtual void* Allocate(unsigned int param1) const = 0;
	virtual bool Install(ZResourcePending& resourcePending) = 0;
	virtual bool IsStreamInstaller() const = 0;
	virtual bool IsIndirectionInstaller() const = 0;
	virtual bool SupportsAllocate() const = 0;
	virtual void OnOrphanedResource(const ZRuntimeResourceID& runtimeResourceID, void* param2, unsigned int param3) = 0;

	IResourceInstaller() = default;
};
