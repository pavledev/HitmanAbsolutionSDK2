#pragma once

class ZRayQueryInput;
class ZRayQueryOutput;

class __declspec(novtable) IAsyncRayHandle
{
public:
	virtual bool IsReady() const = 0;
	virtual void Release() = 0;
	virtual const ZRayQueryInput& GetRayCastInput() const = 0;
	virtual const ZRayQueryOutput& GetRayCastOutput() const = 0;
	virtual ~IAsyncRayHandle() = default;

	IAsyncRayHandle() = default;
};
