#pragma once

#include "ZMaterialDescriptorEntity.h"
#include "IEntityFactory.h"
#include "ZRenderMaterialInstance.h"
#include "TSharedPointer.h"
#include "ZEntitySingleton.h"

class ZHM5MaterialDescriptorEntity : public ZMaterialDescriptorEntity
{
public:
    TResourcePtr<IEntityFactory> m_pBulletDecalControllerFactory;
    TResourcePtr<ZRenderMaterialInstance> m_pBulletDecalMaterial;
    unsigned int m_nBulletDecalNumVariationsX;
    unsigned int m_nBulletDecalNumVariationsY;
    SVector2 m_vBulletDecalSize;
    float m_fBulletDecalSizeVariation;
    TResourcePtr<IEntityFactory> m_pSplatDecalControllerFactory;
    TResourcePtr<IEntityFactory> m_pSecondarySplatDecalControllerFactory;
    TResourcePtr<ZRenderMaterialInstance> m_pSplatDecalMaterial;
    unsigned int m_nSplatDecalNumVariationsX;
    unsigned int m_nSplatDecalNumVariationsY;
    SVector2 m_vSplatDecalSize;
    float m_fSplatDecalSizeVariation;
    TResourcePtr<IEntityFactory> m_pBloodPoolDecalControllerFactory;
    TResourcePtr<IEntityFactory> m_pBulletImpactFactory;
    float m_fPenetratableBulletEnergyThreshold;
    TSharedPointer<ZEntitySingleton> m_pBloodPoolDecalController;
    TSharedPointer<ZEntitySingleton> m_pSplatDecalController;
    TSharedPointer<ZEntitySingleton> m_pSecondarySplatDecalController;
    TSharedPointer<ZEntitySingleton> m_pBulletDecalController;
    bool m_bAlwaysPenetrable;
    int m_nBulletImpactEntryIndex;
};
