#pragma once

#include "ZSharedPointerTarget.h"
#include "ZResourceStub.h"
#include "TSharedPointer.h"
#include "ZResourceDataBuffer.h"

class ZResourceReader : public ZSharedPointerTarget
{
public:
    ZResourceStub* m_pStub;
    TSharedPointer<ZResourceDataBuffer> m_pResourceData;
    unsigned int m_nResourceDataSize;
};
