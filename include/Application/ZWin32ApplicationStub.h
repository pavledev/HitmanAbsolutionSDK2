#pragma once

#include "ZApplicationBase.h"
#include "ZComponentManager.h"
#include "ITraceListener.h"
#include "ZTraceListenerWin32.h"
#include "TScopedPointer.h"

class alignas(4) ZWin32ApplicationStub : public ZApplicationBase
{
public:
    ZComponentManager* m_pComponentManager;
    IIniFile* m_pIniFile;
    TMap<ZString, ZString>* m_pOptions;
    ITraceListener* m_pTraceListenerZDebug2;
    bool m_bCleanupCOM;
    bool m_bApplicationIniWasLoaded;
    ZTraceListenerWin32* m_pTraceListenerWin32;
    TScopedPointer<TMap<ZString, ZString> > m_pCommandLineOverrides;
    int m_nArgC;
    char** m_apszArgV;
    void* m_pExceptionHandler;
    bool m_bInitialized;

    void Initialize(const ZString*);
    void AddApplicationSpecificOptions(IIniFile*);
    bool Startup();
    void Shutdown();
};
