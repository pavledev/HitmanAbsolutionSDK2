#pragma once

#include "ZMutex.h"
#include "TArray.h"
#include "ZResourcePtr.h"
#include "ZDelegate.h"

class alignas(4) ZResourceLibrarySet
{
public:
    ZMutex m_Mutex;
    ZMutex m_ExecutingCallbackMutex;
    TArray<ZResourcePtr> m_Libraries;
    TArray<ZDelegate<void __cdecl(void)> > m_Callbacks;
    ZResourcePtr m_pHeaderLibrary;
    __int8 m_bReleased : 1;
    __int8 m_bProcessingCallbacks : 1;
};
