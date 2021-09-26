#pragma once

#include "ZString.h"

class __declspec(novtable) ZConfigCommand
{
public:
	enum ECLASSTYPE
	{
		ECLASS_FLOAT = 0,
		ECLASS_INT = 1,
		ECLASS_STRING = 2,
		ECLASS_UNKNOWN = 3
	};

	const char* m_pszName;
	ZConfigCommand* m_pNext;

	virtual ECLASSTYPE GetType();
	virtual void Execute(const unsigned int param1, const char** param2) = 0;
	virtual ~ZConfigCommand() = default;

	ZConfigCommand() = default;
	ZConfigCommand(const char* pszName);
	static ZConfigCommand* First();
	ZConfigCommand* Next() const;
	static const char* GetConfigClassName(ECLASSTYPE classType);
	static void ExecuteCommand(const ZString& pCommandName, const char* argv);
	static ZConfigCommand* GetConfigVariable(const ZString& pszName);
	ZString Name() const;
};
