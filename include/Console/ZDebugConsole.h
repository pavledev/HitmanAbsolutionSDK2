#pragma once

#include "IComponentInterface.h"
#include "Function.h"
#include "BaseAddresses.h"
#include "ZVariantRef.h"

class ZCyclicBuffer;
class ZDebugConsoleCompletionList;
class ZString;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct STypeID;

class ZDebugConsole : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	char m_szCommandLine[256];
	ZDebugConsoleCompletionList* m_pkCompletions;
	ZCyclicBuffer* m_pkCommands;
	ZCyclicBuffer* m_pkHistory;
	int m_lLine;
	int m_lScrollLine;
	int m_iCurrentCommand;
	int m_lCommandLinePos;
	int m_iHistPos;
	bool m_bHasFocus : 1;
	bool m_bLastCommmandTab : 1;

	static const int CONSOLE_MAX_COMP_SIZE;
	static const int CONSOLE_COMMANDS_HISTORY_SIZE;
	static const int CONSOLE_HISTORY_SIZE;

	~ZDebugConsole() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZDebugConsole() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	static int OnInput(int iKey, int iMask, void* pThis);

	template <typename... Args>
	void AddLine(const char* Format, Args... args)
	{
		Function::Call<ZDebugConsole*, const char*, Args...>(BaseAddresses::hitman5Dll + 0x629CD0, this, Format, args...);
		//reinterpret_cast<void(__cdecl*)(ZDebugConsole*, const char*, Args...)>(BaseAddresses::hitman5Dll + 0x629CD0)(this, Format, args...);
	}

	const char* GetLine(const long lLine) const;
	void ExecuteCommand(const char* szCommand);
	void Command();
	void GetHistory(int iDir);
	void AddHistory(const char* szLine);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnStopEvent(const ZString& sEvent, const ZVariantRef& oldValue);
	void EnableConsole(bool bEnable);
	void SplitToArgs(const char* pszString, unsigned int* pargc, const char*** pargv);
};
