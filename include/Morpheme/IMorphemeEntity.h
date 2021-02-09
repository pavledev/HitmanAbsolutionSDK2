#pragma once

#include "IComponentInterface.h"
#include "ZMorphemeNetworkInstance.h"
#include "ZEvent0.h"
#include "IVariationInstance.h"
#include "ZMorphemePostProcessorInfo.h"

class IMorphemeEntity : public IComponentInterface
{
public:
    virtual ZMorphemeNetworkInstance* GetNetwork();
    virtual int GetNetworkInstanceID();
    virtual bool IsInitializationDone();
    virtual ZEvent0* GetInitializationDoneEvent();
    virtual ZEvent0* GetUnInitializationDoneEvent();
    virtual void SetInstantiateNetwork(bool);
    virtual const ZEntityRef* GetVariationResource();
    virtual void SetVariationResourceEntity(ZEntityRef);
    virtual int CreateNetworkInstance(IVariationInstance*);
    virtual void WaitForNetworkUpdate();
    virtual void SignalBonesChangedEvent();
    virtual void SignalBonesChangedEventDirect();
    virtual void CalcRootNodeMovement(const SMatrix*, SMatrix*);
    virtual float GetMoveDistance();
    virtual void RegisterPostProcessor(const ZDelegate<void __cdecl(ZMorphemePostProcessorInfo&)>*);
    virtual void UnregisterPostProcessor(const ZDelegate<void __cdecl(ZMorphemePostProcessorInfo&)>*);
    virtual SMatrix* ExtractBoneMatPosFromAnimAtTimeFraction(SMatrix* result, const unsigned int, int, float);
    virtual SMatrix* ExtractBoneMatPosFromAnimAtTimeFractionSimple(SMatrix* result, const unsigned int, int, float, bool);
    virtual bool IsBoneAnimated(const unsigned int, int);
};
