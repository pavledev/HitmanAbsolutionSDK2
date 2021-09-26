#pragma once

#include "IComponentInterface.h"
#include "ZString.h"

class ZComponentCreateInfo;

class __declspec(novtable) IModule : public IComponentInterface
{
public:
	~IModule() override = default;
	virtual const ZString& Name() = 0;
	virtual bool Initialize() = 0;
	virtual void Shutdown() = 0;
	virtual void Activate() = 0;
	virtual void Deactivate() = 0;
	virtual ZString GetOption(const ZString& string) = 0;
	virtual bool GetOptionBool(const ZString& string) = 0;
	virtual void SetOption(const ZString& string, const ZString& string2) = 0;
	virtual void BeginInitialization() = 0;
	virtual void EndInitialization() = 0;
	virtual void WaitForInitialization() = 0;
	virtual IComponentInterface* CreateComponent(const ZString& string, ZComponentCreateInfo& componentCreateInfo) = 0;

	IModule() = default;
};
