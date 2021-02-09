#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "IHM5Outfit.h"
#include "ZRuntimeResourceID.h"
#include "SMatrix43.h"
#include "ZHM5ClothBundleEntity.h"

class IHM5ClothBundlePool : public IComponentInterface
{
public:
    virtual void PlaceClothBundle(const TEntityRef<IHM5Outfit>, const ZRuntimeResourceID*, const SMatrix43*, bool, TEntityRef<ZHM5ClothBundleEntity>);
    virtual void RemoveBundle(const ZEntityRef*);
    virtual bool GetClothBundle(const ZEntityRef*, ZRuntimeResourceID*);
    virtual bool GetClothBundle(const ZEntityRef*, TEntityRef<IHM5Outfit>*, ZRuntimeResourceID*);
    virtual ZResourcePtr* GetDisguiseMovie(ZResourcePtr* result, const ZEntityRef*);
    virtual void ReleasePool();
};
