#pragma once

#include "ZResourcePtr.h"
#include "TSharedPointer.h"
#include "ZResourceReader.h"

class ZResourcePending
{
public:
    ZResourcePtr m_pResource;
    TSharedPointer<ZResourceReader> m_pResourceReader;
    int m_nPriority;
    int m_ResourceHandle;
    int m_nDataStartPosition;
};
