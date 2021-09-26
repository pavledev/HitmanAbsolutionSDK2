#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"

class IHM5Outfit;
class ZHM5ClothBundleEntity;
class ZRuntimeResourceID;
struct SMatrix43;
template <class T> class TEntityRef;

class __declspec(novtable) IHM5ClothBundlePool : public IComponentInterface
{
public:
	~IHM5ClothBundlePool() override = default;
	virtual void PlaceClothBundle(const TEntityRef<IHM5Outfit> entityRef, const ZRuntimeResourceID& runtimeResourceID, const SMatrix43& matrix43, bool param4, TEntityRef<ZHM5ClothBundleEntity> entityRef5) = 0;
	virtual void RemoveBundle(const ZEntityRef& entityRef) = 0;
	virtual bool GetClothBundle(const ZEntityRef& entityRef, ZRuntimeResourceID& runtimeResourceID) = 0;
	virtual bool GetClothBundle(const ZEntityRef& entityRef, TEntityRef<IHM5Outfit>& entityRef2, ZRuntimeResourceID& runtimeResourceID) = 0;
	virtual ZResourcePtr GetDisguiseMovie(const ZEntityRef& entityRef) = 0;
	virtual void ReleasePool() = 0;

	static void RegisterType();
	IHM5ClothBundlePool() = default;
};
