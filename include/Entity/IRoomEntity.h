#pragma once

#include "IComponentInterface.h"
#include "TArray.h"
#include "ZEntityRef.h"

class IRoomEntity : public IComponentInterface
{
public:
    enum EReasoningGridImportance : __int32
    {
        RGI_NoGrid = 0x0,
        RGI_Low = 0x1,
        RGI_Normal = 0x2,
        RGI_High = 0x3,
        RGI_Extreme = 0x4
    };

    virtual IRoomEntity::EReasoningGridImportance GetGridImportance();
    virtual const TArray<ZEntityRef>* GetClientList();
};
