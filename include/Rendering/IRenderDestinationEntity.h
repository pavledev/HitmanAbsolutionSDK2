#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "SRenderViewport.h"
#include "IRenderDestination.h"

class __declspec(novtable) IRenderDestinationEntity : public IComponentInterface
{
public:
	enum ERenderDestinationType
	{
		E_SCREEN = 0,
		E_TEXTURE = 1
	};

	~IRenderDestinationEntity() override = default;
	virtual const ZEntityRef& GetSource() const = 0;
	virtual const SRenderViewport& GetDestinationViewport() const = 0;
	virtual IRenderDestination* GetRenderDestination() const = 0;
	virtual bool GetEditorExclusive() const = 0;
	virtual void SetSource(const ZEntityRef& entityRef) = 0;
	virtual void SetEditorExclusive(bool param1) = 0;
	virtual ERenderDestinationType GetType() = 0;

	IRenderDestinationEntity() = default;
};
