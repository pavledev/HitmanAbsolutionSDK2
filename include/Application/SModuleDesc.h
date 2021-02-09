#pragma once

#include "ZString.h"
#include "IModule.h"

class SModuleDesc
{
public:
    ZString m_pszName;
    IModule* m_pModule;
};
