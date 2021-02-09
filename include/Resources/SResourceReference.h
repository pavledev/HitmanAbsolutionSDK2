#pragma once

#include "EResourceReferenceFlags.h"
#include "ZResourceStub.h"
#include "ZRuntimeResourceID.h"

class SResourceReference
{
public:
    EResourceReferenceFlags m_Flags;

    union
    {
        ZResourceStub* m_pStub;
        ZRuntimeResourceID* m_pridMediaResource;
    };

    ZResourcePtr m_pResource;
};
