#pragma once

#include "ZSpatialEntity.h"
#include "TResourcePtr.h"
#include "IEntityFactory.h"
#include "IHM5Outfit.h"

class ZHM5ClothBundleEntity : public ZSpatialEntity
{
public:
    TResourcePtr<IEntityFactory> m_pClothBundleSpatialEntityFactory;
    ZRuntimeResourceID m_ridClothBundleSpatialEntity;
    TEntityRef<IHM5Outfit> m_pOutfitReference;
    ZRuntimeResourceID m_ridDisguisePrimResource;
    float m_fButtonHeightOffset;
    TEntityRef<ZSpatialEntity> m_editModeEntity;
};
