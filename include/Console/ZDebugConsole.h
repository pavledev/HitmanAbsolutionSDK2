#pragma once

#include "IComponentInterface.h"
#include "ZDebugConsoleCompletionList.h"
#include "ZCyclicBuffer.h"
#include "SGameUpdateEvent.h"
#include "SComponentMapEntry.h"

class alignas(4) ZDebugConsole : public IComponentInterface
{
public:
    char m_szCommandLine[256];
    ZDebugConsoleCompletionList* m_pkCompletions;
    ZCyclicBuffer* m_pkCommands;
    ZCyclicBuffer* m_pkHistory;
    int m_lLine;
    int m_lScrollLine;
    int m_iCurrentCommand;
    int m_lCommandLinePos;
    int m_iHistPos;
    __int8 m_bHasFocus : 1;
    __int8 m_bLastCommmandTab : 1;

    virtual ZVariantRef* GetVariantRef(ZVariantRef * result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID * iid);

    void OnStopEvent(ZString* sEvent, ZVariantRef* oldValue);
    const char* GetLine(int lLine);
    void SplitToArgs(char* pszString, unsigned int* pargc, char*** pargv);
    void AddLine(char* Format);
    ZDebugConsole();
    void FrameUpdate(SGameUpdateEvent* updateEvent);
    void Command();
    void ExecuteCommand(const char* szCommand);
    static int OnInput(int iKey, int iMask, void* pThis);
    const SComponentMapEntry* GetComponentInterfacesInternal();
    void GetHistory(int iDir);
    void AddHistory(char* szLine);
    void EnableConsole(bool bEnable);
};
