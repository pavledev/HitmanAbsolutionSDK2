#pragma once

#include "EComponentManagerState.h"
#include "ZModuleTable.h"
#include "ZMutex.h"

class IApplication;
class IComponentInterface;
class IModule;
class ZComponentCreateInfo;
class ZString;
struct STypeID;
template <class A, class B> class TMap;

class ZComponentManager
{
public:
	IApplication* m_pApplication;
	EComponentManagerState m_state;
	ZModuleTable m_modules;
	TMap<ZString, IComponentInterface*>* m_pSingletons;
	ZMutex m_ModuleLoadMutex;

	ZComponentManager() = default;
	~ZComponentManager() = default;
	void SetApplication(IApplication* application);
	IApplication* GetApplication();
	void Initialize();
	void Shutdown();
	void Activate();
	void Deactivate();
	bool IsRunning();
	void RegisterModule(IModule* pModule);
	IModule* GetModule(const ZString& sName);
	bool PrepareCreateComponent(const ZString& pszFullName);
	void* CreateComponent(const ZString& pszFullName, STypeID* requestedInterface, ZComponentCreateInfo& Info);
	IModule* FindModuleByComponentName(const ZString& pszFullName);
	IModule* GetModuleInternal(const ZString& pszName, int nModuleNameLength);
};
