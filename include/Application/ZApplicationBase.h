#pragma once

#include "IApplication.h"
#include "THashMap.h"
#include "TDefaultHashMapPolicy.h"

class ZApplicationBase : public IApplication
{
public:
    THashMap<ZString, ZString, TDefaultHashMapPolicy<ZString, ZString>> m_debugContextMap;
};
