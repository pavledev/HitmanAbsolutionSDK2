#pragma once

#include "TResourcePtr.h"
#include "SWaveBankFXData.h"

class IWaveBankData
{
public:
    virtual const TResourcePtr<SWaveBankFXData>* GetFXResource();
    virtual ZRuntimeResourceID* GetRuntimeResourceID(ZRuntimeResourceID* result);
    virtual bool IsNotDucking();
    virtual ~IWaveBankData();
};
