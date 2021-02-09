#pragma once

#include "IApplication.h"
#include "EComponentManagerState.h"
#include "ZModuleTable.h"
#include "TMap.h"
#include "ZMutex.h"

class ZComponentManager
{
public:
    IApplication* m_pApplication;
    EComponentManagerState m_state;
    ZModuleTable m_modules;
    TMap<ZString, IComponentInterface*>* m_pSingletons;
    ZMutex m_ModuleLoadMutex;
};
