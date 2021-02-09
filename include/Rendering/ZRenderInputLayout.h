#pragma once

#include "TRenderReferencedCountedImpl.h"
#include "RenderReferencedCountedBaseStub.h"
#include "SRenderInputElementDesc.h"
#include "TArray.h"
#include "SBinding.h"

class ZRenderInputLayout : TRenderReferencedCountedImpl<RenderReferencedCountedBaseStub, 0>
{
    unsigned int m_nNumElements;
    SRenderInputElementDesc m_Elements[16];
    TArray<SBinding> m_aBindings;

    virtual unsigned int GetElements(SRenderInputElementDesc*);
};
