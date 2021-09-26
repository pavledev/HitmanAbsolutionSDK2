#pragma once

#include "SModuleDesc.h"

class IModule;
class ZString;

class ZModuleTable
{
public:
	int m_nLength;
	SModuleDesc m_modules[100];

	static const int MAX_MODULES;

	ZModuleTable() = default;
	int Length();
	IModule* operator[](int nIndex);
	IModule* Find(const ZString& pszName, int nNameLength);
	void Add(const ZString& pszName, IModule* pModule);
	~ZModuleTable() = default;
};
