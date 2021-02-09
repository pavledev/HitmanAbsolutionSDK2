#pragma once

#include "IComponentInterface.h"
#include "SGateDesc.h"
#include "float4.h"
#include "TArray.h"
#include "ZEntityRef.h"
#include "SColorRGB.h"

class IGateEntity : public IComponentInterface
{
public:
    SGateDesc m_Desc;

    virtual float4* GetPortalSize(float4* result);
    virtual float4* GetConnectorOffset(float4* result);
    virtual const TArray<ZEntityRef>* GetClientList();
    virtual const ZEntityRef* GetRoomLeft();
    virtual const ZEntityRef* GetRoomRight();
    virtual bool IsReasoning();
    virtual bool IsOpen();
    virtual const SColorRGB* GetClosedColor();
    virtual float GetClipDistance();
};
