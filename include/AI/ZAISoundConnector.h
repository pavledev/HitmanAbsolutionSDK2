#pragma once

#include "ZSpatialEntity.h"
#include "ZAISoundConnectorTarget.h"

class alignas(4) ZAISoundConnector : public ZSpatialEntity
{
public:
    TEntityRef<ZAISoundConnectorTarget> m_pConnectedTo;
    bool m_bRegistered;
    bool m_bTwoWay;
};
