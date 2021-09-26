#pragma once

#include "IModule.h"
#include "ZMutex.h"
#include "ZString.h"
#include "ZVariantRef.h"

struct SComponentMapEntry;
class IComponentInterface;
class ZComponentCreateInfo;
struct STypeID;
template <class A, class B> class TMap;
template <class T> class TArray;

class __declspec(novtable) ZSimpleModuleBase : public IModule
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	class __declspec(novtable) ZComponentInfoBase
	{
		ZString m_sName;

		virtual ~ZComponentInfoBase() = default;
		virtual IComponentInterface* CreateComponent(ZComponentCreateInfo& componentCreateInfo) = 0;
	};

	ZString m_pszName;
	TMap<ZString, ZComponentInfoBase*>* m_pComponents;
	TMap<ZString, ZString>* m_pOptionMap;
	bool m_bIsInitializing;
	bool m_bIsShuttingDown;
	ZMutex m_initializationMutex;
	TArray<IComponentInterface*>* m_pSingletonOrder;

	~ZSimpleModuleBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	const ZString& Name() override;
	bool Initialize() override;
	void Shutdown() override;
	void Activate() override;
	void Deactivate() override;
	ZString GetOption(const ZString& pszName) override;
	bool GetOptionBool(const ZString& pszName) override;
	void SetOption(const ZString& pszName, const ZString& value) override;
	void BeginInitialization() override;
	void EndInitialization() override;
	void WaitForInitialization() override;
	IComponentInterface* CreateComponent(const ZString& pszName, ZComponentCreateInfo& Info) override;
	virtual void OnRegisterComponents() = 0;

	ZSimpleModuleBase() = default;
	ZSimpleModuleBase(const ZString& pszName);
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
};
