#pragma once

#include "GStat.h"
#include "StatInterface.h"

class GStatInfo : public GStat
{
public:
    unsigned int StatId;
    StatInterface* pInterface;
    GStat* pData;
};
