#pragma once

#include "IComponentInterface.h"

class ZRenderGraphNode;

class __declspec(novtable) IRenderGraphNodeProducer : public IComponentInterface
{
public:
	~IRenderGraphNodeProducer() override = default;
	virtual ZRenderGraphNode* CreateRenderGraphNode() = 0;

	static void RegisterType();
	IRenderGraphNodeProducer() = default;
};
