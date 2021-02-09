#pragma once

#include "ZEntityImpl.h"
#include "ZRuntimeResourceID.h"
#include "TEntityRef.h"
#include "ZTokenIDEntity.h"
#include "EContentKitDLCInfoType.h"

class ZContentKitDLCInfo : public ZEntityImpl
{
public:
    ZRuntimeResourceID m_ridIcon;
    ZString m_sTitleID;
    ZString m_sDescriptionID;
    TEntityRef<ZTokenIDEntity> m_Token;
    EContentKitDLCInfoType m_eType;
    ZString m_sPS3StoreID;
    ZString m_sXboxStoreID;
};
