#pragma once

#include "ZActionMapTree.h"

class ZInputAction
{
public:
    const char* m_szName;
    ZActionMapTree* m_pkMap;
    int m_iSeq;
};
