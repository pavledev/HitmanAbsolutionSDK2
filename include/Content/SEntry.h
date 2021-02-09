#pragma once

#include "TSet.h"
#include "TEntityRef.h"
#include "ZContentKitEntity.h"
#include "ZContentKitMenuSetup.h"

class SEntry
{
public:
    TSet<TEntityRef<ZContentKitEntity>> m_rKits;
    TEntityRef<ZContentKitMenuSetup> m_rMenu;
    STokenID m_CachedToken;
};
