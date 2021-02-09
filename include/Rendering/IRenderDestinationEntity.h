#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "SRenderViewport.h"
#include "IRenderDestination.h"

class IRenderDestinationEntity : public IComponentInterface
{
public:
    enum ERenderDestinationType : __int32
    {
        E_SCREEN = 0x0,
        E_TEXTURE = 0x1
    };

    virtual const ZEntityRef* GetSource();
    virtual const SRenderViewport* GetDestinationViewport();
    virtual IRenderDestination* GetRenderDestination();
    virtual bool GetEditorExclusive();
    virtual void SetSource(const ZEntityRef*);
    virtual void SetEditorExclusive(bool);
    virtual ERenderDestinationType GetType();
};
