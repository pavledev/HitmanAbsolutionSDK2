#pragma once

#include "IModule.h"
#include "TMap.h"
#include "ZComponentInfoBase.h"
#include "ZMutex.h"
#include "TArray.h"

class ZSimpleModuleBase : public IModule
{
public:
    ZString m_pszName;
    TMap<ZString, ZComponentInfoBase*>* m_pComponents;
    TMap<ZString, ZString>* m_pOptionMap;
    bool m_bIsInitializing;
    bool m_bIsShuttingDown;
    ZMutex m_initializationMutex;
    TArray<IComponentInterface*>* m_pSingletonOrder;

    virtual void OnRegisterComponents();
};
