#pragma once

#include "ZApplicationBase.h"
#include "TScopedPointer.h"
#include "ZString.h"

class IIniFile;
class IModule;
class ITraceListener;
class ZComponentManager;
class ZTraceListenerWin32;
template <class A, class B> class TMap;

class ZWin32ApplicationStub : public ZApplicationBase
{
public:
	ZComponentManager* m_pComponentManager;
	IIniFile* m_pIniFile;
	TMap<ZString, ZString>* m_pOptions;
	ITraceListener* m_pTraceListenerZDebug2;
	bool m_bCleanupCOM;
	bool m_bApplicationIniWasLoaded;
	ZTraceListenerWin32* m_pTraceListenerWin32;
	TScopedPointer<TMap<ZString, ZString>> m_pCommandLineOverrides;
	int m_nArgC;
	char** m_apszArgV;
	void* m_pExceptionHandler;
	bool m_bInitialized;

	~ZWin32ApplicationStub() override = default;
	void OnBeforeInitialize() override;
	void OnAfterInitialize() override;
	void OnBeforeShutdown() override;
	void OnAfterShutdown() override;
	void OnBeforeModuleInitialize(IModule* pModule) override;
	void OnAfterModuleInitialize(IModule* pModule) override;
	void OnBeforeModuleShutdown(IModule* pModule) override;
	void OnAfterModuleShutdown(IModule* pModule) override;
	void OnModuleNotFound(const ZString& pszModuleName) override;
	void SetOption(const ZString& sOption, const ZString& sValue) override;
	ZString GetOption(const ZString& sOption) override;
	bool GetOptionBool(const ZString& pszName) override;
	IIniFile* GetIniFile() override;
	void Exit() override;
	void GetErrorMailSenderName(char* pBuffer) override;
	virtual void Initialize(const ZString& sDefaultSettings);
	virtual void AddApplicationSpecificOptions(IIniFile* pIniFile);
	virtual bool Startup();
	virtual void Shutdown();

	ZWin32ApplicationStub() = default;
	ZWin32ApplicationStub(int argc, char** argv);
	void LoadOptions(const ZString& sDefaultSettings, int& argc, char** argv);
	void ApplyOptionOverrides(int& argc, char** argv);
	void SetIniFileApplicationOption(const ZString& sOptionName, const ZString& sValue);
	ZString GetProjectPath();
	ZString GetDefaultIniFileName();
};
