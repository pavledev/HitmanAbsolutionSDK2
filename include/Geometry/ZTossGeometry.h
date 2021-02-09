#pragma once

#include "TEntityRef.h"
#include "ZPrimitiveContainerEntity.h"
#include "ZTossConfigurationEntity.h"
#include "ZRenderDynamicMesh.h"

class ZTossGeometry
{
public:
    alignas(16) TEntityRef<ZPrimitiveContainerEntity> m_primitiveContainer;
    TEntityRef<ZPrimitiveContainerEntity> m_primitiveContainerDisc;
    ZTossConfigurationEntity* m_pConfigurator;
    ZRenderDynamicMesh m_Mesh;
    ZRenderDynamicMesh m_MeshDisc;
    int m_cOldArch;
    float4 m_rgOldArch[64];
    bool m_bIsFloor;
    bool m_bLastWasDeadly;
    float m_discAlpha;
    float m_discRadius;
    float m_targetAnimTime;
    float m_targetAnimParam;
    float m_targetArchAnimParam;
    float m_discAnimTime;
    float m_wallBlend;
    float m_floorBlend;
    float m_targetBlend;
    float m_fCamRotation;
    bool m_bTossGeometryAllowedForDifficulty;

    virtual ~ZTossGeometry();
};
