#pragma once

#include "ZBoundedEntity.h"
#include "SVector3.h"
#include "ZResourcePtr.h"
#include "POIType.h"

class ZPointOfInterestEntity : public ZBoundedEntity
{
public:
    SVector3 m_vClipDebugVerts[10];
    SVector3 m_vClipDebugVertsCenter;
    int m_nClipDebugVertsCount;
    SVector3 m_vPortalSize;
    bool m_bActive;
    bool m_bBillboard;
    float m_fMaxDistance;
    bool m_bGlobal;
    ZResourcePtr m_pHelper;
    POIType m_eType;

    virtual TEntityRef<ZSpatialEntity>* GetSpatial(TEntityRef<ZSpatialEntity>* result);
    virtual bool GetIsActive();
    virtual float GetMaxDistance();
    virtual float GetDuration();
    virtual float GetQuarentineDuration();
    virtual float GetLocalDuration();
    virtual float GetViewConeAngle();
    virtual bool GetIsGlobal();
    virtual POIType GetType();
};
