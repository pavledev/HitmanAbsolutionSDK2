#pragma once

#include "IComponentInterface.h"
#include "SRenderPostfilterParameters.h"
#include "ZEntityRef.h"
#include "SRenderPostfilterPerScreenDecalParametersInternal.h"

class IGamePostfilterControllerEntity : public IComponentInterface
{
public:
    virtual void UpdateParameters(SRenderPostfilterParameters*);
    virtual void SetDefaultParameters(const SRenderPostfilterParameters*, float);
    virtual void SetRenderPostfilterControllerEntity(ZEntityRef);
    virtual unsigned int GetGameLerpMask();
    virtual unsigned int UpdateScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal*, unsigned int);
};
