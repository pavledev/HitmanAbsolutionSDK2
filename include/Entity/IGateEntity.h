#pragma once

#include "IComponentInterface.h"
#include "SGateDesc.h"
#include "float4.h"

class ZEntityRef;
struct SColorRGB;
template <class T> class TArray;

class __declspec(novtable) IGateEntity : public IComponentInterface
{
public:
	SGateDesc m_Desc;

	~IGateEntity() override = default;
	virtual float4 GetPortalSize() const = 0;
	virtual float4 GetConnectorOffset() const = 0;
	virtual const TArray<ZEntityRef>& GetClientList() const = 0;
	virtual const ZEntityRef& GetRoomLeft() const = 0;
	virtual const ZEntityRef& GetRoomRight() const = 0;
	virtual bool IsReasoning() const = 0;
	virtual bool IsOpen() const = 0;
	virtual const SColorRGB& GetClosedColor() const = 0;
	virtual float GetClipDistance() const = 0;

	static void RegisterType();
	const SGateDesc& GetDesc() const;
	IGateEntity() = default;
};
