#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"
#include "ZEntityRef.h"

class IVariationInstance;
class ZEvent0;
class ZMorphemeNetworkInstance;
class ZMorphemePostProcessorInfo;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) IMorphemeEntity : public IComponentInterface
{
public:
	~IMorphemeEntity() override = default;
	virtual ZMorphemeNetworkInstance* GetNetwork() const = 0;
	virtual int GetNetworkInstanceID() const = 0;
	virtual bool IsInitializationDone() const = 0;
	virtual ZEvent0& GetInitializationDoneEvent() = 0;
	virtual ZEvent0& GetUnInitializationDoneEvent() = 0;
	virtual void SetInstantiateNetwork(bool param1) = 0;
	virtual const ZEntityRef& GetVariationResource() const = 0;
	virtual void SetVariationResourceEntity(ZEntityRef entityRef) = 0;
	virtual int CreateNetworkInstance(IVariationInstance* variationInstance) const = 0;
	virtual void WaitForNetworkUpdate() = 0;
	virtual void SignalBonesChangedEvent() = 0;
	virtual void SignalBonesChangedEventDirect() = 0;
	virtual void CalcRootNodeMovement(const SMatrix& matrix, SMatrix& matrix2) = 0;
	virtual float GetMoveDistance() const = 0;
	virtual void RegisterPostProcessor(const ZDelegate<void __cdecl(ZMorphemePostProcessorInfo&)>& delegate) = 0;
	virtual void UnregisterPostProcessor(const ZDelegate<void __cdecl(ZMorphemePostProcessorInfo&)>& delegate) = 0;
	virtual SMatrix ExtractBoneMatPosFromAnimAtTimeFraction(const unsigned int param1, int param2, float param3) = 0;
	virtual SMatrix ExtractBoneMatPosFromAnimAtTimeFractionSimple(const unsigned int param1, int param2, float param3, bool param4) = 0;
	virtual bool IsBoneAnimated(const unsigned int param1, int param2) = 0;

	static void RegisterType();
	IMorphemeEntity() = default;
};
