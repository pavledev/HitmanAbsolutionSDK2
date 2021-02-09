#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "IRenderPostfilterParametersEntity.h"
#include "SRenderPostfilterPerScreenDecalParametersInternal.h"

class IRenderPostfilterControllerEntity : public IComponentInterface
{
public:
    virtual TEntityRef<IRenderPostfilterParametersEntity>* GetCurrentParametersEntity(TEntityRef<IRenderPostfilterParametersEntity>* result);
    virtual TEntityRef<IRenderPostfilterParametersEntity>* GetParametersEntity(TEntityRef<IRenderPostfilterParametersEntity>* result);
    virtual void UpdateParameters(SRenderPostfilterParameters*);
    virtual void LerpParameters(ZEntityRef);
    virtual void ReportParametersChanged();
    virtual void RestartLerp(const float);
    virtual void SetRoomLerp(const bool);
    virtual bool GetRoomLerp();
    virtual float GetLuminance();
    virtual unsigned int GetScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal**);
    virtual void ClearScreenDecals();
};
