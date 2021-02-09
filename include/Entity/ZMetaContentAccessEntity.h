#pragma once

#include "ZEntityImpl.h"
#include "EMetaContent.h"
#include "TEntityRef.h"
#include "ZTokenIDEntity.h"

class ZMetaContentAccessEntity : public ZEntityImpl
{
public:
    EMetaContent m_ContentType;
    TArray<TEntityRef<ZTokenIDEntity>> m_aUnlockTokens;
};
