#pragma once

#include "TSharedPointer.h"
#include "ZResourceReader.h"
#include "MR.h"

class ZRigResource
{
public:
    TSharedPointer<ZResourceReader> m_pReader;
    MR::Rig* m_pRig;
    ZRuntimeResourceID m_ridResource;
};
