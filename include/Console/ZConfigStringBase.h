#pragma once

#include "ZConfigCommand.h"

class ZConfigStringBase : public ZConfigCommand
{
public:
    char m_szValue[256];
};
