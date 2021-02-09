#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"

class ZTossConfigurationEntity : public ZEntityImpl
{
public:
    ZResourcePtr m_materialArch;
    ZResourcePtr m_materialDisc;
};
