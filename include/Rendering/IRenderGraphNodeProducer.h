#pragma once

#include "IComponentInterface.h"
#include "ZRenderGraphNode.h"

class IRenderGraphNodeProducer : public IComponentInterface
{
public:
    virtual ZRenderGraphNode* CreateRenderGraphNode();
};
