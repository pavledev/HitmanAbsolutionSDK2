#pragma once

#include "IModule.h"
#include "IIniFile.h"
#include "ERunMode.h"

class IApplication
{
public:
    virtual ~IApplication();
    virtual void OnBeforeInitialize();
    virtual void OnAfterInitialize();
    virtual void OnBeforeShutdown();
    virtual void OnAfterShutdown();
    virtual void OnBeforeModuleInitialize(IModule*);
    virtual void OnAfterModuleInitialize(IModule*);
    virtual void OnBeforeModuleShutdown(IModule*);
    virtual void OnAfterModuleShutdown(IModule*);
    virtual void OnModuleNotFound(const ZString*);
    virtual void SetOption(const ZString*, const ZString*);
    virtual ZString* GetOption(ZString* result, const ZString*);
    virtual bool GetOptionBool(const ZString*);
    virtual IIniFile* GetIniFile();
    virtual ERunMode GetRunMode();
    virtual void Exit();
    virtual void SetDebugContextInfo(const ZString*, const ZString*);
    virtual ZString* GetDebugContextInfo(ZString* result, const ZString*);
    virtual bool IsNonInteractiveMode();
    virtual void SendErrorMail(const ZString*, const ZString*);
    virtual void GetErrorMailSenderName(char*);
};
