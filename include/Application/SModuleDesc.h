#pragma once

#include "ZString.h"

class IModule;

struct SModuleDesc
{
	ZString m_pszName;
	IModule* m_pModule;

	SModuleDesc() = default;
	~SModuleDesc() = default;
};
