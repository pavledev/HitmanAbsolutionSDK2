#pragma once

#include "ZEntityImpl.h"
#include "STokenID.h"

class ZTokenIDEntity : public ZEntityImpl
{
public:
    ZString m_sName;
    STokenID m_TokenIDCached;
};
