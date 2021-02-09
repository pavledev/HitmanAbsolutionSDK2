#pragma once

#include "ZSpatialEntity.h"
#include "SVector2.h"
#include "ZResourcePtr.h"
#include "ZHM5GuideVentilatorShaft.h"

enum EType : __int32
{
    TypeNode = 0x0,
    TypeEventHole = 0x1,
    TypeEntranceHigh = 0x2,
    TypeEntranceLow = 0x3
};

class ZHM5VentilatorShaftNodeEntity : public ZSpatialEntity
{
public:
    SVector2 m_vArmMovementHorizontal;
    SVector2 m_vArmMovementVertical;
    ZResourcePtr m_pHelper;
    TEntityRef<ZHM5GuideVentilatorShaft> m_rMasterGuide;
    unsigned int m_iSplineIdx;

    virtual void ResetNode();
    virtual EType GetType();
    virtual void GeomTransformChangeCallback(const ZEntityRef*, const SMatrix43*);
};
