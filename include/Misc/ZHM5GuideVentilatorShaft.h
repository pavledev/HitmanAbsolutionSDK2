#pragma once

#include "ZSpatialEntity.h"
#include "IHM5ActionEntityListener.h"
#include "ZSpline.h"

class ZHM5VentilatorShaftNodeEntity;

class ZHM5GuideVentilatorShaft : public ZSpatialEntity, public IHM5ActionEntityListener
{
public:
    TArray<TEntityRef<ZHM5VentilatorShaftNodeEntity>> m_Nodes;
    TEntityRef<ZHM5Action> m_Action;
    ZSpline* m_pSpline;
};
