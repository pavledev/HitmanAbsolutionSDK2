#pragma once

#include "ZContentKitEntity.h"

class alignas(4) ZPropKitEntity : public ZContentKitEntity
{
public:
    ZRuntimeResourceID m_sHiResNotebookImage;
    bool m_bIsNewPickup;
};
